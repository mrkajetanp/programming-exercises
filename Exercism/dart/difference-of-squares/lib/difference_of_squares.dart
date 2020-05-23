import 'dart:math';

class DifferenceOfSquares {
  int squareOfSum(int x) {
    int sum = 0;

    for (int i = 1 ; i <= x ; i++) {
      sum += i;
    }

    return pow(sum, 2) as int;
  }

  int sumOfSquares(int x) {
    int sum = 0;

    for (int i = 1 ; i <= x ; i++) {
      sum += pow(i, 2) as int;
    }

    return sum;
  }

  int differenceOfSquares(int x) {
    return squareOfSum(x) - sumOfSquares(x);
  }
}
