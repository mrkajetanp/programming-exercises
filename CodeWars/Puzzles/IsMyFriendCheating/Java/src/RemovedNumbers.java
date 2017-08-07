import java.util.ArrayList;
import java.util.List;

/**
 * Created by cajetan on 05/08/2017.
 */

public class RemovedNumbers {

    public static List<long[]> removNb(long n) {
        List<long[]> result = new ArrayList<>();
        long sum = n*(n+1)/2;

        for (long a = 1 ; a <= n ; ++a) {
            if ((sum-a)%(a+1) == 0) {
                long b = (sum-a)/(a+1);

                if (b < n)
                    result.add(new long[] {a, b});
            }
        }

        return result;
    }

}
