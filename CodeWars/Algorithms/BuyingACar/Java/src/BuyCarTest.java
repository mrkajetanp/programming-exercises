/**
 * Created by cajetan on 28/07/2017.
 */

import static org.junit.Assert.*;
import org.junit.Test;

public class BuyCarTest {

    @Test
    public void test1() {
        int[] r = new int[] { 6, 766 };
        assertArrayEquals(r, BuyCar.nbMonths(2000, 8000, 1000, 1.5));
    }
    @Test
    public void test2() {
        int[] r = new int[] { 0, 4000 };
        assertArrayEquals(r, BuyCar.nbMonths(12000, 8000, 1000, 1.5));
    }
}