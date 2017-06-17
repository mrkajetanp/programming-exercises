public class BeerSong {
    public String verse(int x) {
        switch (x) {
            case 0:
                return "No more bottles of beer on the wall, no more bottles of beer.\n" +
                        "Go to the store and buy some more, 99 bottles of beer on the wall.\n\n";

            case 1:
                return "1 bottle of beer on the wall, 1 bottle of beer.\n" +
                        "Take it down and pass it around, no more bottles of beer on the wall.\n\n";

            default:
                return x + " bottles of beer on the wall, " + x + " bottles of beer.\n" +
                        "Take one down and pass it around, " + (x-1) + " bottle" +
                        ((x-1 == 1 ) ? "" : "s") + " of beer on the wall.\n\n";
        }

    }

    public String sing(int from, int to) {
        StringBuilder result = new StringBuilder();

        for (int i = from ; i >= to ; --i) {
            result.append(verse(i));
        }

        return result.toString();
    }

    public String singSong() {
        return sing(99, 0);
    }
}