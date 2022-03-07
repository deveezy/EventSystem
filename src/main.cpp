#include <cstdint>
#include <functional>
#include <iostream>
#include <map>
#include <string>

#include "EventHandler.hpp"

// class Demo {
// public:
//   Demo() = default;
//   Demo(const Demo &demo) { std::cout << "copy ctor\n"; }
//   Demo(Demo &&demo) { std::cout << "move ctor\n"; }

//   Demo &operator=(const Demo &demo) {
//     std::cout << "copy assignment";
//     return *this;
//   }
//   Demo &operator=(Demo &&demo) {
//     std::cout << "move assignment";
//     return *this;
//   }
// };

// void Pass(Demo _demo) {
// 	Demo demo = std::move(_demo);
// }

struct Base {
  void exec() { std::cout << "base\n"; }
};

struct Derived : Base {
  void exec() { std::cout << "der\n"; }
};

void Pass(Base _base) {
  _base.exec();
}

int main() {
  Pass(Derived {});
  return 0;
}