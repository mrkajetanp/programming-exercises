import java.util.ArrayList;
import java.util.Arrays;
import java.util.Collections;
import java.util.List;

public class SumOfDivided {
    public static void primeFactors(List<Integer> list, int n) {

        for (int i = 2 ; i < Math.sqrt(n)+1 ; ++i) {
            while (n%i == 0) {
                if (!list.contains(i))
                    list.add(i);
                n /= i;
            }
        }

        if (n > 1) {
            if (!list.contains(n))
                list.add(n);
        }
    }

    public static String sumOfDivided(int[] l) {
        List<Integer> factors = new ArrayList<>();

        for (int x : l)
            primeFactors(factors, x);
        Collections.sort(factors);

        StringBuilder result = new StringBuilder();

        for (int i : factors) {
            result.append(String.format("(%d %d)", i,
                    Arrays.stream(l).filter(x -> x%i == 0).sum()));
        }

        return result.toString();
    }
}
