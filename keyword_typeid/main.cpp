#include <iostream>
#include <map>
#include <string>
#include <typeinfo>
using std::string;
using std::map;
using std::cout;
using std::endl;

class Persion {
};
class Student : public Persion {
};

int main(int argc, char const *argv[]) {
    int a = 0;
    Persion p;
    Student s;
    map<string, float> coll;
    cout << "typeid(Studnet): " << typeid(s).name() << endl;
    cout << "typeid(Persion): " << typeid(p).name() << endl;
    cout << "typeid(int): " << typeid(a).name() << endl;
    cout << "typeid(map<string, float>): " << typeid(coll).name() << endl;
    return 0;
}
