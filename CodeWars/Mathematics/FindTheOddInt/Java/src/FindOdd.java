import java.util.HashMap;
import java.util.Map;

/**
 * Created by cajetan on 7/13/17.
 */

public class FindOdd {
    public static int findIt(int[] A) {
        HashMap<Integer, Integer> occurrences = new HashMap<>();

        for (int x : A) {
            if (!occurrences.containsKey(x))
                occurrences.put(x, 1);
            else
                occurrences.put(x, occurrences.get(x)+1);
        }

        for (Map.Entry<Integer, Integer> entry : occurrences.entrySet()) {
            if (entry.getValue()%2 != 0)
                return entry.getKey();
        }

        throw new IllegalArgumentException();
    }
}