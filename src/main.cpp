#include <iostream>
#include "instance.hpp"

int main(int argc, char *argv[]) {
    std::filesystem::path instance_file_path = argv[1];
    
    Instance instance(instance_file_path);

    instance.print();

    return 0;
}
