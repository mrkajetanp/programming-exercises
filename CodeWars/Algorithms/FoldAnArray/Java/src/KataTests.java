/**
 * Created by cajetan on 7/11/17.
 */
import org.junit.Test;
import static org.junit.Assert.assertEquals;
import java.util.Arrays;

public class KataTests {
    @Test
    public void basicTests() {
        int[] input = new int[] { 1, 2, 3, 4, 5 };
        int[] expected = new int[] { 6, 6, 3 };
        assertEquals(Arrays.toString(expected), Arrays.toString(Kata.foldArray(input, 1)));

        expected = new int[] { 9, 6 };
        assertEquals(Arrays.toString(expected), Arrays.toString(Kata.foldArray(input, 2)));

        expected = new int[] { 15 };
        assertEquals(Arrays.toString(expected), Arrays.toString(Kata.foldArray(input, 3)));

        input = new int[] { -9, 9, -8, 8, 66, 23 };
        expected = new int[] { 14, 75, 0 };
        assertEquals(Arrays.toString(expected), Arrays.toString(Kata.foldArray(input, 1)));
    }
}