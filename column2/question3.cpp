#include <iostream>
#include <numeric>
#include <vector>
#include "../utils.h"

void rotate(std::vector<int>& v, const int i) {
  const int n = v.size();

  for(int cnt = 0; cnt < std::gcd(i, n); cnt++) {
    int t = v[cnt];
    int dst = cnt;

    while(1) {
      int src = dst + i; 
      if (src >= n) src = src % n;
      if (src == cnt) break;
      v[dst] = v[src];
      dst = src;
    }

    v[dst] = t;
  }
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

  rotate(v, i);

  dump(v);

  return 0;
}
