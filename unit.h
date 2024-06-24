#ifndef UNIT_H
#define UNIT_H

#include <string>
#include <vector>
#include <memory>
#include "code_generator.h"

// Абстрактный базовый класс для всех элементов кода
class Unit {
public:
    using Flags = unsigned int;
public:
    virtual ~Unit() = default;

    // Метод для добавления дочерних элементов (может быть переопределен)
    virtual void add( const std::shared_ptr< Unit >& , Flags ) {
        throw std::runtime_error( "Not supported" );
    }
    // Метод для генерации кода элемента (должен быть переопределен)
    virtual std::string compile( const CodeGenerator& generator, unsigned int level = 0 ) const = 0;
protected:
    // Вспомогательный метод для генерации отступов
    virtual std::string generateShift( unsigned int level ) const
    {
        static const auto DEFAULT_SHIFT = "    "; // Используем 4 пробела для отступа
        std::string result;
        for( unsigned int i = 0; i < level; ++i ) {
            result += DEFAULT_SHIFT;
        }
        return result;
    }
};

#endif // UNIT_H
