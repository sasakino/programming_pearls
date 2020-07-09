#include <iostream>
#include <vector>
#include <algorithm>
#include <random>
#include <chrono>
#include "../utils.h"

constexpr int dataSize = 10000000;

std::vector<int> genData(const int num)
{
  std::vector<int> data(num);
  std::iota(data.begin(), data.end(), 0);
  std::random_device rng;
  std::mt19937 engine(rng());
  std::shuffle(data.begin(), data.end(), engine);

  return data;
}

int main()
{
  auto data = genData(dataSize);
  auto dataSize = data.size();
  Timer t;

  auto d1(data);
  t.start();
  std::sort(d1.begin(), d1.end());
  t.stop();
  t.showResult();

  auto d2(data);
  t.start();
  std::vector<bool> binData(dataSize);
  for(auto d : d2)
  {
    binData[d] = 1;
  }
  t.stop();
  t.showResult();
}
