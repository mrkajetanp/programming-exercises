/**
 * Created by cajetan on 5/21/17.
 */
public class PrimeCalculator {
    public boolean isPrime(int num) {
        if (num == 2 || num == 3)
            return true;

        if (num%2 == 0)
            return false;

        for (int i = 3 ; i < (int)Math.sqrt(num)+1 ; i += 2) {
            if (num%i == 0)
                return false;
        }

        return true;
    }

    public int nth(int num) {
        if (num < 1)
            throw new IllegalArgumentException();

        int nth = 0;

        for (int i = 2 ; ; ++i) {
            if (isPrime(i))
                nth++;

            if (nth == num)
                return i;
        }
    }
}
