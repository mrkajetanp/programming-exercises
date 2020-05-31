
class Acronym {
  String abbreviate(String input) {
    return input.replaceAll("-", " ").split(" ")
    .map((String it) => it[0]).join("").toUpperCase();
  }
}
