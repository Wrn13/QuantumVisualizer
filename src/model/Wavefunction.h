#include <gsl/gsl_matrix.h>
/**
 *  Class representing a 2D wavefunction
 *  
 */
class Wavefunction{
public:
    /**
     *  Constructor initializes a single wavepacket
     */
    Wavefunction();
    /**
     *  Constructor initializes with function representing the values
     *
     */ 
    Wavefunction(double initFunction(double x, double y, void * params));

private:
    gsl_matrix * psi;
};
