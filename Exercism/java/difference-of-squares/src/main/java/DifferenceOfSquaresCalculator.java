import java.util.stream.IntStream;

public final class DifferenceOfSquaresCalculator {

    public int computeSquareOfSumTo(int a) {
        return (int) Math.pow(IntStream.rangeClosed(1, a).sum(), 2);
    }

    public int computeSumOfSquaresTo(int a) {
        return IntStream.rangeClosed(1, a).map(d -> (int)Math.pow(d, 2)).sum();
    }

    public int computeDifferenceOfSquares(int a) {
        return computeSquareOfSumTo(a) - computeSumOfSquaresTo(a);
    }
}
