#include <iostream>
#include <string>
#include <set>
#include <functional>
#include <typeinfo>
using std::cout;
using std::endl;
using std::string;
using std::set;

class Persion {
public:
    Persion(const string &name, int age) :
        name(name), age(age) {
    }
    string name;
    int age;
};
int main(int argc, char const *argv[]) {
    auto cmp = [](const Persion &one, const Persion &other) {
        return one.age < other.age;
    };
    std::function<bool(const Persion &, const Persion &)> cmpPersion = cmp;
    cout << "typeid(cmp).name: " << typeid(cmp).name() << endl;
    cout << "typeid(cmpPersion).name: " << typeid(cmpPersion).name() << endl;

    set<Persion, decltype(cmp)> s(cmp);
    set<Persion, decltype(cmpPersion)> s2(cmpPersion);
    for (int i = 0; i < 10; i++) {
        s.emplace("name" + std::to_string(i), 20 + i);
        s2.emplace("name" + std::to_string(i), 20 + i);
    }
    for (auto &i : s) {
        cout << i.name << ": " << i.age << endl;
    }
    for (auto &i : s2) {
        cout << i.name << ": " << i.age << endl;
    }

    return 0;
}
