#include <iostream>
#include <cstdlib>
#include <vector>
#include "../utils.h"

std::vector<int> fibo(const int n) {
  std::vector<int> v(n);
  for(int i = 0; i < n; i++) {
    if(i <= 1) v[i] = 1;
    else v[i] = v[i-1] + v[i-2];
  }
  return v;
}

int main(int argc, char** argv) {

  if(argc != 2) return 0;

  const int n = std::atoi(argv[1]);

  std::vector<int> v = fibo(n);

  dump(v);

  return 0;
}
