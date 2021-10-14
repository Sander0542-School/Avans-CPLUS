#ifndef SPEUREN_MET_KRUL_INTERPRETER_HPP
#define SPEUREN_MET_KRUL_INTERPRETER_HPP

#include "Stack.hpp"
#include "utils/StringUtil.hpp"
#include "Exceptions/SyntaxException.hpp"
#include <map>
#include <string>

using variables_map = std::map<std::string, std::string>;
using labels_map = std::map<std::string, int>;

class Interpreter {
public:
    bool execute(const std::string& file, std::string& result);

private:
    void execute_command(std::string& command, int& i);

    void load_labels(const std::vector<std::string>& commands);

    Stack stack;
    Stack call_stack;
    variables_map variables;
    labels_map labels;
};

#endif //SPEUREN_MET_KRUL_INTERPRETER_HPP
