import java.util.ArrayList;
import java.util.Arrays;
import java.util.List;

/**
 * Created by cajetan on 18/08/2017.
 */

class Fibkind {

    public static long lengthSupUK(int n, int k) {
        List<Integer> fibos  = new ArrayList<>(Arrays.asList(1, 1));
        int count = 0;

        for (int i = 3 ; i <= n ; ++i) {
            int curr = fibos.get(i - fibos.get(i-1-1) - 1) +
                    fibos.get(i - fibos.get(i-2-1) - 1);

            if (curr >= k)
                count++;

            fibos.add(curr);
        }

        return count;
    }

    public static long comp(int n) {
        List<Integer> fibos  = new ArrayList<>(Arrays.asList(1, 1));
        int count = 0;

        for (int i = 3 ; i <= n ; ++i) {
            int curr = fibos.get(i - fibos.get(i-1-1) - 1) +
                    fibos.get(i - fibos.get(i-2-1) - 1);

            if (curr < fibos.get(fibos.size()-1))
                count++;

            fibos.add(curr);
        }

        return count;
    }

}