import java.util.ArrayList;
import java.util.List;

/**
 * Created by cajetan on 7/15/17.
 */

public class Line {
    private static int countOccurrences(List<Integer> list, int x) {
        int count = 0;

        for (int d : list) {
            if (d == x)
                count++;
        }

        return count;
    }

    public static String Tickets(int[] peopleInLine) {
        List<Integer> acc = new ArrayList<>();

        for (int x : peopleInLine) {
            switch (x) {
                case 25:
                    acc.add(x);
                    break;

                case 50:
                    if (!acc.contains(25))
                        return "NO";
                    acc.remove(acc.indexOf(25));
                    acc.add(50);
                    break;

                case 100:
                    if (acc.contains(50) && acc.contains(25)) {
                        acc.remove(acc.indexOf(50));
                        acc.remove(acc.indexOf(25));
                        acc.add(100);
                    } else if (countOccurrences(acc, 25) >= 3) {
                        acc.remove(acc.indexOf(25));
                        acc.remove(acc.indexOf(25));
                        acc.remove(acc.indexOf(25));
                        acc.add(100);
                    } else {
                        return "NO";
                    }
                    break;
            }
        }

        return "YES";
    }
}