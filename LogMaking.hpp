#pragma once
#include <vector>
#include <map>
#include <string>
#include "GeoWork.hpp"


class UserLog final{
    int m_user_id = 0;
    std::map<size_t, Coordinate> m_track = {};

public:
    UserLog();
    UserLog(int user_id);
    UserLog(const UserLog& other);
    void add_point(size_t time, const Coordinate& point);

    int get_user_id() const;
    std::map<size_t, Coordinate> get_track() const;
};

class LocationsMap final{
    std::vector<Location> m_locations = {};

public:
    LocationsMap();
    LocationsMap(std::vector<Location> locations);
    void add_location(const Location& location);
    void add_location(const std::string& name, const Coordinate& point1, const Coordinate& point2);
    void add_locations(const std::vector<Location>& locations);
    //redo as r-tree, log(loc_num) comlexity
    std::vector<Location> which_places(const Coordinate& point) const;
};