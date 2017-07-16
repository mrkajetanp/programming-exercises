/**
 * Created by cajetan on 16/07/2017.
 */
import org.junit.Test;
import static org.junit.Assert.assertEquals;
import org.junit.runners.JUnit4;


public class RotationTest {
    @Test
    public void test() {
        assertEquals(-1, CalculateRotation.shiftedDiff("hoop","pooh"));
        assertEquals(2, CalculateRotation.shiftedDiff("coffee","eecoff"));
        assertEquals(4, CalculateRotation.shiftedDiff("eecoff","coffee"));
    }
}
