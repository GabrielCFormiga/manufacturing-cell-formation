#include "instance.hpp"

#include <fstream>
#include <iomanip>
#include <iostream>

Instance::Instance(std::filesystem::path &instance_file_path) : m_num_parts(0), m_num_machines(0), m_n1(0) {
    std::ifstream file(instance_file_path);
    if (!file.is_open()) {
        throw std::runtime_error("Failed to open instance file");
    }

    std::getline(file, m_name);
    
    std::string line;

    do {
        std::getline(file, line);
    } while (!line.empty());

    file >> m_num_machines >> m_num_parts;

    file.ignore();

    m_matrix.resize(m_num_machines * m_num_parts, false);

    size_t part = 0;
    for (size_t i = 0; i < m_num_machines; ++i) {
        std::getline(file, line);
        
        for (size_t j = 2; j < line.size(); j += 2) {
            part = line[j] - '0';
            part--;
            m_matrix[(part * m_num_machines) + i] = true;
            m_n1++;
        }
    }
    
    file.close();
}

void Instance::print() const {
    std::cout << "Instance: " << m_name << "\n";
    std::cout << "Number of parts: " << m_num_parts << "\n";
    std::cout << "Number of machines: " << m_num_machines << "\n";
    std::cout << "Total number of 1's in matrix: " << m_n1 << "\n";
    std::cout << "Utilization matrix:\n";

    for (size_t i = 0; i < m_num_parts; ++i) {
        for (size_t j = 0; j < m_num_machines; ++j) {
            std::cout << std::setw(2) << (get_utilization(i, j) ? '1' : '0') << " ";
        }
        std::cout << "\n";
    }
}