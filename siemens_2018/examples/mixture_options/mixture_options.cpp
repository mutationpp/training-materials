#include "mutation++.h"
#include <iostream>

int main(int argc, char* argv[])
{
    // Setup mixture options
    Mutation::MixtureOptions options;
    options.setSpeciesDescriptor("{gases with N,O}");
    options.setThermodynamicDatabase("NASA-9");

    // Create the mixture
    Mutation::Mixture mix(options);
    
    // Print the species
    std::cout << "Species: ";
    for (auto& s : mix.species()) 
        std::cout << s.name() << ' ';
    std::cout << '\n';
    
    return 0;
}