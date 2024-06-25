#ifndef METHOD_UNIT_H
#define METHOD_UNIT_H

#include "unit.h"

class MethodUnit : public Unit
{
public:
    enum Modifier{
        STATIC = 1,
        CONST = 1 << 1,
        VIRTUAL = 1 << 2,
        FINAL = 1 << 3,
        ABSTRACT = 1 << 4
    };
    MethodUnit( const std::string& name, const std::string& returnType, Flags flags ) :
        m_name( name ), m_returnType( returnType ), m_flags( flags ) { }
    void add( const std::shared_ptr< Unit >& unit, Flags /* flags */ = 0 ) {
        if(unit == nullptr) {
            std::cout << "Out of memory for " << m_name << std::endl;
            return;
        }
        m_body.push_back( unit );
    }
protected:
    std::string m_name;
    std::string m_returnType;
    Flags m_flags;
    std::vector<std::shared_ptr<Unit>> m_body;
};

class CppMethodUnit : public MethodUnit
{
public:
    CppMethodUnit(const std::string& name, const std::string& returnType, Flags flags) : MethodUnit(name, returnType, flags) {}
    std::string compile( unsigned int level = 0, std::string access = "" ) const override;
};

class CsMethodUnit : public MethodUnit
{
public:
    CsMethodUnit(const std::string& name, const std::string& returnType, Flags flags) : MethodUnit(name, returnType, flags) {}
    std::string compile( unsigned int level = 0, std::string access = "" ) const override;
};

class JavaMethodUnit : public MethodUnit
{
public:
    JavaMethodUnit(const std::string& name, const std::string& returnType, Flags flags) : MethodUnit(name, returnType, flags) {}
    std::string compile( unsigned int level = 0, std::string access = "" ) const override;
};

#endif // METHOD_UNIT_H
