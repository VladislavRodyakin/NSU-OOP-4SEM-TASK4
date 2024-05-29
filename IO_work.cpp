#include "IO_work.hpp"
#include <stdexcept>
#include <algorithm>

std::vector<UserLog> IOWork::read_user(std::istream& in_stream)
{
    std::vector<UserLog> users;
    UserLog tmp;
    size_t ts;
    int user_id;
    float user_x, user_y;
    while (in_stream >> ts >> user_id >> user_x >> user_y)
    {
        if (user_id < 0){
            throw std::invalid_argument("User ID must be positive");
        }
        if (ts<0){
            throw std::invalid_argument("Time stamp must be positive");
        }

        auto user_it = std::find_if(users.begin(), users.end(), [&](UserLog& user) { return user.get_user_id() == user_id; });
        if (user_it == users.end()){
            tmp = UserLog(user_id);
            tmp.add_point(ts, Coordinate(user_x, user_y));
            users.push_back(tmp);
        }
        else {
            user_it->add_point(ts, Coordinate(user_x, user_y));
        }
    }
    return users;
}


LocationsMap IOWork::read_map(std::istream& in_stream)
{
    LocationsMap map;
    std::string name;
    float x1, y1, x2, y2;
    while (in_stream >> name >> x1 >> y1 >> x2 >> y2)
    {
        map.add_location(name, Coordinate(x1, y1), Coordinate(x2, y2));
    }
    return map;
}


void IOWork::write_track(int user_id, std::map<size_t, std::vector<std::string>> user_track)
{
    std::ofstream out_stream("user_"+std::to_string(user_id)+"_track.txt");
    out_stream << user_id << std::endl;
    
    for (auto& track : user_track)
    {
        out_stream << track.first << " ";
        for (auto& place : track.second)
        {
            out_stream << place << " ";
        }
        out_stream << std::endl;
    }
    out_stream.close();
}


void IOWork::write_places(int user_id, std::map<size_t, std::vector<std::string>> user_track)
{
    // std::ofstream out_stream("user_"+std::to_string(user_id)+"_track.txt"); // when we need to output into the same file
    
    std::ofstream out_stream("user_"+std::to_string(user_id)+"_places.txt");
    out_stream << user_id << std::endl;
    
    for (auto& track : user_track)
    {
        for (auto& place : track.second)
        {
            if (place == track.second.back()){
                out_stream << place;
            }else{
                out_stream << place << ", ";
            }
        }
        if (track.first != user_track.rbegin()->first){
            out_stream << " - ";
        }
    }
    out_stream << std::endl;
    out_stream.close();
}


std::map<size_t, std::vector<std::string>> TrackCollector::getUserTrack(const LocationsMap& map, const UserLog& user, const int& user_id)
{
    std::map<size_t, std::vector<std::string>> user_track;
    for (auto& track : user.get_track())
    {
        const auto places = map.which_places(track.second);
        std::for_each(places.begin(), places.end(),
                        [&](const Location& place) { user_track[track.first].push_back(place.get_name()); });
    }
    return user_track;
}