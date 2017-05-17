import java.util.ArrayList;
import java.util.Arrays;
import java.util.List;

/**
 * Created by cajetan on 5/17/17.
 */

public class Sieve {
    private int upTo;

    public Sieve(int upTo) {
        this.upTo = upTo;
    }

    List<Integer> getPrimes() {
        List<Integer> result = new ArrayList<>();

        if (upTo == 2) {
            result.add(2);
            return result;
        }

        boolean[] prime_mask = new boolean[upTo];
        Arrays.fill(prime_mask, Boolean.TRUE);

        int i = 2;

        while (Math.pow(i, 2) < upTo) {
            if (prime_mask[i]) {
                int j = i*2;
                while (j < upTo) {
                    prime_mask[j] = false;
                    j += i;
                }
            }

            i++;
        }

        prime_mask[0] = false;
        prime_mask[1] = false;

        for (i = 0 ; i < prime_mask.length ; i++) {
            if (prime_mask[i])
                result.add(i);
        }

        return result;
    }
}
