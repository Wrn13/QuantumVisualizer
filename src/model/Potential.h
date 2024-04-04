#ifndef H_POTENTIAL
#define H_POTENTIAL
#include <gsl/gsl_matrix.h>
/**
 * Class defining the potential matrix.
 *
 */
class Potential{
    public:
        //Default dimension of the potential
        const int defaultSize = 50;
        /**
         *  Default constructor for size defaultSize.
         */
        Potential(){
            potential = gsl_matrix_alloc(defaultSize, defaultSize);

        }
        /**
         *  Constructor which takes a dimension and creates the 2D potential matrix.
         */
        Potential(size_t dimension){
            potential = gsl_matrix_alloc(dimension, dimension);
        }
        /**
         *  The destructor to free the gsl matrix
         */
        ~Potential(){
            gsl_matrix_free(potential);

        }
        /**
         *  Function to add a constant peak to the current potential matrix.
         *  @param x0 the left index of the peak
         *  @param x1 the right index of the peak
         *  @param y0 the top index of the peak
         *  @param y1 the bottom index of the peak
         *  @param potential the height of the peak
         */
        void addPeak(int x0, int x1, int y0, int y1, double potential);

        /**
         * Function to return the ith and jth elements of the potential matrix
         */
        double get_Vij(int i, int j){ return gsl_matrix_get(potential, i, j);}
    private:

        gsl_matrix * potential;


};



#endif