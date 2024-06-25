#ifndef CSHARP_CODE_GENERATOR_H
#define CSHARP_CODE_GENERATOR_H

#include "code_factory.h"

// Класс для генерации кода на C#
class CSharpCodeGenerator : public CodeGenerator {
public:
    std::string generateProgram() const override {
        ClassUnit myClass( "MyClass" );

        myClass.add(
            std::make_shared< MethodUnit >( "TestFunc1", "void", 0 ),
            ClassUnit::PUBLIC
            );
        myClass.add(
            std::make_shared< MethodUnit >( "TestFunc2", "void", MethodUnit::STATIC ),
            ClassUnit::PRIVATE
            );
        myClass.add(
            std::make_shared< MethodUnit >( "TestFunc3", "void", MethodUnit::VIRTUAL | MethodUnit::CONST ),
            ClassUnit::PUBLIC
            );

        auto method = std::make_shared< MethodUnit >( "TestFunc4", "void", MethodUnit::STATIC );
        method->add( std::make_shared< PrintOperatorUnit >( R"(Hello, world!\n)" ) );
        myClass.add( method, ClassUnit::PROTECTED );

        return myClass.compile();
    }
};

#endif // CSHARP_CODE_GENERATOR_H
