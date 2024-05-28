#include "LogMaking.hpp"
#include <stdexcept>

UserLog::UserLog() : m_user_id(0) {}

UserLog::UserLog(int user_id) {
    if (user_id < 0) {
        throw std::invalid_argument("User ID must be positive");
    }
    m_user_id = user_id;
}

UserLog::UserLog(const UserLog& other) : m_user_id(other.m_user_id), m_track(other.m_track) {}

void UserLog::add_point(size_t time, const Coordinate& point){
    if (time < 0){
        throw std::invalid_argument("Time stamp must be positive");
    }
    m_track[time] = point;
}

int UserLog::get_user_id() const { return m_user_id; }

std::map<size_t, Coordinate> UserLog::get_track() const { return m_track; }


Map::Map() {}

Map::Map(std::vector<Location> locations) : m_locations(locations) {}

void Map::add_location(const Location& location) { m_locations.push_back(location); }

void Map::add_location(const std::vector<Location>& locations) {
    m_locations.insert(m_locations.end(), locations.begin(), locations.end());
}

void Map::add_location(const std::string& name, const Coordinate& point1, const Coordinate& point2) {
    m_locations.emplace_back(name, point1, point2);
}

std::vector<Location> Map::which_places(const Coordinate& point) const {
    std::vector<Location> places;
    for (const auto& location : m_locations) {
        if (location.point_in_location(point)) {
            places.push_back(location);
        }
    }
    return places;
}