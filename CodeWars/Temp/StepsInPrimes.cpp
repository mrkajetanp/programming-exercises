#include <iostream>
#include <utility>
#include <math.h>

class StepInPrimes {
public:
  static bool isPrime(int number);
  static std::pair <long long, long long> step(int g, long long m, long long n);
};

std::pair <long long, long long> StepInPrimes::step(int g, long long m, long long n) {
  while (m < n) {
    if(isPrime(m) && isPrime(m+g))  return std::make_pair(m, m+g);
    m++;
  }
  return std::make_pair(0,0);
}

bool StepInPrimes::isPrime(int n) {
  int i;
  if (n == 2) return true;
  if (n%2 == 0) return false;
  for (i = 3 ; i <= sqrt(n) ; i += 2)
    if (n%i == 0)
      return false;
  return true;
}

int main() {
  std::pair <long long, long long> a = StepInPrimes::step(6, 100, 110);
  std::cout << std::get<0>(a) << ", " << std::get<1>(a) << std::endl;

  return 0;
}
