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

        double dot(vec2 v) {
            return (x * v.x + y * v.y);
        };

        double cross(vec2 v) {
            return (x * v.y + y * v.x);
        }

        vec2 deltaTimeAdd(vec2 v) {
            //placeholder
            return v;
        };
        
};

class rigidbody {
    
};

//function to get the closest point and the distance to that point from a position to a line segment
vec2 closestPointToLineSegment(vec2 p1, vec2 p2, vec2 q) {
    vec2 u = p2.sub(p1);
    vec2 v = q.sub(p1);

    double dotProduct = u.dot(v);
	double uLengthSquared = u.dot(u);
	double t = dotProduct / uLengthSquared;

    if (t < 0) {
        return p1;
    } else if (t > 1) {
        return p2;
    } else {
        return p1.add(u.mul(t));
    }
};

void pause() {
    int x;
    std::cin >> x;
};