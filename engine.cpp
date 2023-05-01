#include <iostream>
#include <fstream>
#include <filesystem>
#include <vector>

namespace fs = std::filesystem;

void getFiles(std::filesystem::path rootPath, bool toFile=false)
{
    std::vector<std::filesystem::directory_entry> output;
    std::ofstream outFile;
    if (toFile){
        outFile.open("/home/jan/Repositories/FileBrowserEngine/output.txt");
    }

    for (const auto &entry: std::filesystem::recursive_directory_iterator(rootPath))
    {
        //if (toFile) outFile<< entry.path()<<std::endl;
        output.emplace_back(entry);
    }
    if (toFile){
        outFile.close();
    }
    std::cout<< "Entries: " << output.size()<< std::endl;
}

int main()
{
    std::cout << "File Browser Engine has started" << std::endl;
    for(auto i{0}; i<5; i++)
    {
        auto begin = std::chrono::high_resolution_clock::now();
        getFiles("/home/jan/Repositories/gmat-swx");
        auto end = std::chrono::high_resolution_clock::now();
        std::cout<< std::chrono::duration_cast<std::chrono::milliseconds>(end-begin).count() << "[ms]" << std::endl;
    }
    return 0;
}