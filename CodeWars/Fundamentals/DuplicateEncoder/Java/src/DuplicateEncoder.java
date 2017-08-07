/**
 * Created by cajetan on 21/07/2017.
 */

public class DuplicateEncoder {
    static String encode(String word){
        String lower = word.toLowerCase();

        return lower.chars().
                map(c -> (lower.indexOf(c) == lower.lastIndexOf(c)) ? '(' : ')')
                .collect(StringBuilder::new,
                        StringBuilder::appendCodePoint,
                        StringBuilder::append)
                .toString();
    }
}
