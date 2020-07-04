
class MatchingBrackets {
  bool isPaired(String input) {
    List<String> brackets = [];

    for (int i = 0 ; i < input.length ; i++) {
      switch (input[i]) {
        case '{': { brackets.add(input[i]); }
        break;
        case '[': { brackets.add(input[i]); }
        break;
        case '(': { brackets.add(input[i]); }
        break;

        case '}': {
          if (brackets.isEmpty || brackets.last != '{')
            return false;
          else
            brackets.removeLast();
        }
        break;
        case ']': {
          if (brackets.isEmpty || brackets.last != '[')
            return false;
          else
            brackets.removeLast();
        }
        break;
        case ')': {
          if (brackets.isEmpty || brackets.last != '(')
            return false;
          else
            brackets.removeLast();
        }
        break;
      }
    }

    return brackets.isEmpty;
  }
}
