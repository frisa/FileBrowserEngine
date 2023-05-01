#include <iostream>
#include <fstream>
#include <filesystem>
#include <vector>

inline void getFilesFast(std::filesystem::path rootPath)
{
    std::vector<std::filesystem::directory_entry> output;
    for (const auto &entry : std::filesystem::recursive_directory_iterator(rootPath))
    {
        // if (toFile) outFile<< entry.path()<<std::endl;
        output.emplace_back(entry);
    }
    std::cout << "Entries: " << output.size() << " ";
}

int main()
{
    std::cout << "File Browser Engine has started" << std::endl;
    const unsigned int count{10};
    std::chrono::time_point<std::chrono::system_clock> begin;
    std::chrono::time_point<std::chrono::system_clock> end;
    uint64_t duration{0};
    uint64_t sum{0};

    for (auto i{0}; i < count; i++)
    {
        begin = std::chrono::high_resolution_clock::now();
        getFilesFast("/home/jan/Repositories/gmat-swx");
        end = std::chrono::high_resolution_clock::now();
        duration = std::chrono::duration_cast<std::chrono::milliseconds>(end - begin).count();
        std::cout << "Duration: " << duration << std::endl;
        sum += duration;
    }

    double average_duration = sum / count;
    std::cout << "Average Duration: " << average_duration << std::endl;
    return 0;
}