/**
 * Created by cajetan on 03/08/2017.
 */

class GapInPrimes {
    private static boolean isPrime(long n) {
        if (n <= 3)
            return true;

        if (n%2 == 0 || n%3 == 0)
            return false;

        long i = 5;
        long w = 2;

        while (Math.pow(i, 2) <= n) {
            if (n%i == 0)
                return false;

            i += w;
            w = 6-w;
        }

        return true;
    }

    public static long[] gap(int g, long m, long n) {
        if (n-m == g)
            return new long[] { m, n };

        long last_prime = 0;

        for (long i = m ; i <= n ; ++i) {
            if (!isPrime(i))
                continue;

            if (i-last_prime == g)
                return new long[] { last_prime, i };

            last_prime = i;
        }

        return null;
    }
}
