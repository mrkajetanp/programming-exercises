/**
 * Created by cajetan on 16/07/2017.
 */

public class Carboat {

    public static String howmuch(int m, int n) {
        if (m > n) {
            int temp = m;
            m = n;
            n = temp;
        }

        StringBuilder result = new StringBuilder("[");

        double c = 0, b = 0;
        for (int i = m ; i <= n ; ++i) {
            c = (i-1)/9.0;
            b = (i-2)/7.0;

            if (c < 0 || b < 0)
                continue;

            if (c-Math.floor(c) == 0 && b-Math.floor(b) == 0) {
                result.append("[M: ");
                result.append(i);
                result.append(" B: ");
                result.append((int)b);
                result.append(" C: ");
                result.append((int)c);
                result.append(']');
            }
        }

        return result.append("]").toString();
    }
}