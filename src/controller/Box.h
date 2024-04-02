#ifndef H_BOX
#define H_BOX
class Box{
    public:
        Box(double x0, double x1, double y0, double y1);
        
        
    private:
        int left_x;
        int right_x;
        int top_y;
        int bottom_y;
};
#endif
