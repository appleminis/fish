#ifndef poissonsson
#define poissonsson

#include <GL/gl.h>
#include <GL/glu.h>
#include "vect.h"

#define L 16

class poisson
{
public:
	poisson();
	poisson(vect _p, vect _v, float s, float ve=10);
	~poisson(void);

	vect p,v;
	float sz,vs;
	vect apos[L];
    int ai;

	void aff ();
	void anime (float tp);
	bool voisin (vect w);
};

#endif
