/**
 * Created by cajetan on 31/07/2017.
 */

import static org.junit.Assert.*;
import org.junit.Test;

public class RankTest {

    @Test
    public void test() {
        System.out.println("Fixed Tests");
        String st = "";
        Integer[] we = new Integer[] {4, 2, 1, 4, 3, 1, 2};
        assertEquals("No participants", Rank.nthRank(st, we, 4));
        st = "Addison,Jayden,Sofia,Michael,Andrew,Lily,Benjamin";
        we = new Integer[] {4, 2, 1, 4, 3, 1, 2};
        assertEquals("Not enough participants", Rank.nthRank(st, we, 8));
        st = "Addison,Jayden,Sofia,Michael,Andrew,Lily,Benjamin";
        we = new Integer[] {4, 2, 1, 4, 3, 1, 2};
        assertEquals("Benjamin", Rank.nthRank(st, we, 4));
        st = "Elijah,Chloe,Elizabeth,Matthew,Natalie,Jayden";
        we = new Integer[] {1, 3, 5, 5, 3, 6};
        assertEquals("Matthew", Rank.nthRank(st, we, 2));
    }
}
