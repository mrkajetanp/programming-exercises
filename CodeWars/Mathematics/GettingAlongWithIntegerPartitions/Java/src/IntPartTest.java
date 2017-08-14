/**
 * Created by cajetan on 14/08/2017.
 */

import static org.junit.Assert.*;
import org.junit.Test;

public class IntPartTest {

    @Test
    public void Numbers_Small() {
        // assertEquals("Range: 1 Average: 1.50 Median: 1.50", IntPart.part(2));
        // assertEquals("Range: 2 Average: 2.00 Median: 2.00", IntPart.part(3));
        // assertEquals("Range: 3 Average: 2.50 Median: 2.50", IntPart.part(4));
        assertEquals("Range: 5 Average: 3.50 Median: 3.50", IntPart.part(5));
    }
}
/*
import java.util.ArrayList;
import java.util.Collections;
import java.util.List;
import java.util.Locale;

public class IntPart {

    private static List<List<Long>> partAux(long s, long k) {
        long k0 = Math.min(s, k);
        List<List<Long>> res = new ArrayList<List<Long>>();
        if (k0 < 1)
            return res;
        for (long n = k0; n > 0; n--) {
            long r = s - n;
            if (r > 0) {
                List<List<Long>> arr = partAux(r, n);
                for (int i = 0; i < arr.size(); i++) {
                    List<Long> t = arr.get(i);
                    t.add(n);
                    res.add(t);
                }
            } else {
                List<Long> q = new ArrayList<Long>();
                q.add(n);
                res.add(q);
            }
        }
        return res;
    }

    public static String part(long n) {
        List<List<Long>> res = IntPart.partAux(n, n);
        List<Long> r = new ArrayList<Long>();
        for (int i = 0; i < res.size(); i++) {
            List<Long> t = res.get(i);
            long p = 1;
            for (int j = 0; j < t.size(); j++) {
                p *= t.get(j);
            }
            if (!r.contains(p))
                r.add(p);
        }
        Collections.sort(r);
        int lg = r.size();
        long sm = 0;
        for (int i = 0; i < r.size(); i++) {
            sm += r.get(i);
        }
        double avg = sm / (double) lg;
        long rge = r.get(lg - 1) - r.get(0);
        double md = (r.get((lg - 1) / 2) + r.get(lg / 2)) / 2.0;
        return String.format(Locale.US, "Range: %d Average: %.2f Median: %.2f",
                rge, avg, md);
    }
}
*/