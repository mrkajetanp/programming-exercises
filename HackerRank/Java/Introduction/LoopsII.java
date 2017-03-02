import java.util.*;
import static org.junit.Assert.assertEquals;
import org.junit.Test;

public class LoopsII {
    public static int testMe (int a) {
        if (a == 8)
            return 16;

        return 5;
    }

    public static void main(String[] args) {
        Scanner in = new Scanner(System.in);
        int t=in.nextInt();
        for(int i=0;i<t;i++){
            int a  = in.nextInt();
            int b = in.nextInt();
            int n = in.nextInt();
            for (int j = 0 ; j < n ; ++j) {
                long num = a;
                for (int k = 0 ; k <= j ; ++k) {
                    num += Math.pow(2,k)*b;
                }
                System.out.print (num);
                if (j != n-1)
                    System.out.print(" ");
            }
            if (i != n-1)
                System.out.println("");
        }
        in.close();
    }
}

class MyTests {

    @Test
    public void testTestMe() {
        LoopsII l2 = new LoopsII();
        assertEquals("10 x 0 must be 0", 16, l2.testMe(8));
    }
}
