#pragma once
#include <string>

struct Color
{
    private:
    uint32_t m_r;
    uint32_t m_g;
    uint32_t m_b;

    public:
    Color(const uint32_t r, const uint32_t g, const uint32_t b) : m_r(r), m_g(g), m_b(b)
    {
        
    }
};

struct iVec2{
    int x;
    int y;
};

struct Character
{
    std::string _name;
    iVec2 _height;
    Color _hair;
    
};