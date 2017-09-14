
class RevRot {

    private static boolean ifReverse(String str) {
        return str.chars()
                .mapToDouble(c -> Math.pow(Character.getNumericValue(c), 3))
                .sum()%2 == 0;
    }

    private static String rotate(String str) {
        return str.substring(1) + str.charAt(0);
    }

    public static String revRot(String str, int sz) {
        if (sz <= 0 || sz > str.length())
            return "";

        StringBuilder result = new StringBuilder();

        int idx = 0;
        while (idx <= str.length()) {
            String temp = str.substring(idx, idx+sz);

            if (ifReverse(temp))
                result.append(new StringBuilder(temp).reverse().toString());
            else
                result.append(rotate(temp));

            idx += sz;
            if (idx+sz > str.length())
                break;
        }

        return result.toString();
    }

}