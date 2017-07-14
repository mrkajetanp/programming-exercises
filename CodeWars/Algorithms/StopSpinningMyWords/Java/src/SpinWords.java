/**
 * Created by cajetan on 7/14/17.
 */

public class SpinWords {

    public String spinWords(String sentence) {
        StringBuilder result = new StringBuilder();

        for (String word : sentence.split("\\s")) {
            if (word.length() >= 5)
                result.append(new StringBuilder(word).reverse().toString());
            else
                result.append(word);

            result.append(" ");
        }

        result.setLength(result.length()-1);
        return result.toString();
    }

}