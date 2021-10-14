#include <iostream>
#include <map>
#include <string>
#include <fstream>
#include <memory>
#include <cstdio>
using std::string;
using std::map;
using std::cout;
using std::endl;

void close_file(std::FILE *file) {
    std::fclose(file);
    std::cout << "auto close" << std::endl;
}

int main(int argc, char const *argv[]) {
    int a = 0;
    map<string, float> coll;
    coll.emplace("pi", 3.14);
    for (map<string, float>::value_type item : coll) {
        // decltype(coll)::value_type item = i;
        cout << item.first << " : " << item.second << endl;
    }

    decltype(coll)::value_type elem2;
    decltype(a) b;
    b = 10;

    std::ofstream("demo.txt") << 'x';
    {
        using unique_file_t = std::unique_ptr<std::FILE, decltype(&close_file)>;
        unique_file_t fp(std::fopen("demo.txt", "r"), &close_file);
        if (fp)
            std::cout << char(std::fgetc(fp.get())) << std::endl;
    }
    return 0;
}
