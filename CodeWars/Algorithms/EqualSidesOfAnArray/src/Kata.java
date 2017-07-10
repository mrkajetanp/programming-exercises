import java.util.List;
import java.util.stream.Collectors;
import java.util.stream.IntStream;

/**
 * Created by cajetan on 7/10/17.
 */

public class Kata {
    public static int findEvenIndex(int[] arr) {
        List<Integer> input = IntStream.of(arr).boxed().collect(Collectors.toList());

        for (int i = 0 ; i < input.size() ; ++i) {
            if (input.subList(0, i).stream().mapToInt(d -> d).sum() ==
                    input.subList(i+1, input.size()).stream().mapToInt(d -> d).sum())
                return i;
        }

        return -1;
    }
}
