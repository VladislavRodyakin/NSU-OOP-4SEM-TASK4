#pragma once
#include <vector>
#include <map>
#include <string>
#include <iostream>
#include <sstream>
#include <fstream>
#include "LogMaking.hpp"

class IOWork{
public:
    std::vector<UserLog> read_user(std::istream& in_stream);
    Map read_map(std::istream& in_stream);
    void write_track(int user_id, std::map<size_t, std::vector<std::string>> user_track); // answer to question 1 //, ostream& out_stream = cout);
    void write_places(int user_id, std::map<size_t, std::vector<std::string>> user_track); // answer to question 2
};

class TrackCollector{
public:
    std::map<size_t, std::vector<std::string>> getUserTrack(const Map& map, const UserLog& user, const int& user_id);

};//might not need a class