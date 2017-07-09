/**
 * Created by cajetan on 7/9/17.
 */

public class Rainfall {
    public static double mean(String town, String str) {
        String line = "";

        for (String l : str.split("\\r?\\n")) {
            if (l.substring(0, l.indexOf(':')).equals(town)) {
                line = l;
                break;
            }
        }

        if (line.isEmpty())
            return -1;

        int[] temp = line.chars().
                filter(c -> Character.isDigit(c) || c == '.' || c == ',').
                toArray();

        StringBuilder strB = new StringBuilder("");
        for (int i : temp)
            strB.append((char) i);
        line = strB.toString();

        double sum = 0;
        for (String num : line.split(","))
            sum += Double.parseDouble(num);

        return sum/12.0;
    }

    public static double variance(String town, String str) {
        String line = "";
        double rainMean = mean(town, str);

        for (String l : str.split("\\r?\\n")) {
            if (l.substring(0, l.indexOf(':')).equals(town)) {
                line = l;
                break;
            }
        }

        if (line.isEmpty())
            return -1;

        int[] temp = line.chars().
                filter(c -> Character.isDigit(c) || c == '.' || c == ',').
                toArray();

        StringBuilder strB = new StringBuilder("");
        for (int i : temp)
            strB.append((char) i);
        line = strB.toString();

        double sum = 0;
        for (String num : line.split(","))
            sum += Math.pow(Double.parseDouble(num)-rainMean, 2);

        return sum/12.0;
    }
}