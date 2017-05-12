import java.util.HashMap;

/**
 * Created by cajetan on 5/10/17.
 */

public class Scrabble {
    private String input;
    private HashMap<Character, Integer> scores;

    public Scrabble(String input) {
        this.input = input;
        scores = new HashMap<>();

        scores.put('a', 1);
        scores.put('e', 1);
        scores.put('i', 1);
        scores.put('o', 1);
        scores.put('u', 1);
        scores.put('l', 1);
        scores.put('n', 1);
        scores.put('r', 1);
        scores.put('s', 1);
        scores.put('t', 1);
        scores.put('d', 2);
        scores.put('g', 2);
        scores.put('b', 3);
        scores.put('c', 3);
        scores.put('m', 3);
        scores.put('p', 3);
        scores.put('f', 4);
        scores.put('h', 4);
        scores.put('v', 4);
        scores.put('w', 4);
        scores.put('y', 4);
        scores.put('k', 5);
        scores.put('j', 8);
        scores.put('x', 8);
        scores.put('q', 10);
        scores.put('z', 10);
    }

    public int getScore() {
        int result = 0;

        if (input == null)
            return 0;

        for (char c : input.toLowerCase().toCharArray()) {
            if (Character.isAlphabetic(c))
                result += scores.get(c);
        }

        return result;
    }
}
