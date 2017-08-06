/**
 * Created by cajetan on 06/08/2017.
 */

import static org.junit.Assert.*;
import org.junit.Test;


public class DiophTest {

    @Test
    public void test1() {
        assertEquals("[[3, 1]]", Dioph.solEquaStr(5));
    }
    @Test
    public void test2() {
        assertEquals("[[4, 1]]", Dioph.solEquaStr(12));
    }
    @Test
    public void test3() {
        assertEquals("[[7, 3]]", Dioph.solEquaStr(13));
    }
    @Test
    public void test4() {
        assertEquals("[[4, 0]]", Dioph.solEquaStr(16));
    }
}