#include <iostream>
#include "Interpreter.hpp"

bool Interpreter::execute(const std::string& file, std::string& result) {
    stack.clear();
    call_stack.clear();
    variables.clear();
    labels.clear();

    auto commands = StringUtil::split(file);

    load_labels(commands);

    int i = 0;

    while (i >= 0 && i < commands.size())
    {
        std::string command = (commands)[i];

        if (command == "end")
        {
            result = stack.peek();
            return true;
        }

        execute_command(command, i);
    }

    result = stack.peek();

    return false;
}

void Interpreter::execute_command(std::string& command, int& i) {
    i++;
    // Integer operations
    if (command == "add")
    {
        int val1 = stack.pop_int();
        int val2 = stack.pop_int();

        stack.push(val1 + val2);
    }
    else if (command == "sub")
    {
        int val1 = stack.pop_int();
        int val2 = stack.pop_int();

        stack.push(val2 - val1);
    }
    else if (command == "mul")
    {
        int val1 = stack.pop_int();
        int val2 = stack.pop_int();

        stack.push(val1 * val2);
    }
    else if (command == "div")
    {
        int val1 = stack.pop_int();
        int val2 = stack.pop_int();

        stack.push(val2 / val1);
    }
    else if (command == "mod")
    {
        int val1 = stack.pop_int();
        int val2 = stack.pop_int();

        stack.push(val2 % val1);
    }
    else if (command == "neg")
    {
        int val = -stack.pop_int();
        stack.push(val);
    }
    else if (command == "abs")
    {
        int val = stack.pop_int();
        val = std::abs(val);
        stack.push(val);
    }
    else if (command == "inc")
    {
        int val = stack.pop_int();
        stack.push(++val);
    }
    else if (command == "dec")
    {
        int val = stack.pop_int();
        stack.push(--val);
    }
        // String operations
    else if (command == "dup")
    {
        stack.push(stack.peek());
    }
    else if (command == "rev")
    {
        auto val = stack.pop();
        StringUtil::reverse(val);
        stack.push(val);
    }
    else if (command == "slc")
    {
        auto to = stack.pop_int();
        auto from = stack.pop_int();
        auto val = stack.pop();
        stack.push(val.substr(from, to - from));
    }
    else if (command == "idx")
    {
        auto index = stack.pop_int();
        auto val = stack.pop();
        stack.push(val.substr(index, 1));
    }
    else if (command == "cat")
    {
        auto val1 = stack.pop();
        auto val2 = stack.pop();
        stack.push(val2 + val1);
    }
    else if (command == "len")
    {
        auto val = stack.pop();
        stack.push(val.length());
    }
    else if (command == "rot")
    {
        auto val = stack.pop();
        StringUtil::rotate(val, 13);
        stack.push(val);
    }
    else if (command == "enl")
    {
        auto val = stack.pop();
        stack.push(val + '\n');
    }
        // Tests & Jumps
    else if (command == "gto")
    {
        i = stack.pop_int();
    }
    else if (command == "geq")
    {
        auto line = stack.pop_int();
        auto val2 = stack.pop();
        auto val1 = stack.pop();

        if (val1 == val2)
            i = line;
    }
    else if (command == "gne")
    {
        auto line = stack.pop_int();
        auto val2 = stack.pop();
        auto val1 = stack.pop();

        if (val1 != val2)
            i = line;
    }
    else if (command == "glt")
    {
        auto line = stack.pop_int();
        auto val2 = stack.pop_int();
        auto val1 = stack.pop_int();

        if (val1 < val2)
            i = line;
    }
    else if (command == "gle")
    {
        auto line = stack.pop_int();
        auto val2 = stack.pop_int();
        auto val1 = stack.pop_int();

        if (val1 <= val2)
            i = line;
    }
    else if (command == "ggt")
    {
        auto line = stack.pop_int();
        auto val2 = stack.pop_int();
        auto val1 = stack.pop_int();

        if (val1 > val2)
            i = line;
    }
    else if (command == "gge")
    {
        auto line = stack.pop_int();
        auto val2 = stack.pop_int();
        auto val1 = stack.pop_int();

        if (val1 >= val2)
            i = line;
    }
        // Functions
    else if (command == "fun")
    {
        call_stack.push(i);
        std::string gto = "gto";
        execute_command(gto, i);
    }
    else if (command == "ret")
    {
        i = call_stack.pop_int();
    }
        // Values and types
    else if (StringUtil::is_number(command))
    {
        stack.push(command);
    }
    else if (StringUtil::starts_with(command, "\\"))
    {
        command.erase(0, 1);
        stack.push(command);
    }
    else if (StringUtil::starts_with(command, ">"))
    {
        command.erase(0, 1);
        stack.push(labels.at(command));
    }
    else if (StringUtil::starts_with(command, "="))
    {
        command.erase(0, 1);
        variables.erase(command);
        variables.insert(std::make_pair(command, stack.pop()));
    }
    else if (StringUtil::starts_with(command, "$"))
    {
        command.erase(0, 1);
        stack.push(variables.at(command));
    }
        // Helpers
    else if (command == "out")
    {
        std::cout << stack.peek() << std::endl;
    }
    else if (command == "err")
    {
        std::cerr << stack.peek() << std::endl;
    }
    else if (command == "in")
    {
        std::string val;
        std::cin >> val;
        stack.push(val);
    }
        // Comments
    else if (StringUtil::starts_with(command, "#"))
    {
        std::cout << "Comment: " << command.substr(1) << std::endl;
    }
}

void Interpreter::load_labels(const std::vector<std::string>& commands) {
    for (int i = 0; i != commands.size(); i++)
    {
        std::string command = (commands)[i];

        if (StringUtil::starts_with(command, ":"))
        {
            labels.insert(std::make_pair(command.substr(1), i));
        }
    }
}