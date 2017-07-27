import java.util.ArrayList;
import java.util.Arrays;
import java.util.List;

/**
 * Created by cajetan on 27/07/2017.
 */

public class SqProd2Sum {
    public static List<long[]> prod2Sum(long a, long b, long c, long d) {
        List<long[]> result = new ArrayList<>();
        long n = (a*a + b*b) * (c*c + d*d);
        long[] sums = new long[] { Math.abs(a*c+b*d),Math.abs(a*d+b*c),
                Math.abs(a*c-b*d), Math.abs(a*d-b*c)};

        for (long e : sums) {
            for (long f : sums) {
                if (Math.pow(e, 2) + Math.pow(f, 2) == n) {
                    long[] pair = new long[] { Math.min(e, f), Math.max(e, f)};
                    if (result.stream().noneMatch(arr -> Arrays.equals(arr, pair)))
                        result.add(pair);
                }
            }
        }

        result.sort((i, j) -> Long.compare(i[0], j[0]));
        return result;
    }
}
