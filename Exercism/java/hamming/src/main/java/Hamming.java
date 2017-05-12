public class Hamming {
    private String s1;
    private String s2;

    public Hamming(String s1, String s2) {

        if (s1.length() != s2.length())
            throw new IllegalArgumentException();

        this.s1 = s1;
        this.s2 = s2;
    }

    public int getHammingDistance() {
        int hamming = 0;

        for (int i = 0 ; i < s1.length() ; i++) {
            if (s1.charAt(i) != s2.charAt(i))
                hamming++;
        }

        return hamming;
    }
}
