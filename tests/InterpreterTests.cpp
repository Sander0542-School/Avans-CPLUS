#include "InterpreterTests.hpp"

void InterpreterTests::run() {
    test_files();
}

void InterpreterTests::test_files() {
    const std::string baseUrl = "https://gist.githubusercontent.com/Sander0542/2f14d5f7ae656ad91dba180764c19710/raw/";
    HttpClient httpClient;
    Interpreter interpreter;

    auto files = std::map<std::string, bool>{
            {"abs.krul",       true},
            {"add.krul",       true},
            {"cat.krul",       true},
            {"dec.krul",       true},
            {"div.krul",       true},
            {"dup.krul",       true},
            {"fail.krul",      false},
            {"fun.krul",       true},
            {"gge.krul",       true},
            {"ggt.krul",       true},
            {"gle.krul",       true},
            {"glt.krul",       true},
            {"gne.krul",       true},
            {"idx.krul",       true},
            {"inc.krul",       true},
            {"labels.krul",    true},
            {"len.krul",       true},
            {"mod.krul",       true},
            {"mul.krul",       true},
            {"neg.krul",       true},
            {"rev.krul",       true},
            {"rot.krul",       true},
            {"slc.krul",       true},
            {"sub.krul",       true},
            {"variables.krul", true},
    };

    std::string base;
    Assert::Start("Interpreter (base.krul)");
    Assert::True(httpClient.get(baseUrl + "base.krul", &base));

    base += "\n";

    for (const auto& file: files)
    {
        Assert::Start("Interpreter (" + file.first + ")");

        std::string content;
        auto success = httpClient.get(baseUrl + file.first, &content);

        Assert::True(success);
        if (success)
        {
            std::string result;
            try
            {
                Assert::Same(file.second, interpreter.execute(base + content, result));
            }
            catch (const SyntaxException& ex)
            {
                Assert::False(file.second);
            }
        }
    }
}
