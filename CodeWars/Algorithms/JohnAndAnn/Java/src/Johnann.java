import java.util.ArrayList;
import java.util.List;

/**
 * Created by cajetan on 17/08/2017.
 */

public class Johnann {

    public static List<Long> john(long n) {
        List<Long> anns = new ArrayList<>();
        anns.add(1L);
        anns.add(1L);

        List<Long> johns = new ArrayList<>();
        johns.add(0L);
        johns.add(0L);

        for (int i = 2 ; i < n ; ++i) {
            anns.add(i - johns.get(Math.toIntExact(anns.get(i-1))));
            johns.add(i - anns.get(Math.toIntExact(johns.get(i-1))));
        }

        return johns;
    }

    public static List<Long> ann(long n) {
        List<Long> anns = new ArrayList<>();
        anns.add(1L);
        anns.add(1L);

        List<Long> johns = new ArrayList<>();
        johns.add(0L);
        johns.add(0L);

        for (int i = 2 ; i < n ; ++i) {
            anns.add(i - johns.get(Math.toIntExact(anns.get(i-1))));
            johns.add(i - anns.get(Math.toIntExact(johns.get(i-1))));
        }

        return anns;
    }

    public static long sumJohn(long n) {
        return john(n).stream().reduce(0L, (x, y) -> x + y);
    }

    public static long sumAnn(long n) {
        return ann(n).stream().reduce(0L, (x, y) -> x + y);
    }
}
