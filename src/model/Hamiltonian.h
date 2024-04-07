#include "Potential.h"
#include <gsl/gsl_matrix.h>
#include <iostream>
/**
 * Class representing the Hamiltonian of the system.
 */ 
class Hamiltonian{
    public:
        /** Constructor to generate the Hamiltonian.
         * @Param p The potential of the system
         * @Param n the size in each direction of the potential
         * @Param delta the distance between grid points; smaller => more precise
         */
        Hamiltonian(Potential p, int n, double delta);
        /**
         * Diagonalize the matrix.
         * Requires is_diagonalized == true. 
         */
        void diagonalize();
        /**
         * Returns if the hamiltonian is diagonalized or not.
         */
        bool is_diagonalized() {return is_diagonal;}

        int get_Hij(int i, int j){
            if (i < 0 || j < 0 || i >= hamiltonianDimension || j >= hamiltonianDimension){
                std::cout<<"Invalid dimension in Hamiltonian accessor.\n";
                return -1;
            }
            return gsl_matrix_get(hamiltonian, i, j);
        }
    private:
        
        gsl_matrix * hamiltonian;
        bool is_diagonal = false;
        int hamiltonianDimension;
        gsl_vector * eigenvalues;
        gsl_matrix * eigenvectors;

};
