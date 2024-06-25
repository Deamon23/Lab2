#ifndef PRINT_OPERATOR_UNIT_H
#define PRINT_OPERATOR_UNIT_H

#include "unit.h"

class PrintOperatorUnit : public Unit
{
public:
    explicit PrintOperatorUnit( const std::string& text ) : m_text( text ) { }
protected:
    std::string m_text;
};

class CppPrintOperatorUnit : public PrintOperatorUnit
{
public:
    explicit CppPrintOperatorUnit(const std::string& text) : PrintOperatorUnit( text ) { }
    std::string compile( unsigned int level = 0, std::string access = "" ) const override;
};

class CsPrintOperatorUnit : public PrintOperatorUnit
{
public:
    explicit CsPrintOperatorUnit( const std::string& text ) : PrintOperatorUnit( text ) { }
    std::string compile( unsigned int level = 0, std::string access = "" ) const override;
};

class JavaPrintOperatorUnit : public PrintOperatorUnit
{
public:
    explicit JavaPrintOperatorUnit( const std::string& text ) : PrintOperatorUnit( text ) { }
    std::string compile( unsigned int level = 0, std::string access = "" ) const override;
};

#endif // PRINT_OPERATOR_UNIT_H
