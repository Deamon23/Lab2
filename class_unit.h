#ifndef CLASS_UNIT_H
#define CLASS_UNIT_H

#include "unit.h"

class ClassUnit : public Unit
{
public:
    enum AccessModifier {
        PUBLIC,
        PROTECTED,
        PRIVATE,
        PRIVATE_PROTECTED,
        FILE,
        INTERNAL,
        PROTECTED_INTERNAL
    };
    static const std::vector<std::string> ACCESS_MODIFIERS;
    explicit ClassUnit( const std::string& name );

protected:
    std::string m_name;
    using Fields = std::vector< std::shared_ptr< Unit > >;
    std::vector< Fields > m_fields;
};

class CppClassUnit : public ClassUnit
{
public:
    explicit CppClassUnit(const std::string& name) : ClassUnit( name ) {}
    void add(const std::shared_ptr<Unit>& unit, Flags flags) override;
    std::string compile( unsigned int level = 0, std::string access = "" ) const override;
};

class CsClassUnit : public ClassUnit
{
public:
    explicit CsClassUnit(const std::string &name): ClassUnit( name ) {}
    void add(const std::shared_ptr<Unit>& unit, Flags flags) override;
    std::string compile( unsigned int level = 0, std::string access = "" ) const override;
};

class JavaClassUnit : public ClassUnit
{
public:
    explicit JavaClassUnit(const std::string &name) : ClassUnit( name ) {}
    void add(const std::shared_ptr<Unit>& unit, Flags flags) override;
    std::string compile( unsigned int level = 0, std::string access = "" ) const override;
};

#endif // CLASS_UNIT_H
