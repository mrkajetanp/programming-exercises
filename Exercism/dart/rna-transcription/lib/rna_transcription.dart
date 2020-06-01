
class RnaTranscription {
  var rna = {
    'C': 'G',
    'G': 'C',
    'T': 'A',
    'A': 'U',
  };

  String toRna(String input) {
    return input.split("").map((String s) => rna[s]).join("");
  }
}
