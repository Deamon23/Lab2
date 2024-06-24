#ifndef GENERATOR_H
#define GENERATOR_H

#include <memory>

#include "class_unit.h"
#include "method_unit.h"
#include "print_operator_unit.h"
#include "csharp_code_generator.h"
#include "java_code_generator.h"
#include "cpp_code_generator.h"

// Функция для генерации программы с использованием заданного генератора кода
std::string generateProgram(const CodeGenerator& generator) {
    // Создаем объект класса
    ClassUnit myClass( "MyClass" );

    // Добавляем методы в класс с различными модификаторами доступа и флагами
    myClass.add(
        std::make_shared< MethodUnit >( "testFunc1", "void", 0 ),
        ClassUnit::PUBLIC
        );
    myClass.add(
        std::make_shared< MethodUnit >( "testFunc2", "void", MethodUnit::STATIC ),
        ClassUnit::PRIVATE
        );
    myClass.add(
        std::make_shared< MethodUnit >( "testFunc3", "void", MethodUnit::VIRTUAL | MethodUnit::CONST ),
        ClassUnit::PUBLIC
        );

    // Создаем метод с оператором печати и добавляем его в класс
    auto method = std::make_shared< MethodUnit >( "testFunc4", "void", MethodUnit::STATIC );
    method->add( std::make_shared< PrintOperatorUnit >( R"(Hello, world!\n)" ) );
    myClass.add( method, ClassUnit::PROTECTED );

    // Генерируем и возвращаем код класса
    return myClass.compile(generator);
}

#endif // GENERATOR_H
