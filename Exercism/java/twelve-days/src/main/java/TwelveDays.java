/**
 * Created by cajetan on 5/20/17.
 */
public class TwelveDays {
    private String[] verseThings;
    private String[] daynums;

    public TwelveDays() {
        verseThings = new String[12];
        verseThings[0] = "a Partridge";
        verseThings[1] = "two Turtle Doves";
        verseThings[2] = "three French Hens";
        verseThings[3] = "four Calling Birds";
        verseThings[4] = "five Gold Rings";
        verseThings[5] = "six Geese-a-Laying";
        verseThings[6] = "seven Swans-a-Swimming";
        verseThings[7] = "eight Maids-a-Milking";
        verseThings[8] = "nine Ladies Dancing";
        verseThings[9] = "ten Lords-a-Leaping";
        verseThings[10] = "eleven Pipers Piping";
        verseThings[11] = "twelve Drummers Drumming";

        daynums = new String[12];
        daynums[0] = "first";
        daynums[1] = "second";
        daynums[2] = "third";
        daynums[3] = "fourth";
        daynums[4] = "fifth";
        daynums[5] = "sixth";
        daynums[6] = "seventh";
        daynums[7] = "eighth";
        daynums[8] = "ninth";
        daynums[9] = "tenth";
        daynums[10] = "eleventh";
        daynums[11] = "twelfth";
    }

    public String verse(int a) {
        StringBuilder result = new StringBuilder();

        result.append("On the " + daynums[a-1] +
                " day of Christmas my true love gave to me, ");

        for (int i = a-1 ; i > 0 ; --i) {
            result.append(verseThings[i] + ", ");
        }

        if (a > 1)
            result.append("and ");

        result.append(verseThings[0]);

        result.append(" in a Pear Tree.\n");
        return result.toString();
    }

    public String verses(int from, int to) {
        StringBuilder result = new StringBuilder("");

        for (int i = from ; i <= to ; ++i)
            result.append(verse(i) + '\n');

        result.deleteCharAt(result.length()-1);
        return result.toString();
    }

    public String sing() {
        return verses(1, 12);
    }
}
