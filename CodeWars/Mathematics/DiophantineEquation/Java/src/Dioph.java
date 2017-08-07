/**
 * Created by cajetan on 06/08/2017.
 */

public class Dioph {

    public static String solEquaStr(long n) {
        StringBuilder result = new StringBuilder("[");

        for (long i = 1 ; i < Math.floor(Math.sqrt(n))+1 ; ++i) {
            // i == x-2y
            // j == x+2y
            if (n%i == 0) {
                long j = n/i;

                if ((j-i)%4 == 0) {
                    // j-i == 4y
                    // i+j == 2x
                    result.append(String.format("[%d, %d]", (i+j)/2, (j-i)/4));
                }
            }
        }

        return result.append("]").toString();
    }

}
