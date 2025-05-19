#ifndef ASP_HPP
#define ASP_HPP

#include <random>
#include <vector>
#include "instance.hpp"

class MCF {
private:
    Instance m_instance;

public:
    MCF(Instance &instance);
};

#endif