import java.util.ArrayList;
import java.util.Arrays;
import java.util.List;
import java.util.stream.Collectors;
import java.util.stream.LongStream;

/**
 * Created by cajetan on 14/08/2017.
 */

public class IntPart {

    private static List<List<Long>> decompose(long n, long m) {
        long k = Math.min(n, m);
        List<List<Long>> result = new ArrayList<>();

        if (k < 1)
            return result;

        for (long i = k ; i > 0 ; --i) {
            if (n-i > 0) {
                List<List<Long>> arr = decompose(n-i, i);
                for (List<Long> t : arr) {
                    t.add(n);
                    result.add(t);
                }
            } else {
                List<Long> q = new ArrayList<>();
                q.add(n);
                result.add(q);
            }
        }

        return result;
    }

    public static String part(long n) {
        List<List<Long>> temp = decompose(n, n);

        long[] result = temp.stream()
                .mapToLong(v -> v.stream().reduce(1L, (a, b) -> a*b))
                .distinct().toArray();
        for (long i : result)
            System.out.print(i + ",");
        System.out.println();


        return "";
    }
}

