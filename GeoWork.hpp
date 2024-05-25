#pragma once
#include <string>


class Coordinate final{
    float m_x = 0;
    float m_y = 0;

public:
    Coordinate(float x, float y);
    // void getXY(float& x, float& y);
    // void setXY(float x, float y);
    float getX() const;
    float getY() const;
    void setX(float x);
    void setY(float y);
};

class Location final{
    std::string m_name = "";
    std::pair<Coordinate, Coordinate> m_coordinates;

public:
    Location(const std::string& name, const Coordinate& point1, const Coordinate& point2);
    bool point_in_location(const Coordinate& point);
    std::string get_name() const;
    std::pair<Coordinate, Coordinate> get_coordinates() const;
};