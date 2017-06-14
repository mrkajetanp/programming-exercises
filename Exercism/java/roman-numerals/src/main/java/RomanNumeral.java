import javafx.util.Pair;

import java.util.ArrayList;
import java.util.Vector;

/**
 * Created by cajetan on 6/14/17.
 */
public class RomanNumeral {
    private int arabicNumeral;
    private String romanNumeral;

    public RomanNumeral(int arabicNumeral) {
        this.arabicNumeral = arabicNumeral;

        convert();
    }

    private void convert() {
        Vector<Pair<Integer, String>> table = new Vector<>();
        table.add(new Pair<>(1, "I"));
        table.add(new Pair<>(4, "IV"));
        table.add(new Pair<>(5, "V"));
        table.add(new Pair<>(9, "IX"));
        table.add(new Pair<>(10, "X"));
        table.add(new Pair<>(40, "XL"));
        table.add(new Pair<>(50, "L"));
        table.add(new Pair<>(90, "XC"));
        table.add(new Pair<>(100, "C"));
        table.add(new Pair<>(400, "CD"));
        table.add(new Pair<>(500, "D"));
        table.add(new Pair<>(900, "CM"));
        table.add(new Pair<>(1000, "M"));

        StringBuilder result = new StringBuilder();
        int x = this.arabicNumeral;

        while (x > 0) {
            int idx = 12;

            while (table.get(idx).getKey() > x)
                idx--;

            x -= table.get(idx).getKey();
            result.append(table.get(idx).getValue());
        }

        this.romanNumeral = result.toString();
    }

    public String getRomanNumeral() {
        return this.romanNumeral;
    }
}
