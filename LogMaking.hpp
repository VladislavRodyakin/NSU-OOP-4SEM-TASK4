#include <vector>
#include <map>
#include <string>

class UserLog{
    int user_id;
    std::map<int, std::pair<float,float>> track;
};

class Map{
    std::map<std::string, std::pair<std::pair<float,float>, std::pair<float,float>>> map;
    public:
    std::vector<std::string> which_places(std::pair<float,float> point);
};