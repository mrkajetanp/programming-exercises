import java.util.Arrays;

/**
 * Created by cajetan on 7/12/17.
 */

public class AreSame {
    public static boolean comp(int[] a, int[] b) {
        if (a == null || b == null)
            return false;

        return Arrays.equals(Arrays.stream(a).map(i -> i*i).sorted().toArray(),
                Arrays.stream(b).sorted().toArray());
    }
}