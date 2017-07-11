import java.util.ArrayList;
import java.util.List;

/**
 * Created by cajetan on 7/11/17.
 */

public class Kata {
    public static int[] foldArray(int[] array, int runs) {
        List<Integer> result = new ArrayList<>();

        for (int i = 0, j = array.length-1 ; i < Math.floor(array.length/2) ; ++i, --j)
            result.add(array[i] + array[j]);

        if (array.length%2 != 0)
            result.add(array[(int)Math.ceil(array.length/2)]);

        return (runs == 1) ? result.stream().mapToInt(i -> i).toArray() :
                foldArray(result.stream().mapToInt(i -> i).toArray(), runs-1);
    }
}

