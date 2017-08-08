import java.util.stream.LongStream;

public class KPrimes {

    public static long nPrime(long n) {
        int result = 0;

        for (long i = 2 ; i < Math.sqrt(n)+1 ; ++i) {
            while (n%i == 0) {
                result++;
                n /= i;
            }
        }

        if (n > 1)
            result++;

        return result;
    }

    public static long[] countKprimes(int k, long start, long end) {
        return LongStream.range(start, end+1).filter(x -> nPrime(x) == k).toArray();
    }

    public static int puzzle(int s) {
        int result = 0;

        for (long i : countKprimes(1, 1, s)) {
            for (long j : countKprimes(3, 1, s)) {
                for (long k : countKprimes(7, 1, s)) {
                    if (i + j + k == s)
                        result++;
                }
            }
        }

        return result;
    }
}