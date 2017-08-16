/**
 * Created by cajetan on 16/08/2017.
 */

import java.util.*;
import java.util.stream.Collectors;

public class Tour {

    private static int idxFriend(String[][] ftwns, String str) {

        for (int i = 0 ; i < ftwns.length ; ++i) {
            if (ftwns[i][0].equals(str))
                return i;
        }

        return -1;
    }

    public static int tour(String[] arrFriends, String[][] ftwns, Map<String, Double> h) {
        List<String> lFriends = Arrays.stream(arrFriends).
                filter(s -> idxFriend(ftwns, s) != -1).collect(Collectors.toList());

        double sum = h.get(ftwns[idxFriend(ftwns, lFriends.get(0))][1]);

        for (int i = 0 ; i < lFriends.size()-1 ; ++i) {
            double d1 = h.get(ftwns[idxFriend(ftwns, lFriends.get(i+1))][1]);
            double d2 = h.get(ftwns[idxFriend(ftwns, lFriends.get(i))][1]);

            sum += Math.sqrt(d1*d1-d2*d2);
        }

        sum += h.get(ftwns[idxFriend(ftwns, lFriends.get(lFriends.size()-1))][1]);
        return (int)Math.floor(sum);
    }
}

