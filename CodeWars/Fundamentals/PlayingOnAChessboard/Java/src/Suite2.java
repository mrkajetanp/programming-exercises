/**
 * Created by cajetan on 02/08/2017.
 */

public class Suite2 {

    public static String game(long n) {
        return (n%2 == 0) ?
                String.format("[%d]", n/2*n) :
                String.format("[%d, %d]", n*n, 2);
    }

}
