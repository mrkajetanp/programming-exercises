class Triangle {
  bool equilateral(double a, double b, double c) {
    return a == b && b == c;
  }

  bool isosceles(double a, double b, double c) {
    return a == b || b == c || a == c;
  }

  bool scalene(double a, double b, double c) {
    return a != b && b != c && a != c;
  }
}
