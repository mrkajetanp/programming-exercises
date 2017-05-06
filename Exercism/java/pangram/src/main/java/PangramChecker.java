import java.util.HashSet;

public class PangramChecker {

    public boolean isPangram(String input) {

        HashSet<Character> letters = new HashSet<>();

        for (char c : input.toLowerCase().toCharArray()) {
            if (Character.isAlphabetic(c) && c >= 'a' && c <= 'z')
                letters.add(c);
        }

        return letters.size() == 26;
    }
}
