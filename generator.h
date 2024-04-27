#ifndef GENERATOR_H
#define GENERATOR_H

#include "cplusplus/classunit.h"
#include "cplusplus/methodunit.h"
#include "cplusplus/printoperatorunit.h"

#include "csharp/classunit.h"
#include "csharp/methodunit.h"
#include "csharp/printoperatorunit.h"

#include "java/classunit.h"
#include "java/methodunit.h"
#include "java/printoperatorunit.h"

std::string generateProgram() {
    ClassUnit myClass( "MyClass" );
    myClass.add(
        std::make_shared< MethodUnit >( "testFunc1", "void", 0 ),
        ClassUnit::PUBLIC
        );
    myClass.add(
        std::make_shared< MethodUnit >( "testFunc2", "void", MethodUnit::STATIC ),
        ClassUnit::PRIVATE
        );
    myClass.add(
        std::make_shared< MethodUnit >( "testFunc3", "void", MethodUnit::VIRTUAL |
                                                              MethodUnit::CONST ),
        ClassUnit::PUBLIC
        );
    auto method = std::make_shared< MethodUnit >( "testFunc4", "void",
                                               MethodUnit::STATIC );
    method->add( std::make_shared< PrintOperatorUnit >( R"(Hello, world!\n)" ) );
    myClass.add( method, ClassUnit::PROTECTED );
    return myClass.compile();
}

#endif // GENERATOR_H
