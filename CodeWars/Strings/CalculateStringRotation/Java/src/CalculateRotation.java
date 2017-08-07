/**
 * Created by cajetan on 16/07/2017.
 */

public class CalculateRotation {
    static String rotate(String input) {
        StringBuilder result = new StringBuilder();

        result.append(input.charAt(input.length()-1));
        result.append(input.substring(0, input.length()-1));

        return result.toString();
    }

    static int shiftedDiff(String first, String second){
        int len = first.length();

        for (int i = 0 ; i < len ; ++i) {
            if (first.equals(second))
                return i;

            first = rotate(first);
        }

        return -1;
    }

    static int shiftedDiffBetter(String first, String second) {
        if (first.length() != second.length())
            return -1;

        return (second + second).indexOf(first);
    }
}



