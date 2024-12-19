#include <iostream>
#include <fstream>
#include <string>

int    replaceString(std::string fileName, std::string s1, std::string s2)
{
    std::string outputFileName = fileName + ".replace";
    std::string line;

    if (s1.empty())
        return (std::cout << "String that will be replaced cannot be empty!" << std::endl, 0);

    std::ifstream inputFile(fileName.c_str());
    if (!inputFile.is_open())
        return (std::cout << "An error occured while opening input file " << fileName << std::endl, 0);

    std::ofstream outFile(outputFileName.c_str());
    if (!outFile.is_open())
        return (std::cout << "An error occured while creating output file " << outputFileName << std::endl, inputFile.close(), 0);

    while (std::getline(inputFile, line))
    {
        std::size_t pos = 0;
        while ((pos = line.find(s1, pos)) != std::string::npos) //alınan satırda s1 var mı diye kontrol ediyoruz yok ise npos adlı olmadığını gösteren özel bir değişken ile belirtiliyor.
        {
            line.erase(pos, s1.length()); //O satırdaki ve pozisyondaki s1'i s1 uzunluğu kadar siliyoruz.
            line.insert(pos, s2); // s2 yi o pozisyona ekliyoruz.
            pos += s2.length(); // pos'u o uzunluk kadar ilerletiyoruz.
        }
        outFile << line << std::endl;
    }

    inputFile.close();
    outFile.close();
    return (1);
}

int main(int ac, char **av)
{
    if (ac != 4)
        return(std::cout << "Usage: ./replace [filename] [s1] [s2]" << std::endl, 1);
    
    std::string fileName = av[1];
    std::string s1 = av[2];
    std::string s2 = av[3];

    replaceString(fileName, s1, s2);
    return (0);
}