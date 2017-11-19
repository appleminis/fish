#ifndef OBSTACLE_H
#define OBSTACLE_H

#include <vect.h>

class obstacle
{
public:

    vect p;
    float r;

    obstacle();
    obstacle(vect pp, float rr);
    ~obstacle();
};

#endif // OBSTACLE_H
