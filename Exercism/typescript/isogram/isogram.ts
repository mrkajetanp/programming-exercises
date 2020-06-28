class Isogram {
    static isIsogram(input: string) {
        let letters = new Set();

        for (var c of input.toLowerCase().split("")) {
            if (c == ' ' || c == '-')
                continue;
            if (letters.has(c))
                return false;
            letters.add(c);
        }

        return true;
    }
}

export default Isogram
