#pragma once

#include <iostream>

template <typename T>
class Point {
protected:
    T _x;
    T _y;
public:
    Point() : _x(0), _y(0) {}
    Point(T x_coord, T y_coord) : _x(x_coord), _y(y_coord) {}
    Point(const Point& other) : _x(other.getX()), _y(other.getY()) {}

    T getX() const { return _x; }//const после функции для того чтобы он не менял ничего, const перед для того чтобы возвращал константу
    T getY() const { return _y; }

    void setX(T newX) { _x = newX; }
    void setY(T newY) { _y = newY; }

    T get_distance(const Point& other) const {
        T a_x = other.getX() - _x;
        T a_y = other.getY() - _y;
        return sqrt(a_x * a_x + a_y * a_y);
    }
};

template<typename T>
class Point3D : public Point<T> {
protected:
    T _z;
public:
    Point3D() : Point<T>(), _z(0) {}
    Point3D(T x_coord, T y_coord, T z_coord) : Point<T>(x_coord, y_coord), _z(z_coord) {}
    Point3D(const Point3D& other) : Point<T>(other.getX(), other.getY()), _z(other.getZ()) {}

    T getZ() const { return _z; }

    void setZ(T newZ) { _z = newZ; }

    T get_distance3D(const Point3D& other) const {
        T a_x = other.getX() - this->_x;
        T a_y = other.getY() - this->_y;
        T a_z = other.getZ() - this->_z;
        return sqrt(a_x * a_x + a_y * a_y + a_z * a_z);
    }
};