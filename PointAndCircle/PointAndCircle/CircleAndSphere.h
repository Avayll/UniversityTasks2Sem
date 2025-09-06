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
    Circle(Circle& other) : Point<T>(other.getX(), other.getY()), _radius(other.getRadius()) {}

    T getRadius() const { return _radius; }
    Point<T> getCenter() const { return Point<T>(this->_x, this->_y); }

    void setRadius(T newRadius) { _radius = newRadius; }
    void setCenter(T x, T y) {
        this->_x = x;
        this->_y = y;
    }
    void setCenter(const Point<T>& center) {
        this->_x = center.getX();
        this->_y = center.getY();
    }

    states_circle is_intersects(const Circle& other) const {
        T distance = this->get_distance(other.getCenter());
        if (distance < (this->_radius + other.getRadius())) {
            return 2;
        }
        else if (distance = (this->_radius + other.getRadius())) {
            return 1;
        }
        else if (distance > (this->_radius + other.getRadius())) {
            return 3;
        }
    }
};