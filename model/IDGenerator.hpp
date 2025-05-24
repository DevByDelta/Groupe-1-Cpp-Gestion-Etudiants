#pragma once
// IDGenerator.hpp  --  généré automatiquement
// Aminata
#include <string>
#include<atomic>
#include<typeinfo>

class IDGenerator {
public:
    template<typename T>
    static std::string generate(){
        static std::atomic<long> counter{0};
        long c =++counter;
        return std::string(typeid(T).name()) + "_" + std::to_string(c);
    }
};
