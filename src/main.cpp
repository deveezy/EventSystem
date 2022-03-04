#include <cstdint>
#include <functional>
#include <iostream>
#include <string>

class Demo {
public:
  Demo() = default;
  Demo(const Demo &demo) { std::cout << "copy ctor\n"; }
  Demo(Demo &&demo) { std::cout << "move ctor\n"; }

  Demo &operator=(const Demo &demo) {
    std::cout << "copy assignment";
    return *this;
  }
  Demo &operator=(Demo &&demo) {
    std::cout << "move assignment";
    return *this;
  }
};

void Pass(Demo _demo) { 
	Demo demo = std::move(_demo); 
}

int main() {
  std::cout << "Start\n";
  Pass(Demo {});
  return 0;
}