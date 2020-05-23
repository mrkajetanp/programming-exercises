class WordCount {
  Map<String, int> countWords(String input) {
    Map<String, int> result = {};

    RegExp(r"((?:\w|['-]\w)+)").allMatches(input)
    .forEach((Match it) {
        String word = it.group(0).toLowerCase();
        if (word.startsWith("'"))
            word = word.substring(1);

        if (result.containsKey(word))
            result[word] = result[word]+1;
        else
          result[word] = 1;
    });

    return result;
  }
}
