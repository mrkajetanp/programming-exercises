/**
 * Created by cajetan on 28/07/2017.
 */

public class BuyCar {

    public static int[] nbMonths(int startPriceOld, int startPriceNew,
                                 int savingperMonth, double percentLossByMonth) {
        if (startPriceOld >= startPriceNew)
            return new int[] { 0, startPriceOld-startPriceNew };

        int month = 1;
        double priceOld = startPriceOld;
        double priceNew = startPriceNew;
        double account = 0.0;

        while (true) {
            if (month%2 == 0)
                percentLossByMonth += 0.5;

            priceOld -= priceOld * (percentLossByMonth/100.0);
            priceNew -= priceNew * (percentLossByMonth/100.0);
            account += savingperMonth;

            if (account+priceOld >= priceNew)
                break;

            month++;
        }

        return new int[] { month, (int)Math.round(account+priceOld-priceNew) };
    }

}