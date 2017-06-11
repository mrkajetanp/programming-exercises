import java.util.ArrayList;
import java.util.List;

public class Series {
    private String series;

    public Series(String series) {
        this.series = series;
    }

    List<Integer> getDigits() {
        List<Integer> result = new ArrayList<>();

        series.chars().forEach(c -> {
            System.out.println("c = " + (char)c);
            result.add(Character.getNumericValue(c));
        });

        return result;
    }

    List<List<Integer>> slices(int len) {
        if (len > series.length())
            throw new IllegalArgumentException();

        List<List<Integer>> result = new ArrayList<>();

        List<Integer> allDigits = getDigits();

        int idx = 0;

        while (idx+len <= allDigits.size()) {
            result.add(allDigits.subList(idx, idx+len));

            idx++;
        }

        return result;
    }
}
