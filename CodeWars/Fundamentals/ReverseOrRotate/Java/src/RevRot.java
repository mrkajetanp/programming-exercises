
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

        return "";
    }

}