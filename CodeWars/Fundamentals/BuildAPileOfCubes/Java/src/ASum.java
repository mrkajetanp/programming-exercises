import java.math.BigDecimal;
import java.math.RoundingMode;

/**
 * Created by cajetan on 29/07/2017.
 */

public class ASum {

    public static long findNb(long m) {
        long n = 1;

        BigDecimal num = new BigDecimal(Math.pow(n*(n+1)/2, 2));

        while (num.longValue() < m) {
            n++;
            num = new BigDecimal(n).multiply(new BigDecimal(n+1))
            .divide(new BigDecimal(2), RoundingMode.valueOf(0)).pow(2);
        }

        return (num.longValue() == m) ? n : -1;
    }
}
