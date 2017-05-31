import java.util.ArrayList;

/**
 * Created by cajetan on 5/31/17.
 */
public class PrimeFactorsCalculator {
    private boolean isPrime(long a) {
        int cnt = 1;

        for (int i = 2 ; i <= a ; ++i) {
            if (a % i == 0)
                cnt++;

            if (cnt > 2)
                return false;
        }

        return true;
    }

    public ArrayList<Long> calculatePrimeFactorsOf(long a) {
        ArrayList<Long> result = new ArrayList<>();

        if (a == 1)
            return result;

        if (isPrime(a)) {
            result.add(a);
            return result;
        }

        while (!isPrime(a)) {
            for (int i = 2 ; i <= a ; i++) {
                if (a%i == 0 && isPrime(i)) {
                    result.add((long) i);
                    a /= i;
                }
            }
        }

        if (isPrime(a) && a != 1)
            result.add(a);

        return result;
    }
}
