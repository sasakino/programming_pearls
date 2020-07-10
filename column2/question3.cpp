#include <iostream>
#include <numeric>
#include <vector>
#include "../utils.h"

void rotate(std::vector<int>& v, const int n, const int i) {

  int t = v[0];

  int dst = 0;

  int k = 0;
  int src = k++ * i;

  while(1) {
    std::swap(v[dst], v[src]);

    dst = src;
    int buf = k++ * i;
    int mod = buf % n;
    if(mod == 0) break;
    src = mod > 0 ? mod : buf;
  }

  v[src] = t;
}

int main(int argc, char** argv) {

  if(argc != 3) {
    std::cout << "error: wrong number of arguments" << std::endl;
    return 0;
  }

  const int n = std::atoi(argv[1]);
  const int i = std::atoi(argv[2]);

  if(n < i) {
    std::cout << "error: n < i" << std::endl;
    return 0;
  }

  std::vector<int> v(n);

  std::iota(v.begin(), v.end(), 0);

  rotate(v, n, i);

  dump(v);

  return 0;
}
