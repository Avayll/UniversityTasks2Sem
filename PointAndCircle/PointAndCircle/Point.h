#pragma once

#include <iostream>

template <typename T>
class Point {
protected:
    T _x;
    T _y;
public:
    Point() : x(0), y(0) {}
    Point(T x_coord, T y_coord) : _x(x_coord), _y(y_coord) {}
    Point(const Point& other) : _x(other.getX()), _y(other.getY()) {}

    T getX() const { return _x; }//const ����� ������� ��� ���� ����� �� �� ����� ������, const ����� ��� ���� ����� ��������� ���������
    T getY() const { return _y; }

    void setX(T newX) { _x = newX; }
    void setY(T newY) { _y = newY; }

    T get_distance(Point& other) const {
        T a_x = other.getX() - _x;
        T a_y = other.getY() - _y;
        return sqrt(a_x * a_x + a_y * a_y);
    }
};

template<typename T>
class Point3D : public Point<T> {
private:
    T _x, _y, _z;
public:
    Point3D() : _x(0), _y(0), _z(0) {}
    Point3D(T x_coord, T y_coord, T z_coord) : _x(x_coord), _y(y_coord), _z(z_coord) {}
    Point3D(const Point3D& other) : _x(other.getX()), _y(other.getY()), _z(other.getZ()) {}

    T getZ() const { return _z; }

    void setZ(T newZ) { _z = newZ; }

    T get_distance3D(Point3D& other) const {
        T a_x = other.getX() - _x;
        T a_y = other.getY() - _y;
        T a_z = other.getZ() - _z;
        return sqrt(a_x * a_x + a_y * a_y + a_z*a_z);
    }
};