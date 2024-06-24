#ifndef PRINT_OPERATOR_UNIT_H
#define PRINT_OPERATOR_UNIT_H

#include "unit.h"
#include "code_generator.h"

// Класс для представления оператора печати в генерируемом коде
class PrintOperatorUnit : public Unit {
public:
    explicit PrintOperatorUnit( const std::string& text ) : m_text( text ) { }

    // Метод для генерации кода оператора печати
    std::string compile( const CodeGenerator& generator, unsigned int level = 0 ) const {
        return generateShift( level ) + generator.generatePrint(m_text);
    }
private:
    std::string m_text;
};

#endif // PRINT_OPERATOR_UNIT_H
