/**
 * Created by cajetan on 6/11/17.
 */
public class Atbash {
    public String encode(String input) {
        StringBuilder result = new StringBuilder();

        input.chars().filter(c -> Character.isAlphabetic(c) || Character.isDigit(c))
                .map(Character::toLowerCase).forEach(c -> {
                    if (Character.isDigit(c)) {
                        result.append(Character.getNumericValue(c));
                    } else {
                        result.append((char)(97 + (26 - (c-97))-1));
                    }
        });

        String temp = result.toString();
        result.setLength(0);

        for (String s : temp.split("(?<=\\G.{5})")) {
            result.append(s);
            result.append(' ');
        }

        result.deleteCharAt(result.length()-1);

        return result.toString();
    }

    public String decode(String input) {
        StringBuilder result = new StringBuilder();

        input.chars().filter(c -> Character.isAlphabetic(c) || Character.isDigit(c))
                .map(Character::toLowerCase).forEach(c -> {
                    if (Character.isDigit(c)) {
                        result.append(Character.getNumericValue(c));
                    } else {
                        result.append((char)(97 + (26 - (c-97))-1));
                    }
        });

        return result.toString();
    }
}
