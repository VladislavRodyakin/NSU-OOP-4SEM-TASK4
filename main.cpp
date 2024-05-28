#include <iostream>
#include <sstream>
#include "IO_work.hpp"
#include "GeoWork.hpp"
#include "LogMaking.hpp"

int main(){
    std::cout<<"Hello, I work!"<<std::endl;
    try{

    std::istringstream user_inp{
        "123 1 15.3 8.5\n"
        "123 2 15.3 8.5\n"
        "143 1 1.3 7\n"
        "149 2 28 7\n"
        "180 2 14 10\n"
        "249 2 20 2.9\n"
    };
    std::istringstream map_inp{
        "hGlobal 0 0 20 20\n"
        "Local_1 14 8 16 9\n"
        "Local_2 0 0 9 9\n"
        "Away 25 0 40 9\n"
    };

    IOWork io_work;
    TrackCollector track_collector;

    std::vector<UserLog> usersLogs = io_work.read_user(user_inp);
    Map map = io_work.read_map(map_inp);

    for (auto& user : usersLogs)
    {
        std::map<size_t, std::vector<std::string>> user_track = track_collector.getUserTrack(map, user, user.get_user_id());
        io_work.write_track(user.get_user_id(), user_track);
        io_work.write_places(user.get_user_id(), user_track);
    }


    }
    catch(const std::exception& e){
        std::cout << std::endl <<e.what() << std::endl;
    }
    return 0;
}