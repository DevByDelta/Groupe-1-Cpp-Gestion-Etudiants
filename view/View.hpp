#pragma once

#include <string>

class View {
public:
    virtual ~View();
    void showMessage(const std::string& message);
    std::string promptString(const std::string& message);
    int promptInt(const std::string& message);
    double promptDouble(const std::string& message);
    bool promptYesNo(const std::string& message);
    void warning(const std::string& msg);
    void success(const std::string& msg);
    void error(const std::string& msg);
    
};
