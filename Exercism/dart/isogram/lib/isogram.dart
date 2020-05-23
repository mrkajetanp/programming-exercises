
class Isogram {
  bool isIsogram(String input) {
    var letters = <String>{};
    var result = true;

    input.replaceAll(' ', '').replaceAll('-', '').toLowerCase().split('')
    .forEach((String l) {
        if (letters.contains(l))
          result = false;

        letters.add(l);
    });

    return result;
  }
}
