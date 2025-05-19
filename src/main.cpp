#include <iostream>
#include "instance.hpp"
#include "solution.hpp"
#include "MCF.hpp"

int main(int argc, char *argv[]) {
    std::filesystem::path instance_file_path = argv[1];
    
    Instance instance(instance_file_path);

    instance.print();

    MCF mcf(instance);

    Solution solution(instance);

    return 0;
}
