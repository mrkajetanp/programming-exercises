import java.util.HashSet;

/**
 * Created by cajetan on 5/22/17.
 */
public class IsogramChecker {
    private HashSet<Character> letters;

    public IsogramChecker() {
        letters = new HashSet<>();
    }

    public boolean isIsogram(String text) {
        letters.clear();

        for (char c : text.toCharArray()) {
            if (!Character.isAlphabetic(c))
                continue;

            if (letters.contains(Character.toLowerCase(c)))
                return false;

            letters.add(Character.toLowerCase(c));
        }

        return true;
    }
}
