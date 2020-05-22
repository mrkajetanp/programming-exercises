
class BeerSong {
  List<String> verse(int number) {
    switch (number) {
      case 0:
        return ['No more bottles of beer on the wall, no more bottles of beer.',
          'Go to the store and buy some more, 99 bottles of beer on the wall.'];

      case 1:
        return ['1 bottle of beer on the wall, 1 bottle of beer.',
        'Take it down and pass it around, no more bottles of beer on the wall.'];

      default:
        return ['$number bottles of beer on the wall, $number bottles of beer.',
          'Take one down and pass it around, ${number-1} bottle${(number == 2) ? "" : "s"} of beer on the wall.'];
    }
  }

  List<String> recite(int from, int count) {
    List<String> result = [];

    for (int i = 0 ; i < count ; i++) {
      result.addAll(verse(from-i));
      result.add('');
    }
    result.removeLast();

    return result;
  }
}
