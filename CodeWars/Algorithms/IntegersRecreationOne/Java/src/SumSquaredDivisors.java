import java.util.stream.LongStream;

public class SumSquaredDivisors {

    private static long sumSquaredDivisors(long n) {
        if (n == 1)
            return 1;

        return LongStream.range(1, (long)Math.ceil(Math.sqrt(n)))
                .filter(i -> n%i == 0)
                .map(i -> i*i + (n/i)*(n/i)).sum();
    }

    public static String listSquared(long m, long n) {
        StringBuilder result = new StringBuilder("[");

        for (long i = m ; i < n ; ++i) {
            double sum = sumSquaredDivisors(i);

            if (Math.sqrt(sum) == Math.round(Math.sqrt(sum)))
                result.append(String.format("[%d, %d], ", i, (long)sum));
        }

        if (result.length() >= 2)
            result.setLength(result.length()-2);
        return result.append("]").toString();
    }

}
