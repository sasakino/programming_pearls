#include <iostream>
#include <map>
#include <array>
#include "../utils.h"

class SevenSegmentDisplay {
public:
  SevenSegmentDisplay() {
    this->segdict[0] = 125;
    this->segdict[1] =  80;
    this->segdict[2] =  55;
    this->segdict[3] =  87;
    this->segdict[4] =  90;
    this->segdict[5] =  79;
    this->segdict[6] = 111;
    this->segdict[7] =  92;
    this->segdict[8] = 127;
    this->segdict[9] =  94;
  }

  ~SevenSegmentDisplay(){}

  std::vector<int> convert(const unsigned short num);

  void show(std::vector<unsigned char> segdata);

private:
  std::map<unsigned char, unsigned char> segdict;
};

std::vector<int> SevenSegmentDisplay::convert(const unsigned short num) {
  std::vector<int> segdata(5);

  int d = 10000; 
  int n = 0, a = 0, _a = 0;

  for(int i = 0; i < 5; i++) {
    a = a;
    a = num / d;
    n = a - _a * 10;
    segdata[i] = segdict[n];
    d = d / 10;
  }

  return segdata;
}

void SevenSegmentDisplay::show(std::vector<unsigned char> segdata) {
  std::array<std::array<bool, 15>, 3> seg;

  return;
}

int main() {

  SevenSegmentDisplay sd;

  std::vector<int> a = sd.convert(12345);

  dump(a);

  return 0;
}

//  _  _  _  _  _ 
// |_||_||_||_||_| 3行15列
// |_||_||_||_||_|
