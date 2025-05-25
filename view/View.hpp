#pragma once

#include <string>

class View {
public:
    View() = default;
    ~View() = default;

    static void showMessage(const std::string& message);
    static std::string promptString(const std::string& message);
    static int promptInt(const std::string& message);
    static double promptDouble(const std::string& message);
    static bool promptYesNo(const std::string& message);
};
