/**
 * Created by cajetan on 20/07/2017.
 */

import static org.junit.Assert.*;
import org.junit.Test;

public class ThirteenTest {

    private static void testing(long actual, long expected) {
        assertEquals(expected, actual);
    }
    @Test
    public void test1() {
        System.out.println("Fixed Tests: thirt");
        testing(Thirteen.thirt(8529), 79);
        testing(Thirteen.thirt(85299258), 31);
        testing(Thirteen.thirt(5634), 57);
        testing(Thirteen.thirt(1111111111), 71);
        testing(Thirteen.thirt(987654321), 30);
    }
}