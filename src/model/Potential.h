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
            dimension = defaultSize;
            clearPotential();
        }
        /**
         *  Constructor which takes a single dimension and creates the 2D potential matrix size dim x dim.
         */
        Potential(size_t dim){
            potential = gsl_matrix_alloc(dim, dim);
            dimension = dim;
            clearPotential();
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

        /**
         *  Function to return the dimension of the potential.
         */
        double get_dimension(){return dimension;}

        void clearPotential(){
            for(int i =0; i<dimension; ++i){
                for(int j =0; j<dimension; ++j){
                    gsl_matrix_set(potential,i,j,0);
                }
            }
        }

        void printPotential();
    private:
        gsl_matrix * potential;
        size_t dimension;

};



#endif
