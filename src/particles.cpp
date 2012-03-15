#include "particles.h"
float sqr(float val)
{
    return pow(val,2);
}

float dist(float x, float y)
{
    return sqrt(sqr(x)+sqr(y));
}
particles::particles(int width, int height)
{
    for(int j=0;j<V_COUNT;j++)
    {
        V[j].x=0;
        V[j].y=0;
        V[j].r=0 ;
        V[j].Vect.x=0;
        V[j].Vect.y=0;
    }
    for(int i=0;i<COUNT;i++)
    {
            parts[i].x=rand()%(width);
            parts[i].y=rand()%(height);
    }
}

particles::~particles()
{
    //dtor
}

void particles::recalc()
{
    ofVec2f tmp[V_COUNT];
    ofVec2f atmp;
    for(int i=0;i<COUNT;i++)
    {
        atmp.x=0;
        atmp.y=0;
        int k;
        for(k=0;k<V_COUNT;k++)
            if((int)V[k].Vect.x==0)
                if((int)V[k].Vect.y==0)
                    break;
        for(int j=0;j<k;j++)
        {
            tmp[j].x=V[j].Vect.x;
                tmp[j].y=V[j].Vect.y;
                tmp[j].x=V[j].Vect.x;
                tmp[j].y=V[j].Vect.y;
            atmp+=tmp[j].rotateRad(atan2(parts[i].y-V[j].y,parts[i].x-V[j].x))/dist(parts[i].x-V[j].x,parts[i].y-V[j].y);
        }
            parts[i].aimVect=atmp;
    }

}

void particles::nextstep()
{
    for(int i=0;i<COUNT;i++)
    {
        parts[i].currVect.x+=(parts[i].aimVect.x-parts[i].currVect.x)/200;
        parts[i].currVect.y+=(parts[i].aimVect.y-parts[i].currVect.y)/200;
        parts[i].x+=parts[i].currVect.x;
        parts[i].y+=parts[i].currVect.y;
    }
}
