
class Raindrops {
    convert(x: number): string {
        let result = "";

        if (x % 3 == 0)
            result += "Pling";

        if (x % 5 == 0)
            result += "Plang";

        if (x % 7 == 0)
            result += "Plong";

        if (result.length == 0)
            result += x.toString(10);

        return result;
    }
}

export default Raindrops
