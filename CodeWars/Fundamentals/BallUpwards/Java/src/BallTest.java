/**
 * Created by cajetan on 24/07/2017.
 */

import static org.junit.Assert.*;
import org.junit.Test;


public class BallTest {

    private static void testing(int actual, int expected) {
        assertEquals(expected, actual);
    }
    @Test
    public void test() {
        System.out.println("Fixed Tests maxBall");
        testing(Ball.maxBall(37), 10);
        testing(Ball.maxBall(45), 13);
        testing(Ball.maxBall(99), 28);
        testing(Ball.maxBall(85), 24);
    }
}