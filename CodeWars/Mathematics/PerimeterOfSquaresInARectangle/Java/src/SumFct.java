import java.math.BigInteger;

/**
 * Created by cajetan on 04/08/2017.
 */

class Fibonacci {
    private BigInteger curr;
    private BigInteger next;

    public Fibonacci() {
        this.curr = new BigInteger("0");
        this.next = new BigInteger("1");
    }

    public BigInteger next() {
        BigInteger new_next = this.curr.add(this.next);

        this.curr = this.next;
        this.next = new_next;

        return this.curr;
    }
}

public class SumFct {
    public static BigInteger perimeter(BigInteger n) {
        Fibonacci fib = new Fibonacci();

        BigInteger result = new BigInteger("0");

        for (long i = 0 ; i <= n.longValue() ; ++i)
            result = result.add(fib.next());

        return result.multiply(BigInteger.valueOf(4));
    }
}
