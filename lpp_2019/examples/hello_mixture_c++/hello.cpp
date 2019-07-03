#include "mutation++.h"
#include <iostream>

using namespace Mutation;

int main(int argc, char* argv[])
{
    // Load air5 mixture or the mixture given on command line, if given
    std::string name = "air_5";
    if (argc > 1) name = argv[1];
    Mixture mix(name);
    
    // Print the species
    std::cout << "Species: ";
    for (auto& s : mix.species()) 
        std::cout << s.name() << ' ';
    std::cout << '\n';
    
    // Print the reactions
    std::cout << "Reactions:\n";
    for (auto& r : mix.reactions())
        std::cout << r.formula() << '\n';
    
    return 0;
}