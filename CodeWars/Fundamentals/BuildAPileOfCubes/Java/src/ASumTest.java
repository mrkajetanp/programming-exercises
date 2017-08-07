/**
 * Created by cajetan on 29/07/2017.
 */

import static org.junit.Assert.*;
import org.junit.Test;


public class ASumTest {

    @Test
    public void test1() {
        assertEquals(2022, ASum.findNb(4183059834009L));
    }

    @Test
    public void test5() {
        assertEquals(-1, ASum.findNb(1662894635950598401L));
    }

    @Test
    public void test2() {
        assertEquals(-1, ASum.findNb(24723578342962L));
    }
    @Test
    public void test3() {
        assertEquals(4824, ASum.findNb(135440716410000L));
    }
    @Test
    public void test4() {
        assertEquals(3568, ASum.findNb(40539911473216L));
    }

    @Test
    public void test6() {
        assertEquals(54907, ASum.findNb(2272305342595901284L));
    }



}