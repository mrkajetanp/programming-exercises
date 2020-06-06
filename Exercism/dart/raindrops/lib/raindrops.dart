
class Raindrops {
  String convert(int number) {
    var result = StringBuffer();

    if (number % 3 == 0)
      result.write("Pling");

    if (number % 5 == 0)
      result.write("Plang");

    if (number % 7 == 0)
      result.write("Plong");

    if (result.isEmpty)
      result.write(number.toString());

    return result.toString();
  }
}
