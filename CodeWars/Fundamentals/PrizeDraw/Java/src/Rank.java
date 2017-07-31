import javafx.util.Pair;
import java.util.ArrayList;
import java.util.List;

/**
 * Created by cajetan on 31/07/2017.
 */

class Rank {
    public static int rankName(String name) {
        return name.length() + name.toLowerCase().chars()
                .map(c -> c - 'a' + 1).sum();
    }

    public static String nthRank(String st, Integer[] we, int n) {
        if (st.isEmpty())
            return "No participants";

        String[] nameArr = st.split(",");

        if (n > nameArr.length)
            return "Not enough participants";

        List<Pair<String, Integer>> names = new ArrayList<>();
        for (int i = 0; i < nameArr.length; i++)
            names.add(new Pair<>(nameArr[i], rankName(nameArr[i])*we[i]));

        names.sort((p1, p2) -> {
            if (p1.getValue().equals(p2.getValue()))
                return p1.getKey().compareTo(p2.getKey());
            else
                return p2.getValue().compareTo(p1.getValue());
        });

        return names.get(n-1).getKey();
    }
}
