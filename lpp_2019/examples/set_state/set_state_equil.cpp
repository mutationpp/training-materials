#include "mutation++.h"
#include <iostream>

int main(int argc, char* argv[])
{
    // Create the mixture
    Mutation::MixtureOptions options("air5");
    options.setStateModel("Equil");

    Mutation::Mixture mix(options);
    mix.addComposition("N2:0.79, O2:0.21", true);

    double P = Mutation::ONEATM;
    double T = 7000.0;
    mix.setState(&P, &T, 1);

    for (int i = 0; i < mix.nSpecies(); ++i) {
        std::cout << std::setw(10) << mix.speciesName(i);
        std::cout << std::setw(15) << mix.X()[i] << '\n';
    }
    
    return 0;
}