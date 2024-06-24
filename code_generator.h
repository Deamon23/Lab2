#ifndef CODE_GENERATOR_H
#define CODE_GENERATOR_H

#include <string>

// Абстрактный базовый класс для генерации кода
class CodeGenerator {
public:
    virtual ~CodeGenerator() = default;

    // Виртуальные методы для генерации различных частей кода
    virtual std::string generateClass(const std::string& className) const = 0;
    virtual std::string generateMethod(const std::string& methodName, const std::string& returnType, unsigned int flags) const = 0;
    virtual std::string generatePrint(const std::string& text) const = 0;
};

#endif // CODE_GENERATOR_H
