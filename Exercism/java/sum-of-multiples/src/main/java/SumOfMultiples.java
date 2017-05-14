import java.util.HashSet;
import java.util.stream.IntStream;

public class SumOfMultiples {
    private int num;
    private int[] set;

    public SumOfMultiples(int num, int[] set) {
        this.num = num;
        this.set = set;
    }

    public int getSum() {
        HashSet<Integer> multiples = new HashSet<>();

        for (int x: set)
            IntStream.range(1, num).filter(d -> d % x == 0).forEach(multiples::add);

        return multiples.stream().reduce(0, Integer::sum);
    }
}
