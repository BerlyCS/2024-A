#include <chrono>
#include <future>
#include <iostream>
#include <thread>
unsigned int square(unsigned int i) { 
  std::cout<<"running"<<std::endl;
  std::this_thread::sleep_for(std::chrono::seconds(1));
  return i * i; 
}

int main() {
  std::cout << "square currently running\n"; // do something while square is running
  std::cout << "result is " << (std::async(std::launch::async, square, 8)).get() << '\n'; // getting the result from square
}
