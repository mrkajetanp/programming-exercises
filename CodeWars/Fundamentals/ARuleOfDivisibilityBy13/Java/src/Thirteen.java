/**
 * Created by cajetan on 20/07/2017.
 */

class Thirteen {

    public static long thirt(long n) {
        long new_num = n;
        long old_num = n-1;

        long[] rems = new long[] { 1, 10, 9, 12, 3, 4 };

        while (new_num != old_num) {
            old_num = new_num;

            long[] digits = new StringBuilder()
                    .append(old_num).reverse().toString()
                    .chars()
                    .mapToLong(Character::getNumericValue)
                    .toArray();

            new_num = 0;
            for (int i = 0 ; i < digits.length ; ++i)
                new_num += digits[i]*rems[i%6];
        }

        return new_num;
    }

}