#ifndef HAMILTONIAN_H
#define HAMILTONIAN_H

#include "Potential.h"
#include <gsl/gsl_matrix.h>
#include <iostream>
#include <vector>
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

        ~Hamiltonian(){
            gsl_matrix_free(hamiltonian);
            gsl_matrix_free(eigenvector);
            
        }
        
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

        /**
         *  The dimensionality of the hamiltonian.
         */
        const int SPACE_DIMENSION = 2;


        /**
         * Function to get the ith eigenvector and convert it to matrix form.
         * This is because eigenvectors are stored as an n^2 length list and
         * we might need to convert it to a nicer format.
         */
        void get_matrix_eigenvector(int v);

        /**
         *  Function to output the designated energy level to the designated file name.
         */
        void output(int level, const std::string & fileName);


        /**
         *  Debug function to print a part of the hamiltonian.
         */
        void printHamiltonian();
    private:

        /**
         * Private fields holding the hamiltonian matrix, state of the matrix, dimension, eigenvalues, eigenvector list, and specific eigenvector.
         */
        gsl_matrix * hamiltonian;
        bool is_diagonal = false;
        int hamiltonianDimension;
        std::vector<double> eigenvalues;
        std::vector<std::vector<double>> eigenvectors;
        gsl_matrix * eigenvector;
};

#endif
