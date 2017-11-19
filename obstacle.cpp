#include "obstacle.h"

obstacle::obstacle()
{
    p=vect(0,0,0);
    r=1;
}

obstacle::obstacle(vect pp, float rr)
{
    p=pp;
    r=rr;
}

obstacle::~obstacle()
{

}

