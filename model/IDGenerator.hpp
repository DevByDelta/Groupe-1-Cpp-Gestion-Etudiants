#pragma once
// IDGenerator.hpp  --  généré automatiquement
// Aminata
#pragma once
#include <string>
#include <unordered_map>
class IDGenerator {
public:
    template<typename T>
    static std::string generate();

private:
    static std::unordered_map<std::string, int> counters;
};

