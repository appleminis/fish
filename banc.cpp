#include "banc.h"

inline int clamp(int i)
{
    if (i<0) return 0;
    if (i>dop-1) return dop-1;
    return i;
}

banc::banc(int _np)
{
	np = _np;
	ps = new poisson[np];

	for (int i=0; i<np; i++)
	{
        ps[i].p=vect().random()*4-vect(1,1,1)*6;
        ps[i].v=(vect().random()-vect(1,1,1)*0.5)*0.1*0+vect(1,0,0)*0;
		ps[i].sz=1;
        ps[i].vs=10;
	}

    fco = (float)dop/(15*2.0);

    ob = new obstacle[no=5];
    ob[0].r=15;
    ob[1].r=3;
    ob[1].p=vect(11,1,0);

    ob[2].r=5;
    ob[2].p=vect(0,-12,1);

    ob[3].r=3;
    ob[3].p=vect(-10,0,0);

    ob[4].r=5;
    ob[4].p=vect(0,3,-10);

    for (int i=0; i<dop; i++) for (int j=0; j<dop; j++) for (int k=0; k<dop; k++)
    {
        opt[i][j][k].clear();
    }
    for (int i=0; i<np; i++)
    {
        vect v = ps[i].p;
        opt[clamp((v.x+15)*fco)][clamp((v.y+15)*fco)][clamp((v.z+15)*fco)].push_back(i);
    }

    cohe=0;
    alig=0;
    sepa=0;
    il=0.1;
}


banc::~banc(void)
{
	delete []ps;
}

void banc::aff ()
{
    static GLUquadric *params=NULL; if (params==NULL) params = gluNewQuadric();
	for (int i=0; i<np; i++)
	{
		ps[i].aff();
	}

    glColor3f(0,0,0);

    for (int i=1; i<no; i++)
    {
        glPushMatrix();
        glTranslatef(ob[i].p.x,ob[i].p.y,ob[i].p.z);
        gluSphere(params,ob[i].r,2+ob[i].r*2,2+ob[i].r*2);
        glPopMatrix();
    }

    glPolygonMode(GL_FRONT_AND_BACK, GL_LINE);

    glPolygonMode(GL_FRONT_AND_BACK, GL_FILL);
}

void banc::anime ()
{
    QElapsedTimer et;
    vect *nv = new vect[np];
    float d,fr;
    int nbv;
    poisson *p,*pv;
    vect v(0,0,0);

    et.start();
    for (int i=0; i<dop; i++) for (int j=0; j<dop; j++) for (int k=0; k<dop; k++)
    {
        opt[i][j][k].clear();
    }
    for (int i=0; i<np; i++)
    {
        nv[i]=vect(0,0,0);
        vect v = ps[i].p;
        opt[clamp((v.x+15)*fco)][clamp((v.y+15)*fco)][clamp((v.z+15)*fco)].push_back(i);
    }
    t1=et.elapsed();


    et.start();
	for (int i=0; i<np; i++)
	{
		nbv=0;
        vect vm(0,0,0),pm(0,0,0),vp(0,0,0);
		p = &ps[i];

        vect vn=p->v.rnormal();

        /*for (int j=0; j<np; j++)
        {
            if (i!=j)
            {
                pv = &ps[j];
                vp = p->p-pv->p;
                d=(vp).norme();
                if (d*d<p->vs && vn*vp.rnormal()<0.75)
                {
                    nbv++;
                    vm+=pv->v;
                    pm+=pv->p;

                    fr = sepa/(d*d+0.01);
                    nv[i]+=(vp)*fr;
                    nv[j]+=(vp)*fr*-1;
                }
            }
        }*/

        int ix=int((p->p.x+15.0)*fco);
        int iy=int((p->p.y+15.0)*fco);
        int iz=int((p->p.z+15.0)*fco);


        list<int>::iterator it;
        for (int _i=ix-2; _i<ix+3; _i++)
        for (int _j=iy-2; _j<iy+3; _j++)
        for (int k=iz-2; k<iz+3; k++)
        {
            if (!(_i<0 || _j<0 || k<0 || _i>dop-1 || _j>dop-1 || k>dop-1))
            {
                for (it=opt[_i][_j][k].begin(); it!=opt[_i][_j][k].end(); ++it)
                {
                    int j=*it;

                    if (i!=j)
                    {
                        pv = &ps[j];
                        vp = p->p-pv->p;
                        d=vp.normec();
                        vp.multiplier_par(1.0/d);
                        if (d<p->vs && vn*vp<0.75)
                        {
                            nbv++;
                            vm+=pv->v;
                            pm+=pv->p;

                            fr = sepa/(d+0.01);
                            nv[i]+=(vp)*fr;
                            nv[j]+=(vp)*fr*-1;
                        }
                    }
                }
            }
        }

		if (nbv)
		{
            vm=vm*(1.0/nbv);
            pm=pm*(1.0/nbv);

            vect v1 = (pm-p->p);
            vect v2 = (vm-p->v);
            vect v3 = vect(0,0,0);

            vect v = v1*cohe+v2*alig;//*(1.0/(v1.normec()+1))

            nv[i]+=v;
		}

    }

    t2=et.elapsed();

    for (int i=0; i<np; i++)
    {
        p = &ps[i];

        for (int j=0; j<no; j++)
        {
            d=(ob[j].p-p->p).norme();
            //if (d*d<p->vs)
            {
                float rp=d-ob[j].r;
                nv[i] += (ob[j].p-p->p).normal()*(4.0/(rp*rp*10+0.1))*(rp>0?-1:1);
            }
        }
    }


	for (int i=0; i<np; i++)
	{
		ps[i].v=ps[i].v*(1-il)+nv[i]*il;
        ps[i].anime(0.2);
	}

    delete []nv;
}
