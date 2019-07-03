#include "mutation++.h"
#include <iostream>

void printMoleFractions(const Mutation::Mixture& mix) 
{
    for (int i = 0; i < mix.nSpecies(); ++i) {
        std::cout << std::setw(10) << mix.speciesName(i);
        std::cout << std::setw(15) << mix.X()[i] << '\n';
    }
}

void printProductionRates(Mutation::Mixture& mix) 
{
    std::vector<double> wdot(mix.nSpecies());
    mix.netProductionRates(wdot.data());
    for (int i = 0; i < mix.nSpecies(); ++i) {
        std::cout << std::setw(10) << mix.speciesName(i);
        std::cout << std::setw(15) << wdot[i] << '\n';
    }
}

int main(int argc, char* argv[])
{
    // Create the mixture
    Mutation::MixtureOptions options("air5");
    options.setStateModel("ChemNonEq1T");

    Mutation::Mixture mix(options);
    mix.addComposition("N2:0.79, O2:0.21", true);

    // Equilibrate the solution to T and P
    double P = Mutation::ONEATM;
    double T = 7000.0;
    mix.equilibrate(T, P);

    // Print mole fractions
    std::cout << "-- Before changing temperature --\n";
    std::cout << "Mole fractions:\n";
    printMoleFractions(mix);

    // Print the species production rates
    std::cout << "Production rates:\n";
    printProductionRates(mix);

    // Change the temperature but leave the densities the same
    std::vector<double> rho(mix.nSpecies());
    mix.densities(rho.data());
    T = 1000.0;
    mix.setState(rho.data(), &T, 1);

    // Print mole fractions
    std::cout << "-- After changing temperature --\n";
    std::cout << "Mole fractions:\n";
    printMoleFractions(mix);

    // Print the species production rates
    std::cout << "Production rates:\n";
    printProductionRates(mix);

    return 0;
}