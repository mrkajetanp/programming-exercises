import 'dart:math';

class PrimeFactors {
  bool isPrime(int x) {
    if (x == 2 || x == 3) {
        return true;
    }

    if (x%2 == 0) {
      return false;
    }

    for (int i = 3 ; i < sqrt(x)+1 ; i += 2) {
      if (x%i == 0) {
        return false;
      }
    }

    return true;
  }

  List<int> factors(int n) {
    if (n == 1) {
      return [];
    }

    if (isPrime(n)) {
      return [n];
    }

    List<int> result = [];

    while (!isPrime(n)) {
      int i = 2;

      // Find smallest prime factor of n
      while (!(n%i == 0 && isPrime(i))) {
        i++;
      }

      // Add to factors, divide n by found factor
      result.add(i);
      n ~/= i;
    }

    if (isPrime(n) && n != 1) {
      result.add(n);
    }

    return result;
  }
}
