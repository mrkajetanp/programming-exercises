/**
 * Created by cajetan on 19/08/2017.
 */

public class Suite {

    public static double going(int n) {
        double result = 0.0;

        for (int i = 1 ; i <= n ; ++i) {
            result += (double)i;
            result /= (double)i;
        }

        return Math.floor(result * 1e6) / 1e6;
    }

}