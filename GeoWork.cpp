#include "GeoWork.hpp"

Coordinate::Coordinate(): m_x(0), m_y(0){}

Coordinate::Coordinate(float x, float y): m_x(x), m_y(y){}

Coordinate::Coordinate(const Coordinate& other): m_x(other.m_x), m_y(other.m_y){}

Coordinate& Coordinate::operator=(const Coordinate& other) {
    if (this != &other) {
        m_x = other.m_x;
        m_y = other.m_y;
    }
    return *this;
}

float Coordinate::getX() const { return m_x; }

float Coordinate::getY() const { return m_y; }

void Coordinate::setX(float x){ m_x = x; }

void Coordinate::setY(float y){ m_y = y; }


Location::Location(const std::string& name, const Coordinate& point1, const Coordinate& point2):
    m_name(name), m_coordinates({point1, point2}){}


bool Location::point_in_location(const Coordinate& point) const {
    return point.getX() >= m_coordinates.first.getX() && point.getX() <= m_coordinates.second.getX() 
        && point.getY() >= m_coordinates.first.getY() && point.getY() <= m_coordinates.second.getY() ||
           point.getX() <= m_coordinates.first.getX() && point.getX() >= m_coordinates.second.getX() 
        && point.getY() <= m_coordinates.first.getY() && point.getY() >= m_coordinates.second.getY();
}

std::string Location::get_name() const { return m_name; }

std::pair<Coordinate, Coordinate> Location::get_coordinates() const { return m_coordinates; }