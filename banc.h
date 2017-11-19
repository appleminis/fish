#ifndef killbill
#define killbill

#include <GL/gl.h>
#include <GL/glu.h>
#include "vect.h"
#include "poisson.h"
#include "obstacle.h"
#include <list>
#include <time.h>

#include <QElapsedTimer>

using namespace std;

#define dop 30

class banc
{
public:
	poisson *ps;
    obstacle *ob;

	int np;
    int no;

    float cohe,alig,sepa,il;

    list<int> opt[dop][dop][dop];
    float fco;
    int t1,t2;

	banc(int _np);
	~banc(void);

	void aff ();
	void anime ();
};

#endif
