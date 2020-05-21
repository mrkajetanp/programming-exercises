
class Leap {
  bool leapYear(int year) {
    var factor = (int x) => year % x == 0;
    return factor(4) && (!factor(100) || factor(400));
  }
}
