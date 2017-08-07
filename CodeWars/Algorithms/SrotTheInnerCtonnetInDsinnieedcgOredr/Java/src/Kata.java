import java.util.Arrays;

/**
 * Created by cajetan on 17/07/2017.
 */

public class Kata {
    public static String sortTheInnerContent(String words) {
        StringBuilder result = new StringBuilder();

        for (String word : words.split("\\s")) {
            if (word.length() <= 3) {
                result.append(word).append(' ');
                continue;
            }

            result.append(word.charAt(0));

            char[] chars = word.substring(1, word.length()-1).toCharArray();
            Arrays.sort(chars);

            result.append(new StringBuffer(new String(chars)).reverse().toString())
                    .append(word.charAt(word.length()-1))
                    .append(' ');
        }

        result.setLength(result.length()-1);
        return result.toString();
    }
}
