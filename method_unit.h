#ifndef METHOD_UNIT_H
#define METHOD_UNIT_H

#include "unit.h"
#include "code_generator.h"

// Класс для представления метода в генерируемом коде
class MethodUnit : public Unit {
public:
    // Модификаторы для методов
    enum Modifier {
        STATIC = 1,
        CONST = 1 << 1,
        VIRTUAL = 1 << 2
    };
public:
    MethodUnit( const std::string& name, const std::string& returnType, Flags flags ) :
        m_name( name ), m_returnType( returnType ), m_flags( flags ) { }

    // Метод для добавления операторов в тело метода
    void add( const std::shared_ptr< Unit >& unit, Flags /* flags */ = 0 ) {
        m_body.push_back( unit );
    }

    // Метод для генерации кода метода
    std::string compile( const CodeGenerator& generator, unsigned int level = 0 ) const {
        std::string result = generateShift( level );
        result += generator.generateMethod(m_name, m_returnType, m_flags);
        for( const auto& b : m_body ) {
            result += b->compile( generator, level + 1 );
        }
        result += generateShift( level ) + "}\n";
        return result;
    }
private:
    std::string m_name;
    std::string m_returnType;
    Flags m_flags;
    std::vector< std::shared_ptr< Unit > > m_body;
};

#endif // METHOD_UNIT_H
