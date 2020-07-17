#include <iostream>
#include <map>
#include <array>
#include "../utils.h"

std::vector<int> convert(const unsigned short num, std::map<unsigned char, unsigned char> segdict) {
  std::vector<int> segdata(5);

  unsigned short digit = 10000;
  unsigned short idx = 0;

  for(int i = 0; i < 5; i++) {
    idx = num / digit - idx * digit;
    std::cout << idx << std::endl;
    int n = segdict[idx];

    segdata[i] = n;

    digit/=10;
  }

  return segdata;
}

void show(std::vector<unsigned char> segdata) {
  std::array<std::array<bool, 15>, 3> seg;

  return;
}

int main() {

  std::map<unsigned char, unsigned char> segdict;
  segdict[0] = 125;
  segdict[1] =  80;
  segdict[2] =  55;
  segdict[3] =  87;
  segdict[4] =  90;
  segdict[5] =  79;
  segdict[6] = 111;
  segdict[7] =  92;
  segdict[8] = 127;
  segdict[9] =  94;

  std::vector<int> a = convert(12345, segdict);

  dump(a);

  return 0;
}

//  _  _  _  _  _ 
// |_||_||_||_||_| 3行15列
// |_||_||_||_||_|
