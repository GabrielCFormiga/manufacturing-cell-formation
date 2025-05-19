#ifndef SOLUTION_HPP
#define SOLUTION_HPP

#include <cstdint>
#include <vector>

#include "instance.hpp"

struct Solution {
    std::vector<std::pair<uint32_t, uint32_t>> clusters; 
    std::vector<uint32_t> parts;
    std::vector<uint32_t> machines;
    float objective;

    Solution() = default;

    Solution(const Instance &instance);

    void print() const;
};

#endif