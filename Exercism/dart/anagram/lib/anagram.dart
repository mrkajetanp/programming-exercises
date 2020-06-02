
class Anagram {
  bool isAnagram(String word, String input) {
    word = word.toLowerCase();
    input = input.toLowerCase();

    if (word == input)
      return false;

    List<String> a = word.split("");
    a.sort();
    List<String> b = input.split("");
    b.sort();

    return a.join() == b.join();
  }

  List<String> findAnagrams(String word, List<String> input) {
    return input.where((String s) => isAnagram(s, word)).toList();
  }
}
