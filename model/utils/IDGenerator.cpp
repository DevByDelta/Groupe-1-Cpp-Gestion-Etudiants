#include "IDGenerator.hpp"

#include <fstream>
#include <map>
#include <string>
#include <sstream>

namespace {
    std::map<std::string, int> counters;
    const std::string dbDirectory = "database";
    const std::string storageFile = dbDirectory + "\\id_generator_state.txt";
    bool loaded = false;

    void loadCounters() {
        std::ifstream file(storageFile.c_str());
        if (!file.is_open()) return;

        std::string prefix;
        int count;
        while (file >> prefix >> count) {
            counters[prefix] = count;
        }

        file.close();
    }

    void saveCounters() {
        std::ofstream file(storageFile.c_str());
        for (std::map<std::string, int>::iterator it = counters.begin(); it != counters.end(); ++it) {
            file << it->first << " " << it->second << "\n";
        }
        file.close();
    }

    std::string intToString(int value) {
        std::ostringstream oss;
        oss << value;
        return oss.str();
    }
}

std::string IDGenerator::generate(const std::string& prefix) {
    if (!loaded) {
        loadCounters();
        loaded = true;
    }

    int& count = counters[prefix];
    count += 1;

    saveCounters();

    return prefix + intToString(count);
}
