/**
 * Created by cajetan on 15/08/2017.
 */

import static org.junit.Assert.*;
import org.junit.Test;

public class PrimeConsecTest {

    private static void testing(int k, long[] arr, int expected) {
        assertEquals(expected, PrimeConsec.consecKprimes(k, arr));
    }

    @Test
    public void test() {
        System.out.println("Basic Tests consecKprimes");
        testing(6, new long[] {10098}, 0);
        testing(6, new long[] {10176, 10164}, 0);
        testing(5, new long[] {10116, 10108, 10092, 10104, 10100, 10096, 10088}, 6);
        testing(5, new long[] {10188, 10192, 10212, 10184, 10200, 10208}, 1);
        testing(4, new long[] {10175, 10185, 10180, 10197}, 3);
    }
}