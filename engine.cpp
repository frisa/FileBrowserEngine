#include <iostream>
#include <filesystem>

namespace fs = std::filesystem;

void getFiles(std::filesystem::path rootPath)
{
    for (const auto &entry : std::filesystem::directory_iterator(rootPath))
    {
        std::cout << entry.path() << std::endl;
    }
}

int main()
{
    std::cout << "File Browser Engine has started" << std::endl;
    getFiles("/");
    return 0;
}