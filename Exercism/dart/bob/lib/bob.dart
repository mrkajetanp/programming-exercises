
class Bob {
  String response(String input) {
    input = input.trim();

    if (input.isEmpty)
      return "Fine. Be that way!";

    // No lowercase letters
    if (RegExp(r"([a-z])").allMatches(input).isEmpty) {
      // No uppercase letters
      if (RegExp(r"([A-Z])").allMatches(input).isEmpty) {
        // No letters at all
        if (input.endsWith("?"))
          return "Sure.";
        return "Whatever.";
      }

      // Only uppercase letters
      if (input.endsWith("?"))
        return "Calm down, I know what I\'m doing!";
      return "Whoa, chill out!";
    }

    if (input.endsWith("?"))
      return "Sure.";
    return "Whatever.";
  }
}
