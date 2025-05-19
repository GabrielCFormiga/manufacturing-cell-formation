#ifndef INSTANCE_HPP
#define INSTANCE_HPP

#include <cstddef>
#include <cstdint>
#include <filesystem>
#include <vector>

class Instance {
private:
    size_t m_num_parts;
    size_t m_num_machines;
    std::vector<bool> m_matrix;
    std::string m_name;
    
public:
    Instance(std::filesystem::path &instance_file_path);

    inline size_t get_num_parts() const { return m_num_parts; }
    inline size_t get_num_machines() const { return m_num_machines; }
    inline bool get_utilization(size_t part, size_t machine) const {
        return m_matrix[(part * m_num_machines) + machine];
    }

    void print() const;
};

#endif