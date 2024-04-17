#include "Potential.h"
#include <gsl/gsl_matrix.h>
#include <iostream>
using namespace std;

void Potential::addPeak(int x0, int x1, int y0, int y1, double peak){
    //Error checking
    if(x0 < 0) cout << "Invalid x0 in Potential\n";
    if(x1 >=potential->size1) cout << "Invalid x1 in Potential\n";
    if(y0 < 0) cout<< "Invalid y0 in Potential\n";
    if(y1 >= potential -> size2) cout<< "Invalid y1 in Potential\n";

    //Add peak to required potential indices
    for(int i = y0; i <=y1; ++i){
        for(int j = x0; j <=x1; ++j){
            gsl_matrix_set(potential, i, j, gsl_matrix_get(potential, i, j) + peak);
        }    
    }

}

void Potential::printPotential(){
    for(int i = 0; i<dimension; ++i){
        for(int j = 0; j<dimension; ++j){
            std::cout<< gsl_matrix_get(potential,i,j) <<" ";
        }
        std::cout<<"\n";
    }
}
