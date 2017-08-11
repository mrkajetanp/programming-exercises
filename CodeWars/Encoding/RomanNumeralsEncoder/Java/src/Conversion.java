import javafx.util.Pair;

import java.util.ArrayList;
import java.util.List;

public class Conversion {

    public String solution(int n) {
        List<Pair<Integer, String>> table = new ArrayList<>();
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

        int x = n;
        StringBuilder result = new StringBuilder();

        while (x > 0) {
            int idx = 12;

            while (table.get(idx).getKey() > x) {
                idx--;
            }

            x -= table.get(idx).getKey();
            result.append(table.get(idx).getValue());
        }

        return result.toString();
    }

}