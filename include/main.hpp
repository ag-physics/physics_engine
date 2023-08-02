#pragma once

class vec2{
    public:
        double x;
        double y;

        vec2(double tempX, double tempY);

        vec2 add(vec2 v);

        vec2 sub(vec2 v);

        vec2 mul(double s);

        vec2 pow(int e);

        double mag();

        vec2 norm();

        vec2 dot(vec2 v);

        vec2 cross(vec2 v);

        vec2 deltaTimeAdd(vec2 v);

};

vec2 closestPointToLineSegment(vec2 p1, vec2 p2, vec2 q);

void simulation();

void pause();