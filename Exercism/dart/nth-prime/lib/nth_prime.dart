import 'dart:math';

class NthPrime {
  int prime(int num) {
    if (num < 1) {
      throw ArgumentError("There is no zeroth prime");
    }

    int counter = 0;
    int last_prime = 2;
    int idx = 2;

    while (counter != num) {
      if (isPrime(idx)) {
        last_prime = idx;
        counter += 1;
      }
      idx += 1;
    }

    return last_prime;
  }

  bool isPrime(int num) {
    if (num == 2 || num == 3)
      return true;

    if (num%2 == 0)
      return false;

    for (int i = 3 ; i <= sqrt(num).round() ; i += 2) {
      if (num%i == 0)
        return false;
    }

    return true;
  }
}
