#ifndef H_BOX
#define H_BOX
/**
 * Class to convert mouse coordinates to integer indices for Potential.
 */
class Box{

    public:
        /**
         *  Contstructor takes mouse coordinates and creates object.
         *  Converts coordinates to indices and performs index checking.
         */
        Box(double x0, double x1, double y0, double y1);
        
        int left(){return left_x;}
        int right(){return right_x;}
        int top(){return top_y;}
        int bottom(){return bottom_y;}

    private:
        int left_x;
        int right_x;
        int top_y;
        int bottom_y;
        const double X_MIN = 0.;
        const double X_MAX = 1000.;
        const double Y_MIN = 0.;
        const double Y_MAX = 1000.;
};
#endif
