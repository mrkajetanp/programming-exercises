/**
 * Created by cajetan on 5/10/17.
 */

public class RaindropConverter {
    public String convert(int num) {
        StringBuilder result = new StringBuilder("");

        if (num%3 != 0 && num%5 != 0 && num%7 != 0)
            return String.format("%d", num);

        if (num % 3 == 0)
            result.append("Pling");

        if (num % 5 == 0)
            result.append("Plang");

         if (num % 7 == 0)
            result.append("Plong");

        return result.toString();
    }
}
