/*
 * vect.h
 *
 *  Created on: 10 déc. 2012
 *      Author: r1105260
 */

#ifndef VECT_H_
#define VECT_H_

#include <math.h>
#include <GL/gl.h>
#include <GL/glu.h>
#include <stdlib.h>

class vect;

class vect {
public:
	float x,y,z;

	vect () {x=y=z=0;}
	vect(float a, float b, float c);
	vect(float *a) {x=a[0];y=a[1];z=a[2];}
	vect(double *a) {x=a[0];y=a[1];z=a[2];}
	void set(double *a) {x=a[0];y=a[1];z=a[2];}
	virtual ~vect();

	vect normal() {multiplier_par(1.0/norme()); return *this;}
    vect rnormal() {return (*this)*(1.0/norme());}
	void multiplier_par(float a) {x=a*x;y=a*y;z=a*z;}
	float prodscal(vect v) {return(x*v.x+y*v.y+z*v.z);}

	void vert ()
	{
		glVertex3f (x,y,z);
	}

	vect random ()
	{
		x=(float)rand()/RAND_MAX;
		y=(float)rand()/RAND_MAX;
		z=(float)rand()/RAND_MAX;
		return *this;
	}

	vect operator ^ (vect w)
	{
		//vect z( y*w.z-w.y*z, z*w.x-w.z*x, x*w.y-w.x*y );
		float c1 = y*w.z-w.y*z;
		float c2 = z*w.x-w.z*x;
		float c3 = x*w.y-w.x*y;
		vect z (c1,c2,c3);
		return(z);
	}
	vect operator * (float f)     //produit par un réel
    {
    return vect(x*f,y*f,z*f);
	}
	float operator * (vect w) {return prodscal(w);}

	vect operator + (vect w)
	{
		vect zz(0,0,0);
		zz.x=x+w.x;
		zz.y=y+w.y;
		zz.z=z+w.z;
		return(zz);
	}

	vect operator += (vect w)
	{
		x=x+w.x;
		y=y+w.y;
		z=z+w.z;
		return vect(x,y,z);
	}

	vect operator - (vect w)
	{
		vect zz(0,0,0);
		zz.x=x-w.x;
		zz.y=y-w.y;
		zz.z=z-w.z;
		return(zz);
	}

	float norme () {return sqrt(x*x+y*y+z*z);}
	float normec () {return x*x+y*y+z*z;}
};

#endif /* VECT_H_ */
