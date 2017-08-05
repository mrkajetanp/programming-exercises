/**
 * Created by cajetan on 05/08/2017.
 */

import static org.junit.Assert.*;
import java.util.List;
import java.util.ArrayList;
import org.junit.Test;

public class RemovedNumbersTest {
    @Test
    public void test12() {
        List<long[]> res = new ArrayList<long[]>();
        res.add(new long[] {15, 21});
        res.add(new long[] {21, 15});
        List<long[]> a = RemovedNumbers.removNb(26);
        assertArrayEquals(res.get(0), a.get(0));
        assertArrayEquals(res.get(1), a.get(1));
    }
    @Test
    public void test14() {
        List<long[]> res = new ArrayList<long[]>();
        List<long[]> a = RemovedNumbers.removNb(100);
        assertTrue(res.size() == a.size());
    }
}
