#ifndef PARTICLES_H
#define PARTICLES_H
#define COUNT 50000
#define V_COUNT 5
#include <math.h>
#include <ofVectorMath.h>
struct particle
{
    float x;
    float y;
    ofVec2f currVect;
    ofVec2f aimVect;
};

struct circVect
{
    float x;
    float y;
    float r;
    ofVec2f Vect;
};

float sqr(float val);

float dist(float x, float y);
class particles
{
    public:
        particle parts[COUNT];
        particles(){}
        particles(int width, int height);
        ~particles();
        circVect V[V_COUNT];
        void recalc();
        void nextstep();
    protected:
    private:
};

#endif // PARTICLES_H
