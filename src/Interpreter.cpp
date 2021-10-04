#include <iostream>
#include "Interpreter.hpp"

Interpreter::Interpreter() {
    stack = new Stack;
    call_stack = new Stack;
    variables = new variables_map;
    labels = new labels_map;
}

Interpreter::~Interpreter() {
    delete labels;
    delete variables;
    delete call_stack;
    delete stack;
}

bool Interpreter::execute(const std::string file, std::string* result) {
    stack->clear();
    call_stack->clear();
    variables->clear();
    labels->clear();

    auto commands = StringUtil::split(file, "\n");

    load_labels(commands);

    int i = 0;

    while (i >= 0 && i < commands->size())
    {
        std::string command = (*commands)[i];

        if (command == "end")
        {
            *result = stack->peek();
            return true;
        }

        execute_command(command, &i);
    }

    *result = stack->peek();

    return false;
}

void Interpreter::execute_command(std::string command, int* i) {
    *i = *i + 1;
    // Values and types
    if (std::regex_match(command, std::regex("[0-9]*")))
    {
        stack->push(command);
    }
    else if (StringUtil::starts_with(command, "\\"))
    {
        stack->push(command.substr(1));
    }
    else if (StringUtil::starts_with(command, ":"))
    {
        // do nothing
    }
    else if (StringUtil::starts_with(command, ">"))
    {
        stack->push(labels->at(command.substr(1)));
    }
    else if (StringUtil::starts_with(command, "="))
    {
        variables->erase(command.substr(1));
        variables->insert(std::make_pair(command.substr(1), stack->pop()));
    }
    else if (StringUtil::starts_with(command, "$"))
    {
        stack->push(variables->at(command.substr(1)));
    }
        // Integer operations
    else if (command == "add")
    {
        int val1 = std::stoi(stack->pop());
        int val2 = std::stoi(stack->pop());

        stack->push(val1 + val2);
    }
    else if (command == "sub")
    {
        int val1 = std::stoi(stack->pop());
        int val2 = std::stoi(stack->pop());

        stack->push(val2 - val1);
    }
    else if (command == "mul")
    {
        int val1 = std::stoi(stack->pop());
        int val2 = std::stoi(stack->pop());

        stack->push(val1 * val2);
    }
    else if (command == "div")
    {
        int val1 = std::stoi(stack->pop());
        int val2 = std::stoi(stack->pop());

        stack->push(val2 / val1);
    }
    else if (command == "mod")
    {
        int val1 = std::stoi(stack->pop());
        int val2 = std::stoi(stack->pop());

        stack->push(val2 % val1);
    }
    else if (command == "neg")
    {
        int val = -std::stoi(stack->pop());
        stack->push(val);
    }
    else if (command == "abs")
    {
        int val = std::stoi(stack->pop());
        val = std::abs(val);
        stack->push(val);
    }
    else if (command == "inc")
    {
        int val = std::stoi(stack->pop());
        stack->push(++val);
    }
    else if (command == "dec")
    {
        int val = std::stoi(stack->pop());
        stack->push(--val);
    }
        // String operations
    else if (command == "dup")
    {
        stack->push(stack->peek());
    }
    else if (command == "rev")
    {
        auto val = stack->pop();
        val = StringUtil::reverse(val);
        stack->push(val);
    }
    else if (command == "slc")
    {
        auto to = std::stoi(stack->pop());
        auto from = std::stoi(stack->pop());
        auto val = stack->pop();
        stack->push(val.substr(from, to - from));
    }
    else if (command == "idx")
    {
        auto index = std::stoi(stack->pop());
        auto val = stack->pop();
        stack->push(val.substr(index, 1));
    }
    else if (command == "cat")
    {
        auto val1 = stack->pop();
        auto val2 = stack->pop();
        stack->push(val2 + val1);
    }
    else if (command == "len")
    {
        auto val = stack->pop();
        stack->push(val.length());
    }
    else if (command == "rot")
    {
        auto val = stack->pop();
        stack->push(StringUtil::rotate(val, 13));
    }
    else if (command == "enl")
    {
        auto val = stack->pop();
        stack->push(val + '\n');
    }
        // Tests & Jumps
    else if (command == "gto")
    {
        *i = std::stoi(stack->pop());
    }
    else if (command == "geq")
    {
        auto line = std::stoi(stack->pop());
        auto val2 = stack->pop();
        auto val1 = stack->pop();

        if (val1.compare(val2) == 0)
            *i = line;
    }
    else if (command == "gne")
    {
        auto line = std::stoi(stack->pop());
        auto val2 = stack->pop();
        auto val1 = stack->pop();

        if (val1.compare(val2) != 0)
            *i = line;
    }
    else if (command == "glt")
    {
        auto line = std::stoi(stack->pop());
        auto val2 = std::stoi(stack->pop());
        auto val1 = std::stoi(stack->pop());

        if (val1 < val2)
            *i = line;
    }
    else if (command == "gle")
    {
        auto line = std::stoi(stack->pop());
        auto val2 = std::stoi(stack->pop());
        auto val1 = std::stoi(stack->pop());

        if (val1 <= val2)
            *i = line;
    }
    else if (command == "ggt")
    {
        auto line = std::stoi(stack->pop());
        auto val2 = std::stoi(stack->pop());
        auto val1 = std::stoi(stack->pop());

        if (val1 > val2)
            *i = line;
    }
    else if (command == "gge")
    {
        auto line = std::stoi(stack->pop());
        auto val2 = std::stoi(stack->pop());
        auto val1 = std::stoi(stack->pop());

        if (val1 >= val2)
            *i = line;
    }
        // Functions
    else if (command == "fun")
    {
        call_stack->push(*i);
        execute_command("gto", i);
    }
    else if (command == "ret")
    {
        auto line = std::stoi(call_stack->pop());
        *i = line;
    }
    else
    {
        std::cout << "Command \"" << command << "\" not found" << std::endl;
    }
}

void Interpreter::load_labels(std::vector<std::string>* commands) {
    int i = 0;
    while (i < commands->size())
    {
        std::string command = (*commands)[i];

        if (StringUtil::starts_with(command, ":"))
        {
            labels->insert(std::make_pair(command.substr(1), i));
        }

        i++;
    }
}
