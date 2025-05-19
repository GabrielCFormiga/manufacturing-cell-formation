#include "solution.hpp"
#include "instance.hpp"

#include <cassert>
#include <cmath>
#include <cstddef>
#include <iostream>
#include <unordered_set>

Solution::Solution(const Instance &instance) {
    parts.resize(instance.get_num_parts());
    machines.resize(instance.get_num_machines());
    clusters.resize(1);
    clusters[0] = {instance.get_num_parts(), instance.get_num_machines()};
    objective = 0.0f;
}

