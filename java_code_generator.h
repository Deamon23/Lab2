#ifndef JAVA_CODE_GENERATOR_H
#define JAVA_CODE_GENERATOR_H

#include "code_generator.h"

// Класс для генерации кода на Java
class JavaCodeGenerator : public CodeGenerator {
public:
    // Генерация кода для класса на Java
    std::string generateClass(const std::string& className) const override {
        return "public class " + className + " {\n";
    }

    // Генерация кода для метода на Java
    std::string generateMethod(const std::string& methodName, const std::string& returnType, unsigned int flags) const override {
        std::string result;
        if (flags & MethodUnit::STATIC) {
            result += "static ";
        }
        if (flags & MethodUnit::VIRTUAL) {
            result += "abstract ";
        }
        result += returnType + " " + methodName + "() {\n";
        return result;
    }

    // Генерация кода для оператора печати на Java
    std::string generatePrint(const std::string& text) const override {
        return "System.out.println(\"" + text + "\");\n";
    }
};

#endif // JAVA_CODE_GENERATOR_H
