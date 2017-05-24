import java.util.Arrays;

/**
 * Created by cajetan on 5/24/17.
 */
public class PigLatinTranslator {
    private String[] multiCons;
    private String[] multiVowels;

    public PigLatinTranslator() {
        multiCons = new String[8];
        multiCons[0] = "ch";
        multiCons[1] = "qu";
        multiCons[2] = "squ";
        multiCons[3] = "th";
        multiCons[4] = "thr";
        multiCons[5] = "sch";
        multiCons[6] = "yt";
        multiCons[7] = "xr";

        multiVowels = new String[2];
        multiVowels[0] = "yt";
        multiVowels[1] = "xr";
    }

    private boolean isVowel(char c) {
        String vowels = "aeiouAEIOU";
        return vowels.contains(String.valueOf(c));
    }

    public String translate(String phrase) {
        StringBuilder result = new StringBuilder();

        if (phrase.contains(String.valueOf(' '))) {
            for (String s : phrase.split("\\s+")) {
                result.append(translate(s));
                result.append(' ');
            }
            result.deleteCharAt(result.length()-1);

            return result.toString();
        }

        if (isVowel(phrase.charAt(0)) ||
                Arrays.asList(multiVowels).contains(phrase.substring(0, 2))) {
            result.append(phrase);
        } else {
            if (Arrays.asList(multiCons).contains(phrase.substring(0, 3))) {
                result.append(phrase.substring(3));
                result.append(phrase.substring(0, 3));
            } else if (Arrays.asList(multiCons).contains(phrase.substring(0, 2))) {
                result.append(phrase.substring(2));
                result.append(phrase.substring(0, 2));
            } else {
                result.append(phrase.substring(1));
                result.append(phrase.charAt(0));
            }
        }
        result.append("ay");

        return result.toString();
    }
}
