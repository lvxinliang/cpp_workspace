#include <iostream>
#include <map>
#include <string>
using std::string;
using std::map;
using std::cout;
using std::endl;

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
    return 0;
}
