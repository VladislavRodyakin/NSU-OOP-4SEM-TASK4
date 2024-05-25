#pragma once
#include <vector>
#include <map>
#include <string>
#include "GeoWork.hpp"


class UserLog final{
    int m_user_id = 0;
    std::map<int, Coordinate> m_track = {};

public:
    UserLog();
    UserLog(int user_id);
    UserLog(const UserLog& other);
    void add_point(int time, const Coordinate& point);

    int get_user_id() const;
    std::map<int, Coordinate> get_track() const;
};

class Map final{
    std::vector<Location> m_locations = {};

public:
    Map();
    Map(std::vector<Location> locations);
    void add_location(const Location& location);
    void add_location(const std::vector<Location>& locations); // is this a good practice?
    void add_location(const std::string& name, const Coordinate& point1, const Coordinate& point2); // is this a good practice?
    //redo as r-tree, log(loc_num) comlexity
    std::vector<Location> which_places(const Coordinate& point);
};