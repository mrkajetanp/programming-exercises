import java.util.function.LongBinaryOperator;

/**
 * Created by cajetan on 26/07/2017.
 */

public class Operarray {
    public static long gcdi(long a, long b) {
        return (b == 0) ? Math.abs(a) : gcdi(b, a%b);
    }

    public static long lcmu(long a, long b) {
        return (Math.abs(a)*Math.abs(b)) / gcdi(Math.abs(a), Math.abs(b));
    }

    public static long som(long a, long b) {
        return a+b;
    }

    public static long maxi(long a, long b) {
        return Math.max(a, b);
    }

    public static long mini(long a, long b) {
        return Math.min(a, b);
    }

    public static long[] operArray(LongBinaryOperator operator,
                                   long[] arr, long init) {
        long[] result = new long[arr.length];

        result[0] = operator.applyAsLong(init, arr[0]);
        for (int i = 0 ; i < arr.length-1 ; ++i)
            result[i+1] = operator.applyAsLong(result[i], arr[i+1]);

        return result;
    }
}