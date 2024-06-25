#include "class_unit.h"

const std::vector< std::string > ClassUnit::ACCESS_MODIFIERS = { "public", "protected", "private", "private protected", "file", "internal", "protected internal" };

ClassUnit::ClassUnit(const std::string &name) : m_name( name ) {
    m_fields.resize( ACCESS_MODIFIERS.size() );
}

void CppClassUnit::add(const std::shared_ptr<Unit> &unit, Flags flags) {
    if(unit == nullptr) {
        std::cout << "Out of memory for " << m_name << std::endl;
        return;
    }
    int accessModifier = PRIVATE;
    if( flags < 3 ) {
        accessModifier = flags;
    }
    m_fields[ accessModifier ].push_back( unit );
}

std::string CppClassUnit::compile(unsigned int level, std::string access) const
{
    Q_UNUSED(access)
    std::string result = generateShift( level ) + "class " + m_name + " {\n";
    for( int i = 0; i < 3; ++i ) {
        if( m_fields[ i ].empty() ) {
            continue;
        }
        result += ACCESS_MODIFIERS[ i ] + ":\n";
        for( const auto& f : m_fields[ i ] ) {
            result += f->compile( level + 1 );
        }
        result += "\n";
    }
    result += generateShift( level ) + "};\n";
    return result;
}

void CsClassUnit::add(const std::shared_ptr<Unit> &unit, Flags flags) {
    if(unit == nullptr) {
        std::cout << "Out of memory for " << m_name << std::endl;
        return;
    }
    int accessModifier = PRIVATE;
    if( flags < ACCESS_MODIFIERS.size() ) {
        accessModifier = flags;
    }
    m_fields[ accessModifier ].push_back( unit );
}

std::string CsClassUnit::compile(unsigned int level, std::string access) const
{
    Q_UNUSED(access)
    std::string result = generateShift( level ) + "class " + m_name + " {\n";
    for( size_t i = 0; i < ACCESS_MODIFIERS.size(); ++i ) {
        if( m_fields[ i ].empty() ) {
            continue;
        }

        for( const auto& f : m_fields[ i ] ) {
            result += f->compile( level, ACCESS_MODIFIERS[ i ] );
        }
        result += "\n";
    }
    result += generateShift( level ) + "};\n";
    return result;
}

void JavaClassUnit::add(const std::shared_ptr<Unit> &unit, Flags flags) {
    if(unit == nullptr) {
        std::cout << "Out of memory for " << m_name << std::endl;
        return;
    }
    int accessModifier = INTERNAL;
    if( flags < 3 ) {
        accessModifier = flags;
    }
    m_fields[ accessModifier ].push_back( unit );
}

std::string JavaClassUnit::compile(unsigned int level, std::string access) const
{
    Q_UNUSED(access)
    std::string result = generateShift( level ) + "class " + m_name + " {\n";
    for( int i = 0; i < 3; ++i ) {
        if( m_fields[ i ].empty() ) {
            continue;
        }

        for( const auto& f : m_fields[ i ] ) {
            result += f->compile( level, ACCESS_MODIFIERS[ i ] );
        }
        result += "\n";
    }
    for( const auto& f : m_fields[ INTERNAL ] ) {
        result += f->compile( level );
    }
    result += "\n";
    result += generateShift( level ) + "};\n";
    return result;
}
