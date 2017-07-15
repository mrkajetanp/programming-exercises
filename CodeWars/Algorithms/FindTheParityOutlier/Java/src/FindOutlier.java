/**
 * Created by cajetan on 7/15/17.
 */

public class FindOutlier {
    static int find(int[] integers) {
        boolean evens = false;

        if ((integers[0]%2 == 0 && integers[1]%2 == 0) ||
            (integers[1]%2 == 0 && integers[2]%2 == 0) ||
            (integers[0]%2 == 0 && integers[2]%2 == 0)) {

            evens = true;
        }

        for (int x : integers) {
            if ((x%2 != 0) == evens)
                return x;
        }

        return 0;
    }
}