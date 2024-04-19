#include "Hamiltonian.h"
#include <vector>
#include <gsl/gsl_vector.h>
#include <gsl/gsl_matrix.h>
#include <fstream>
#include "modules/lambda-lanczos/include/lambda_lanczos/lambda_lanczos.hpp"
using namespace std;

Hamiltonian::Hamiltonian (Potential p, int n, double delta){
    cout<<"GOT TO CONSTRUCTOR!";
    //Set all constants
    hamiltonianDimension = n*n;
    hamiltonian = gsl_matrix_calloc(hamiltonianDimension, hamiltonianDimension);
    double invDeltaSquared = 1./delta/delta;
    //Directions of neighbors. Only need to search across and below to avoid double counting
    vector<vector<int>>directions= {{1,0}, {0,1}};
    // Loop for each row in the potential
    for(int r = 0; r<n; ++r){
        //Loop for each index in the potential
        for(int c = 0; c<n; ++c){
            int j = n*r +c;
            //Set the diagonal element to the corresponding value
            gsl_matrix_set(hamiltonian, j, j, p.get_Vij(c,r) + SPACE_DIMENSION * invDeltaSquared);
            //Set off diagonal elements
            for(auto direction : directions){
                int dx = direction[0];
                int dy = direction[1];
                //Make sure we are at a valid position
                if(j+dx < hamiltonianDimension && j+dy < hamiltonianDimension){
                    gsl_matrix_set(hamiltonian, j + dx, j+dy, -0.5 * invDeltaSquared);
                }
            }
        }
    }
    eigenvector = gsl_matrix_alloc(n,n);
    cout<<"Finished Allocating\n";
    is_diagonal = false;
}


void Hamiltonian::diagonalize(){
    //This lambda multiplies a matrix by a vector to be used in the lanczos algorithm
    auto mv_mul = [&](const vector<double>& in, vector<double>& out){
        for(int i =0; i < hamiltonianDimension; ++i){
            for(int j =0; j<hamiltonianDimension; ++j){
                out[i] = gsl_matrix_get(hamiltonian, i, j) * in[j];
            }
        }
    };

    //Compute eigenvalues and eigenvectors
    lambda_lanczos::LambdaLanczos <double> engine (mv_mul, hamiltonianDimension, false, 1);
    engine.run(eigenvalues, eigenvectors);
    //Mark as finished
    is_diagonal = true;
}

void Hamiltonian::get_matrix_eigenvector(int v){
    int n = sqrt(hamiltonianDimension);
    for(int i =0; i<n; ++i){
        for(int j =0; j<n; ++j){
            gsl_matrix_set(eigenvector,i,j,eigenvectors[v][n*i+j]);
        }
    }

}

void Hamiltonian::printHamiltonian(){
    for(int i = 0; i < 30; ++i){
        for(int j = 0; j<30; ++j){
            cout<<gsl_matrix_get(hamiltonian, i, j) <<" ";
        }
        cout<<"\n";
    }

}

void Hamiltonian::output(int l, const std::string & fileName){
    
    ofstream outputFile (fileName.c_str());
    get_matrix_eigenvector(l);

    cout<<"Eigenvalue for l=" << l <<" is " << eigenvalues[l]<<"\n";

    int n = sqrt(hamiltonianDimension);
    for(int i = 0; i<n; ++i){
        for(int j =0; j<n; ++j){
            outputFile << i<< " "<< j<< " "<< gsl_matrix_get(eigenvector, i,j) <<"\n";
        }
    }
    cout<<"Output file created.\n";
    outputFile.close();
}

