#pragma once

#include "Point.h"

enum states_circle {
    touches = 1, in_it = 2, no_touch = 3
};

template <typename T>
class Circle : public Point<T> {
private:
    T _radius;

public:
    Circle() : Point<T>(), _radius(0) {}
    Circle(T x, T y, T radius) : Point<T>(x, y), _radius(radius) {}
    Circle(Point<T>& center, T radius) : Point<T>(center), _radius(radius) {}
    Circle(const Circle& other) : Point<T>(other.getX(), other.getY()), _radius(other.getRadius()) {}

    T getRadius() const { return _radius; }
    Point<T> getCenter() const { return Point<T>(this->_x, this->_y); }

    void setRadius(T newRadius) { this->_radius = newRadius; }
    void setCenter(T x, T y) {
        this->_x = x;
        this->_y = y;
    }
    void setCenter(const Point<T>& center) {
        this->_x = center.getX();
        this->_y = center.getY();
    }

    int is_intersects(const Circle& other) const {
        T distance = this->get_distance(other.getCenter());
        if (distance < (this->_radius + other.getRadius())) {
            return 2;
        }
        else if (distance == (this->_radius + other.getRadius())) {
            return 1;
        }
        else if (distance > (this->_radius + other.getRadius())) {
            return 3;
        }
    }
};

template <typename T>
class Sphere : public Point3D<T> {
private:
    T _radius;

public:
    Sphere() : Point3D<T>(), _radius(0) {}
    Sphere(T x, T y, T z, T radius) : Point3D<T>(x, y, z), _radius(radius) {}
    Sphere(const Point3D<T>& center, T radius) : Point3D<T>(center), _radius(radius) {}
    Sphere(const Sphere& other) : Point3D<T>(other.getX(), other.getY(), other.getZ()), _radius(other.getRadius()) {}

    T getRadius() const { return _radius; }
    Point3D<T> getCenter() const { return Point3D<T>(this->_x, this->_y, this->_z); }

    void setRadius(T newRadius) { this->_radius = newRadius; }
    void setCenter(T x, T y, T z) {
        this->_x = x;
        this->_y = y;
        this->_z = z;
    }
    void setCenter(const Point3D<T>& center) {
        this->_x = center.getX();
        this->_y = center.getY();
        this->_z = center.getZ();
    }
    int is_intersects(const Sphere& other) const {
        T distance = this->get_distance3D(other.getCenter());
        T sum_radii = _radius + other.getRadius();

        if (distance == sum_radii) {
            return 1;
        }
        else if (distance < sum_radii) {
            return 2;
        }
        else if (distance > sum_radii) {
            return 3; 
        }
    }
};

//test for new branch