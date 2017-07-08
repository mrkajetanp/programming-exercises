import java.util.Arrays;
import java.util.Comparator;
import java.util.List;

/**
 * Created by cajetan on 7/8/17.
 */

class WeightCompare implements Comparator<String> {
    @Override
    public int compare(String a, String b) {
        int sumA = a.chars().reduce(0,
                (sum, i) -> sum + Character.getNumericValue(i));

        int sumB = b.chars().reduce(0,
                (sum, i) -> sum + Character.getNumericValue(i));

        if (sumA == sumB)
            return a.compareTo(b);
        else
            return Integer.compare(sumA, sumB);
    }
}

public class WeightSort {

    public static String orderWeight(String input) {
        List<String> parts = Arrays.asList(input.split(" "));
        parts.sort(new WeightCompare());

        String result = parts.stream().reduce("", (str, i) -> str + i + " ");
        return result.substring(0, result.length()-1);
    }

}
