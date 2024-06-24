#ifndef CLASS_UNIT_H
#define CLASS_UNIT_H

#include "unit.h"
#include "code_generator.h"

// Класс для представления класса в генерируемом коде
class ClassUnit : public Unit
{
public:
    // Модификаторы доступа для членов класса
    enum AccessModifier {
        PUBLIC,
        PROTECTED,
        PRIVATE
    };
    static const std::vector< std::string > ACCESS_MODIFIERS;
public:
    explicit ClassUnit( const std::string& name ) : m_name( name ) {
        m_fields.resize( ACCESS_MODIFIERS.size() );
    }

    // Метод для добавления членов класса
    void add( const std::shared_ptr< Unit >& unit, Flags flags ) {
        int accessModifier = PRIVATE;
        if( flags < ACCESS_MODIFIERS.size() ) {
            accessModifier = flags;
        }
        m_fields[ accessModifier ].push_back( unit );
    }

    // Метод для генерации кода класса
    std::string compile( const CodeGenerator& generator, unsigned int level = 0 ) const {
        std::string result = generateShift( level ) + generator.generateClass(m_name);

        for( size_t i = 0; i < ACCESS_MODIFIERS.size(); ++i ) {
            if( m_fields[ i ].empty() ) {
                continue;
            }
            result += ACCESS_MODIFIERS[ i ] + ":\n";
            for( const auto& f : m_fields[ i ] ) {
                result += f->compile(generator, level + 1);
            }
            result += "\n";
        }
        result += generateShift( level ) + "};\n";
        return result;
    }
private:
    std::string m_name;
    using Fields = std::vector< std::shared_ptr< Unit > >;
    std::vector< Fields > m_fields;
};
const std::vector< std::string > ClassUnit::ACCESS_MODIFIERS = { "public",
                                                              "protected", "private" };

#endif // CLASS_UNIT_H
