class ResistorColorDuo {
    var colors = [
      "black", "brown", "red", "orange", "yellow",
      "green", "blue", "violet", "grey", "white"
    ];

    int value(List<String> resistor) {
      return int.parse(resistor.map(
          (it) => colors.indexOf(it)
        ).take(2).toList().join());
    }
}
