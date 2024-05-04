#include <map>
#include <iostream>
#include <string>
#include <vector>
using namespace std;
class IOWork{
    public:
    vector<UserLog> read_user(istream& in_stream);
    Map read_map(istream& in_stream);
    void write_track(int user_id, map<int, vector<string>>); // answer to question 1 //, ostream& out_stream = cout);
    void write_places(int user_id, map<int, vector<string>>); // answer to question 2
};

class UserLog{
    int user_id;
    map<int, pair<float,float>> track;
};

class Map{
    map<string, pair<pair<float,float>, pair<float,float>>> map;
    public:
    vector<string> which_places(pair<float,float> point);
};

class TrackCollector{
    map<int, vector<string>> getUserTrack(UserLog& user, int& user_id);

};//might not need a class

