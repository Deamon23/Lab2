#ifndef CSHARP_CODE_GENERATOR_H
#define CSHARP_CODE_GENERATOR_H

#include "code_generator.h"

// Класс для генерации кода на C#
class CSharpCodeGenerator : public CodeGenerator {
public:
    // Генерация кода для класса на C#
    std::string generateClass(const std::string& className) const override {
        return "public class " + className + " {\n";
    }

    // Генерация кода для метода на C#
    std::string generateMethod(const std::string& methodName, const std::string& returnType, unsigned int flags) const override {
        std::string result;
        if (flags & MethodUnit::STATIC) {
            result += "static ";
        }
        if (flags & MethodUnit::VIRTUAL) {
            result += "virtual ";
        }
        result += returnType + " " + methodName + "() {\n";
        return result;
    }

    // Генерация кода для оператора печати на C#
    std::string generatePrint(const std::string& text) const override {
        return "Console.WriteLine(\"" + text + "\");\n";
    }
};

#endif // CSHARP_CODE_GENERATOR_H
