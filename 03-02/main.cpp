#include <iostream>
#include "Min.h"

int main() {
  Min<int, int> m1;
  Min<int, float> m2;
  Min<int, double> m3;
  Min<float, float> m4;
  Min<float, double> m5;
  Min<double, double> m6;

  std::cout << "Min(int, int)       = " << m1.MinValue(3, 5) << std::endl;
  std::cout << "Min(int, float)     = " << m2.MinValue(3, 5.5f) << std::endl;
  std::cout << "Min(int, double)    = " << m3.MinValue(3, 5.55) << std::endl;
  std::cout << "Min(float, float)   = " << m4.MinValue(3.3f, 5.5f) << std::endl;
  std::cout << "Min(float, double)  = " << m5.MinValue(3.3f, 5.55) << std::endl;
  std::cout << "Min(double, double) = " << m6.MinValue(3.33, 5.55) << std::endl;

  return 0;
}
