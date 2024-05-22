// Задача: Реализирайте обхождане на директории с 
// много нишки, като за всяка поддиректория се пуска отделна нишка. 
// Отпечатайте имената на файловете.

#include <iostream>
#include <thread>
#include <filesystem>
#include <list>
#include <string>

void list_files(const std::string& path)
{
    std::list<std::thread> threads;
    for (auto const& entry : std::filesystem::directory_iterator(path))
    {
        if (entry.is_directory())
        {
            std::cout << entry.path() << "\n";
            threads.push_back(std::thread(list_files, entry.path().string()));
        }
        else
        {
            std::cout << entry.path() << "\n";
        }
    }

    for (auto& thread : threads)
    {
        thread.join();
    }

}

int main()
{
    const std::string path = "D:\\Test";
    list_files(path);
    return 0;
}