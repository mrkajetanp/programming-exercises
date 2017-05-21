import java.util.ArrayList;
import java.util.Collections;
import java.util.List;

final class DiamondPrinter {
    public List<String> printToList(char letter) {
        if (letter == 'A')
            return Collections.singletonList("A");

        List<String> result = new ArrayList<>();

        int side_spaces = letter - 65;
        int inside_spaces = 0;
        char curr_letter = 'A';

        // first line
        StringBuilder line = new StringBuilder("");

        for (int i = 0 ; i < side_spaces ; ++i)
            line.append(' ');

        line.append(curr_letter);

        for (int i = 0 ; i < side_spaces ; ++i)
            line.append(' ');

        result.add(line.toString());

        side_spaces--;
        inside_spaces++;
        curr_letter++;

        // lines up to the middle
        for (int i = 0 ; i < letter-65 ; ++i) {
            line.setLength(0);

            for (int j = 0 ; j < side_spaces ; ++j)
                line.append(' ');

            line.append(curr_letter);

            for (int j = 0 ; j < inside_spaces ; ++j)
                line.append(' ');

            line.append(curr_letter);

            for (int j = 0 ; j < side_spaces ; ++j)
                line.append(' ');

            result.add(line.toString());

            side_spaces--;
            inside_spaces += 2;
            curr_letter++;
        }

        // lines down from the middle
        for (int i = letter-65 ; i > 0 ; --i) {
            result.add(result.get(i-1));
        }

        return result;
    }
}
