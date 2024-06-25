#ifndef CODE_FACTORY_H
#define CODE_FACTORY_H

#include <memory>
#include "unit.h"
#include "method_unit.h"
#include "class_unit.h"
#include "print_operator_unit.h"

class CodeFactory
{
public:
    using Flags = unsigned int;

    virtual std::shared_ptr<Unit> CreateClass(const std::string& name) = 0;
    virtual std::shared_ptr<Unit> CreateMethod(const std::string& name, const std::string& returnType, Flags flags) = 0;
    virtual std::shared_ptr<Unit> CreatePrintOperator(const std::string& text) = 0;
    virtual ~CodeFactory() = default;
};

class CppFactory : public CodeFactory
{
public:
    std::shared_ptr<Unit> CreateClass(const std::string& name) {
        return std::make_shared<CppClassUnit>(name);
    }
    std::shared_ptr<Unit> CreateMethod(const std::string& name, const std::string& returnType, Flags flags) {
        return std::make_shared<CppMethodUnit>(name, returnType, flags);
    }
    std::shared_ptr<Unit> CreatePrintOperator(const std::string& text) {
        return std::make_shared<CppPrintOperatorUnit>(text);
    }
};

class CsFactory : public CodeFactory
{
public:
    std::shared_ptr<Unit> CreateClass(const std::string& name) {
        return std::make_shared<CsClassUnit>(name);
    }
    std::shared_ptr<Unit> CreateMethod(const std::string& name, const std::string& returnType, Flags flags) {
        return std::make_shared<CsMethodUnit>(name, returnType, flags);
    }
    std::shared_ptr<Unit> CreatePrintOperator(const std::string& text) {
        return std::make_shared<CsPrintOperatorUnit>(text);
    }
};

class JavaFactory : public CodeFactory
{
public:
    std::shared_ptr<Unit> CreateClass(const std::string& name) {
        return std::make_shared<JavaClassUnit>(name);
    }
    std::shared_ptr<Unit> CreateMethod(const std::string& name, const std::string& returnType, Flags flags) {
        return std::make_shared<JavaMethodUnit>(name, returnType, flags);
    }
    std::shared_ptr<Unit> CreatePrintOperator(const std::string& text) {
        return std::make_shared<JavaPrintOperatorUnit>(text);
    }
};
#endif // CODE_FACTORY_H
