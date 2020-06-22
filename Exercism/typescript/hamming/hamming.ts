
class Hamming {
    compute(a: string, b: string): number {
        if (a.length != b.length)
            throw Error('DNA strands must be of equal length.');

        var result: number = 0;

        [...a].forEach((c, i) => {
            if (c != b[i])
                result++;
        });

        return result;
    }
}

export default Hamming
