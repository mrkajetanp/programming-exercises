//
// This is only a SKELETON file for the 'RNA Transcription' exercise. It's been provided as a
// convenience to get you started writing code faster.
//

export const toRna = (input) => {
  let rnas = {
    "C": "G",
    "G": "C",
    "T": "A",
    "A": "U",
  };

  let transcribe = (s) => {
    if (s in rnas)
      return rnas[s];
  };

  return input.split("").map(transcribe).join("");
};
