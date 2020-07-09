#include <iostream>
#include <random>

void genknuth(int m, int n) {
  std::mt19937_64 mt;
  std::random_device rnd;
  mt.seed(rnd());

  for (int i = 0; i < n; i++) {
    if ((mt() % (n - i)) < m) {
      //std::cout << i << std::endl;
      m--;
    }
  }
}

int main(int argc, char** argv) {

  if(argc != 3) {
    std::cout << "wrong number of arguments" << std::endl;
    return 0;
  }

  int m = std::atoi(argv[1]);
  int n = std::atoi(argv[2]);

  if(m > n) {
    std::swap(m, n);
  }

  genknuth(m, n);

  return 0;
}
