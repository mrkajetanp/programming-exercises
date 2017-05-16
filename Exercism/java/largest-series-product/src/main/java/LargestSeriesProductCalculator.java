import java.util.Arrays;

public class LargestSeriesProductCalculator {
    private long[] num;

    public LargestSeriesProductCalculator(String num) {
        if (num == null)
            throw new IllegalArgumentException("String to search must be non-null.");

        if (!num.chars().allMatch(Character::isDigit))
            throw new IllegalArgumentException("String to search may only contains digits.");

        this.num = num.chars().map(Character::getNumericValue).asLongStream().toArray();
    }

    public long calculateLargestProductForSeriesLength(int chain) {
        if (chain > num.length)
            throw new IllegalArgumentException("Series length must be less than or equal to the length of the string to search.");

        if (chain < 0)
            throw new IllegalArgumentException("Series length must be non-negative.");

        long sum = 0;
        long temp = 1;

        for (int i = 0 ; i <= this.num.length-chain ; i++) {
            for (long x : Arrays.stream(num).skip(i).limit(chain).toArray())
                temp *= x;

            if (temp > sum)
                sum = temp;

            temp = 1;
        }

        return sum;
    }
}
