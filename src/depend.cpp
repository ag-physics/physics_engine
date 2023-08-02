#include <iostream>
#include <cmath>

class vec2 {
    public:
        double x;
        double y;

        //constructor
        vec2(double tempX, double tempY) {
            x = tempX;
            y = tempY;
        };

        vec2 add(vec2 v) {
            v.x += x;
            v.y += y;
            return v;
        };

        vec2 sub(vec2 v) {
            v.x -= x;
            v.y -= y;
            return v;
        };

        vec2 mul(double s) {
            vec2 v(x, y);
            v.x *= s;
            v.y *= s;
            return v;
        };

        vec2 pow(int e) {
            vec2 v(x, y);
            v.x = std::pow(v.x, e);
            v.y = std::pow(v.y, e);
            return v;
        };

        double mag() {
            vec2 v(x, y);
            v.x = std::pow(v.x, 2);
            v.y = std::pow(v.y, 2);
            return std::sqrt(v.x + v.y);
        };

        vec2 norm() {
            vec2 v(x, y);
            if(mag() == 0) {
                v.x = 0;
                v.y = 0;
                return v;
            } else {
                v.x = v.x/mag();
                v.y = v.y/mag();
                return v;
            };
        };

        vec2 dot(vec2 v) {
            v.x *= x;
            v.y *= y;
            return v;
        };

        vec2 cross(vec2 v) {
            v.x *= y;
            v.y *= x;
            return v;
        }

        vec2 deltaTimeAdd(vec2 v) {
            //placeholder
            return v;
        };
        
};

void pause() {
    int x;
    std::cin >> x;
};