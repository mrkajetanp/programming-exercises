/**
 * Created by cajetan on 15/08/2017.
 */

public class PrimeConsec {

    public static int nPrime(long n) {
        int result = 0;

        for (int i = 2 ; i < Math.sqrt(n)+1 ; ++i) {
            while (n%i == 0) {
                result++;
                n /= i;
            }
        }

        if (n > 1)
            result++;

        return result;
    }

    public static int consecKprimes(int k, long[] arr) {
        int count = 0;
        boolean prev = false;

        for (long x : arr) {
            if (nPrime(x) == k) {
                if (prev)
                    count++;

                prev = true;
            } else {
                prev = false;
            }
        }

        return count;
    }

}