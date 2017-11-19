#include "poisson.h"


poisson::poisson()
{
    ai=0;;
}
poisson::poisson(vect _p, vect _v, float s, float ve)
{
	p=_p;
	v=_v;
	sz=s;
    vs=ve;
    ai=0;
}


poisson::~poisson(void)
{
}

void poisson::aff()
{
    vect nez = v.normal();
    vect nag = nez^vect(nez.z,nez.y,-nez.x);
    vect nag2=nez^nag;
	glBegin (GL_TRIANGLES);
    glColor3f (0,0,1);(p+nag*0.1).vert();
    glColor3f (0,0,1);(p-nag*0.1).vert();
	glColor3f (1,0,0);(p+nez).vert();
	glEnd ();

    glBegin (GL_TRIANGLES);
    glColor3f (0,0,1);(p+nag2*0.1).vert();
    glColor3f (0,0,1);(p-nag2*0.1).vert();
    glColor3f (1,0,0);(p+nez).vert();
    glEnd ();

    /*glColor3f (1,1,1);
    glBegin (GL_LINE_STRIP);
    int i=ai;
    for (int j=0; j<L; j++)
    {

        glVertex3f (apos[i].x,apos[i].y,apos[i].z);
        i++;
        if (i>L-1) i=0;

    }
    glEnd ();*/
}

void poisson::anime (float tp)
{
    //apos[ai++]=p;
	p=p+v*tp;
    //if (ai==L)ai=0;
}


bool poisson::voisin (vect w)
{
	return (w-p).norme()<vs;
}
