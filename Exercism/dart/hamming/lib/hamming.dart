
class Hamming {
  int distance(String a, String b) {
    if ((a.isEmpty && !b.isEmpty) || (!a.isEmpty && b.isEmpty)) {
      throw ArgumentError("no strand must be empty");
    }

    if (a.length != b.length) {
      throw ArgumentError("left and right strands must be of equal length");
    }


    int result = 0;
    for (int i = 0 ; i < a.length ; i++) {
      if (a[i] != b[i]) {
        result++;
      }
    }

    return result;
  }
}
