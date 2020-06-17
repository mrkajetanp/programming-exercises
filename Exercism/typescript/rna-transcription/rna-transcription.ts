
class Transcriptor {
    toRna(dna: string): string {
        var rnas: { [val: string]: string } = {
            "C": "G",
            "G": "C",
            "T": "A",
            "A": "U",
        };

        var transcribe = (s: string) => {
            if (s in rnas)
                return rnas[s];
            throw Error('Invalid input DNA.');
        };

      // throw Error("At least two colors need to be present");
        return dna.split("").map(transcribe).join("");
    }
}

export default Transcriptor
