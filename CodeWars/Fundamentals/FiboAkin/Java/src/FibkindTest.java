/**
 * Created by cajetan on 18/08/2017.
 */

import static org.junit.Assert.*;
import org.junit.Test;
import org.junit.runners.JUnit4;

public class FibkindTest {

    private static void dotest1(int n, int k, int expected) {
        assertEquals(expected, Fibkind.lengthSupUK(n, k));
    }
    private static void dotest2(int n, long expected) {
        assertEquals(expected, Fibkind.comp(n));
    }

    @Test
    public void test1() {
        System.out.println("Basic Tests lengthSupUK");
        dotest1(50, 25, 2);
        dotest1(3332, 973, 1391);
        dotest1(2941, 862, 1246);
        dotest1(3177, 573, 2047);
        dotest1(1745, 645, 474);
    }
    @Test
    public void test2() {
        System.out.println("Basic Tests comp");
        dotest2(74626, 37128);
        dotest2(71749, 35692);
        dotest2(56890, 28281);
        dotest2(60441, 30054);
        dotest2(21361, 10581);
    }
}
