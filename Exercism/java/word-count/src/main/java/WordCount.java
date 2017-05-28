import java.util.HashMap;

public class WordCount {

    public HashMap<String, Integer> phrase(String text) {
        HashMap<String, Integer> result = new HashMap<>();

        text = text.chars().
                filter(c -> Character.isAlphabetic(c) ||
                        Character.isWhitespace(c) ||
                        Character.isDigit(c)).
                collect(StringBuilder::new,
                        StringBuilder::appendCodePoint,
                        StringBuilder::append).
                toString();

        for (String word : text.split("\\s+")) {
            word = word.toLowerCase();

            if (result.containsKey(word))
                result.replace(word, result.get(word)+1);
            else
                result.put(word, 1);
        }

        return result;
    }

}
