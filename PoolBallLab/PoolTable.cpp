// PoolTable implementation
//
#include "PoolTable.h"
#include "PoolBall.h"
#include <cmath>
#include <iostream>
using namespace std;

double PI = acos(-1);

PoolTable::PoolTable(int n){
    // constructor for n poolballs
    set_position(n);    // initialize all N poolball positions
}

void PoolTable::set_position(int n) {
    // position n balls in a line with different speeds
    num_balls = n;
    for(int i=0;i<n;i++) {
        balls[i].xPos = 50 * (i+2);
    }
}

// collision routines. WARMNG! Heavy Math!

double find_angle(double vx, double vy) {
    // determine the angle between poolballs when they collide
    double t; double PI = acos(-1.0);
    if(vx < 0) // vertical collision
        t = PI + atan(vy/vx);
    else if(vx > 0.0 && vy >= 0.0) // 1st quardant collision
        t = atan(vy/vx);
    else if(vx > 0.0 && vy < 0.0) //
        t = 2.0*PI + atan(vy/vx);
    else if( vx == 0.0 && vy == 0.0)
        t = 0.0;
    else if(vx == 0 && vy >= 0.0)
        t = PI/2.0;
    else
        t = 1.5 * PI;
    return t;
}

    
void PoolTable::checkCollisions(int i, int j) {
    // handle ball collisions
    //  ref: http://director-online.com/buildArticle.php?id=532
    double PI = acos(-1.0);
    double x1 = balls[i].xPos;
    double y1 = balls[i].yPos;
    double x2 = balls[j].xPos;
    double y2 = balls[j].yPos;
    double dx = x2 - x1;
    double dy = y2 - y1;
    double dist = sqrt(dx*dx+dy*dy);
    // did a collision occur
    if(dist <= 2 * balls[i].radius + 1) {   // boing    //ADDED the +1
	 //added to try to change the colors when the balls hit.

        double phi; // angle between the two ball centers
        // watch for vertical hits
        if(dx == 0.0)
            phi = PI/2.0;
        else
            phi = atan2 (dy, dx);

        // now compute the total velocities of the two balls
        double vx1 = balls[i].xVelocity;
        double vy1 = balls[i].yVelocity;
        double v1total = sqrt(vx1*vx1 + vy1*vy1);
        double vx2 = balls[j].xVelocity;
        double vy2 = balls[j].yVelocity;
        double v2total = sqrt(vx2*vx2 + vy2*vy2);

        // find the angle of each ball's velocity
        double ang1 = find_angle(vx1,vy1);
        double ang2 = find_angle(vx2,vy2);

        // transform velocities into normal.tangential components
        double v1xr = v1total * cos(ang1 - phi);
        double v1yr = v1total * sin(ang1 - phi);
        double v2xr = v2total * cos(ang2 - phi);
        double v2yr = v2total * sin(ang2 - phi);

        // now find the final velocities (assuming equal mass)
        double v1fxr = v2xr;
        double v2fxr = v1xr;
        double v1fyr = v1yr;
        double v2fyr = v2yr;

        // reset the velocities
        balls[i].xVelocity = cos(phi)*v1fxr + cos(phi+PI/2)*v1fyr;
        balls[i].yVelocity = sin(phi)*v1fxr + sin(phi+PI/2)*v1fyr;
        balls[j].xVelocity = cos(phi)*v2fxr + cos(phi+PI/2)*v2fyr;
        balls[j].yVelocity = sin(phi)*v2fxr + sin(phi+PI/2)*v2fyr;
    }
}

void PoolTable::check_collisions(void) {
    // check for ball to ball collisions
    for(int i=0;i<num_balls;i++) {
        // skip ball hitting itself
        for(int j=i+1;j<num_balls;j++) {
            checkCollisions(i,j);
        }
    }
}

void PoolTable::update(void) {
    // table says for all balls to move themselves
    for(int i=0;i<num_balls;i++) {
        balls[i].update();
    }
    check_collisions();
}

void PoolTable::draw(void) {
    // table says for all balls to draw themselves
    for(int i=0;i<num_balls;i++) {
        balls[i].draw();
    }
}
