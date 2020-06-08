
class PhoneNumber {
  String clean(String input) {
    for (int i = 0 ; i < input.length ; i++) {
      if ("0123456789+ ()-.".contains(input[i])) {
        continue;
      }

      if (input.codeUnitAt(i) >= 97 && input.codeUnitAt(i) <= 122) {
        throw FormatException('letters not permitted');
      }

      throw FormatException('punctuations not permitted');
    }

    var number =  input.split("").where(
      (String c) => (double.tryParse(c) != null)
    ).join("").toString();

    if (number.length == 9) {
      throw FormatException('incorrect number of digits');
    }

    if (number.length > 11) {
      throw FormatException('more than 11 digits');
    }

    if (number.length == 11) {
      if (!number.startsWith("1")) {
        throw FormatException('11 digits must start with 1');
      }
      number = number.substring(1);
    }

    if (number.startsWith("0")) {
      throw FormatException('area code cannot start with zero');
    }

    if (number.startsWith("1")) {
      throw FormatException('area code cannot start with one');
    }

    if (number[3] == "0") {
      throw FormatException('exchange code cannot start with zero');
    }

    if (number[3] == "1") {
      throw FormatException('exchange code cannot start with one');
    }

    return number;
  }
}
