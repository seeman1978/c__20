#include <fstream>
#include <iostream>
#include <filesystem>
namespace fs = std::filesystem;

int main()
{
    bool bResult = fs::create_directories("sandbox/a/b");   ///可以递归创建目录
    std::ofstream("sandbox/file1.txt");
    std::ofstream("sandbox/file2.txt");
    for(auto& p: fs::directory_iterator("sandbox")){    ///不能递归

        auto fs = p.status();
        std::filesystem::file_type ft = fs.type();
        std::cout << p.path() << ".file type:" << static_cast<int>(ft) << '\n';
    }

    /// last_write_time返回值类型std::filesystem::file_time_type
    for(auto& p: fs::recursive_directory_iterator("sandbox")){    ///可以递归
        auto ftime = p.last_write_time();
        std::time_t cftime = decltype(ftime)::clock::to_time_t(ftime);
        std::cout << p.path() << ".last_write_time:" << std::asctime(std::localtime(&cftime));
        if (!p.is_directory()){
            std::cout << ".file size:" << p.file_size() << std::endl;
        }
    }

    fs::remove_all("sandbox");
}