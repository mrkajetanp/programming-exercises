/**
 * Created by cajetan on 17/07/2017.
 */

public class Solution {
    public static boolean isVowel(char c) {
        return (c =='a' || c == 'e' || c == 'i' ||
                c == 'o' || c == 'u');
    }

    public static boolean isAlt(String word) {
        boolean wasVowel = isVowel(word.charAt(0));

        for (char c : word.substring(1).toCharArray()) {
            if (wasVowel && isVowel(c) || !wasVowel && !isVowel(c))
                return false;

            wasVowel = isVowel(c);
        }

        return true;
    }
}
