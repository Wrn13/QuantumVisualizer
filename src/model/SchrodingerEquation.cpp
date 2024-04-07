#include "Potential.h"
#include "Wavefunction.h"
class SchrodingerEquation{
    public:
        SchrodingerEquation(Potential p, Wavefunction w);

    private:
        Potential p;
        Wavefunction w;

};
