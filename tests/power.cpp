#include <iostream>
#include <ostream>
template <typename T> constexpr T calculatePower(T value, unsigned power) {
  return power == 0 ? 1 : value * calculatePower(value, power - 1);
}

void useExample() {
  constexpr int compileTimeCalculated = calculatePower(5, 10); // computes at compile time,  
  std::cout << compileTimeCalculated <<std::endl; 
  // as both arguments are known at compilation time
  // and used for a constant expression.
  int value;
  std::cin >> value;
  int runtimeCalculated = calculatePower(value, 10); // runtime calculated,
  std::cout<< runtimeCalculated <<std::endl;
  // because value is known only at runtime.
}
int main(int argc, char* argv[], char* envp[]) {
  int n=2;
  useExample();
  /* std::cout<<(int(10) * ... * int(10+n)); */

  for (int i = 0; envp[i] != nullptr; ++i) {
        std::cout << "Environment Variable: " << envp[i] << std::endl;
    }
  std::cout<<getenv("PATH")<<std::endl;
    return 0;
}
/* Version ≥ C++17 */
