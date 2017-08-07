/**
 * Created by cajetan on 22/07/2017.
 */

class LongestConsec {

    public static String longestConsec(String[] strarr, int k) {
        if (strarr.length == 0 || k > strarr.length || k <= 0)
            return "";

        int max_len = 0;
        int long_idx = 0;

        for (int i = 0 ; i < strarr.length-k+1 ; ++i) {
            int temp_len = 0;

            for (int j = 0 ; j < k ; ++j)
                temp_len += strarr[i+j].length();

            if (temp_len > max_len) {
                max_len = temp_len;
                long_idx = i;
            }
        }

        StringBuilder result = new StringBuilder();

        for (int i = 0 ; i < k ; ++i)
            result.append(strarr[long_idx+i]);

        return result.toString();
    }

}