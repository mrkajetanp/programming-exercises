
class Pangram {
  bool isPangram(String input) {
    Set<String> letters = Set();

    input.toLowerCase().split("").forEach((String c) {
      if (c.codeUnitAt(0) >= 97 && c.codeUnitAt(0) <= 122)
        letters.add(c);
    });

    return letters.length == 26;
  }
}
