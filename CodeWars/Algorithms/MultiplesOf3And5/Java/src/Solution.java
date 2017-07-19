import java.util.stream.IntStream;

/**
 * Created by cajetan on 19/07/2017.
 */

public class Solution {

    public int solution(int number) {
        return IntStream.range(1, number)
                .filter(x -> x%3 == 0 || x%5 == 0)
                .sum();
    }

}
