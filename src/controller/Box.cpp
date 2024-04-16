#include "Box.h"
#include <cmath>
/**
 *  Helper function to implement the sign function.
 *  -1 if x <0; 0 if x==0; 1 if x>0;
 */
int sgn(double x){
    if(x>0){
        return 1;
    }else if(x==0){
        return 0;
    }else{
        return -1;
    }
}

/**
 * Helper method to shift coordinates.
 */
void shiftCoords(double &min, double &max){
    min += sgn(min) * min;
    max += sgn(min) * min;
}

Box::Box(double x1, double x2, double y1, double y2){
    //Get max and min for each dimension
    double minX = fmin(x1,x2);
    double maxX = fmax(x1,x2);
    double minY = fmin(y1,y2);
    double maxY = fmax(y1,y2);

    //Shift coordinates to be assured positive.
    shiftCoords (minX, maxX);
    shiftCoords (minY, maxY);


}
