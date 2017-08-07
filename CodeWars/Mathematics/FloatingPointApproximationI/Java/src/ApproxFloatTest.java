/**
 * Created by cajetan on 23/07/2017.
 */

import java.text.DecimalFormat;
import static org.junit.Assert.*;
import org.junit.Test;

public class ApproxFloatTest {
    private static void assertFuzzyEquals(double act, double exp){
        boolean inrange;
        double merr = 1e-12;
        if (exp == 0.0)
            inrange = Math.abs(act) <= merr;
        else {
            double e = Math.abs((act - exp) / exp);
            inrange = e <= 1e-12;
        }
        if (!inrange) {
            DecimalFormat df = new DecimalFormat("#.0000000000000000");
            System.out.println("Expected must be near " + exp +", but got " + act);
        }
        assertEquals(true, inrange);
    }
    @Test
    public void test1() {
        System.out.println("Fixed Tests: f");
        assertFuzzyEquals (ApproxFloat.f(2.6e-08), 1.29999999155e-08);
        assertFuzzyEquals (ApproxFloat.f(1.4e-09), 6.999999997549999e-10);
        assertFuzzyEquals (ApproxFloat.f(5.0e-06), 2.499996875007812e-06);
        assertFuzzyEquals (ApproxFloat.f(2.4e-07), 1.1999999280000085e-07);
    }
}