#include "print_operator_unit.h"

std::string CppPrintOperatorUnit::compile(unsigned int level, std::string access) const
{
    Q_UNUSED(access)
    return generateShift(level) + "printf(\"" + m_text+"\");\n";
}

std::string CsPrintOperatorUnit::compile(unsigned int level, std::string access) const
{
    Q_UNUSED(access)
    return generateShift( level ) + "Console.WriteLine( \"" + m_text + "\" );\n";
}

std::string JavaPrintOperatorUnit::compile(unsigned int level, std::string access) const
{
    Q_UNUSED(access)
    return generateShift( level ) + "System.out.println( \"" + m_text + "\" );\n";
}
