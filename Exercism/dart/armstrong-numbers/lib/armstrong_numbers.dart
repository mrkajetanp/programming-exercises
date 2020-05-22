import 'dart:math';

class ArmstrongNumbers {
  bool isArmstrongNumber(int candidate) {
    String number = candidate.toString();

    int sum = number.split('')
    .fold(0, (int sum, String x) => sum + pow(int.parse(x), number.length) as int);

    return sum == candidate;
  }
}
