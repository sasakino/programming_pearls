#include <iostream>
#include <vector>
#include <numeric>

constexpr int ARRAY_SIZE = 100;

int binarySearch(const int t, const std::vector<int> v, int l, int u) {
  if(l < 0 || u >= v.size()) return -1;
  if(l > u) return -1;

  int m = (l + u) / 2;

  if(v[m] < t) l = m + 1;
  else if(v[m] == t) return m;
  else if(v[m] > t) u = m - 1; 

  return binarySearch(t, v, l, u);
}

int main(int argc, char** argv) {
  if(argc != 2) return -1;

  int t = std::atoi(argv[1]);
  if(t >= ARRAY_SIZE) return -1;

  std::vector<int> v(ARRAY_SIZE);
  std::iota(v.begin(), v.end(), 0);

  std::cout << binarySearch(t, v, 0, v.size() - 1) << std::endl;

  return 0;
}
