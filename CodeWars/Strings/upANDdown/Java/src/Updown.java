import java.util.Arrays;
import java.util.Collections;
import java.util.List;

/**
 * Created by cajetan on 25/07/2017.
 */

class Updown {

    public static String arrange(String str) {
        List<String> words = Arrays.asList(str.split("\\s"));

        if (words.size() < 2)
            return str;

        for (int i = 0 ; i < words.size()-1 ; ++i) {
            if (i%2 == 0) {
                if (!(words.get(i).length() <= words.get(i+1).length()))
                    Collections.swap(words, i, i+1);

                words.set(i, words.get(i).toLowerCase());
            } else {
                if (!(words.get(i).length() >= words.get(i+1).length()))
                    Collections.swap(words, i, i+1);

                words.set(i, words.get(i).toUpperCase());
            }
        }

        if (words.size()%2 == 0)
            words.set(words.size()-1, words.get(words.size()-1).toUpperCase());
        else
            words.set(words.size()-1, words.get(words.size()-1).toLowerCase());

        return String.join(" ", words);
    }
}