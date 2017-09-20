/**
 * Created by cajetan on 20/09/2017.
 */

public class BackWardsPrime {

    private boolean isPrime(long n) {
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

    public static String backwardsPrime(long start, long end) {

        return "";
    }

}

