#include "Hamiltonian.h"
#include <vector>
#include <gsl/gsl_vector.h>
#include "modules/lambda-lanczos/include/lambda_lanczos/lambda_lanczos.hpp"
using namespace std;

Hamiltonian::Hamiltonian (Potential p, int n, double delta){
    //Set all constants
    hamiltonianDimension = n*n;
    double invDeltaSquared = 1./delta/delta;
    //Directions of neighbors. Only need to search across and below to avoid double counting
    vector<vector<int>>directions= {{1,0}, {0,1}};
    // Loop for each row in the potential
    for(int r = 0; r<n; ++r){
        //Loop for each index in the potential
        for(int c = 0; c<n; ++c){
            int j = n*r +c;

            //Set the diagonal element to the corresponding value
            gsl_matrix_set(hamiltonian, j, j, p.get_Vij(r,c) + SPACE_DIMENSION * invDeltaSquared);
            //Set off diagonal elements
            for(auto direction : directions){
                int dx = direction[0];
                int dy = direction[1];
                //Make sure we are at a valid position
                if(j+dx <n*n && j+dy < n*n){
                    gsl_matrix_set(hamiltonian, j + dx, j, -0.5 * invDeltaSquared);
                }
            }
        }
    }
}


void Hamiltonian::diagonalize(){
    //This lambda multiplies a matrix by a vector to be used in the lanczos algorithm
    auto mv_mul = [&](const vector<double> in, vector<double>  out){
        for(int i =0; i < hamiltonianDimension; ++i){
            for(int j =0; j<hamiltonianDimension; ++j){
                out[i] = gsl_matrix_get(hamiltonian, i, j) * in[j];

            }
        }
    };

    //Compute eigenvalues and eigenvectors
    lambda_lanczos::LambdaLanczos <double> engine (mv_mul, hamiltonianDimension, true, 2);
    engine.run(eigenvalues, eigenvectors);

    //Mark as finished
    is_diagonal = true;
}

void Hamiltonian::get_matrix_eigenvector(size_t i){
    eigenvector = gsl_matrix_alloc(sqrt(hamiltonianDimension), sqrt(hamiltonianDimension));
}

