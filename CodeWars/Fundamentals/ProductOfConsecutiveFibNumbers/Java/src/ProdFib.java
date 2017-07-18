/**
 * Created by cajetan on 18/07/2017.
 */

public class ProdFib {

    public static long[] productFib(long prod) {
        long a = 0;
        long b = 1;

        while (a*b < prod) {
            long tmp = a;
            a = b;
            b += tmp;
        }

        return new long[] {a, b, (a*b == prod) ? 1 : 0};
    }

}
