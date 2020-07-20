#include <iostream>
#include <vector>
#include <array>
#include <chrono>

template <typename T>
void dump(std::vector<T> &data) 
{
  for(auto d : data)
  {
    std::cout << d << " ";
  }

  std::cout << std::endl;
}

template <typename T, unsigned int U>
void dump(std::array<T, U> &data) 
{
  for(auto d : data)
  {
    std::cout << d << " ";
  }

  std::cout << std::endl;
}

class Timer
{
  public:
    Timer(){}
    ~Timer(){}

    void start()
    {
      this->s = std::chrono::system_clock::now();
    }

    void stop()
    {
      this->e = std::chrono::system_clock::now();
    }

    void showResult() {
      auto dur = this->e - this->s;
      auto msec = std::chrono::duration_cast<std::chrono::milliseconds>(dur);
      std::cout << msec.count() << " ms" << std::endl;
    }

 private:
    std::chrono::system_clock::time_point s;
    std::chrono::system_clock::time_point e;
};
