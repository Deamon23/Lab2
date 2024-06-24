#include <QCoreApplication>
#include <iostream>
#include "generator.h"
#include "csharp_code_generator.h"
#include "java_code_generator.h"
#include "cpp_code_generator.h"

int main() {
    // Создание генераторов для C#, Java и C++
    CSharpCodeGenerator csharpGenerator;
    JavaCodeGenerator javaGenerator;
    CppCodeGenerator cppGenerator;

    // Генерация кода на C#
    std::cout << "C# Code:" << std::endl;
    std::cout << generateProgram(csharpGenerator) << std::endl;

    // Генерация кода на Java
    std::cout << "Java Code:" << std::endl;
    std::cout << generateProgram(javaGenerator) << std::endl;

    // Генерация кода на C++
    std::cout << "C++ Code:" << std::endl;
    std::cout << generateProgram(cppGenerator) << std::endl;

    return 0;
}
