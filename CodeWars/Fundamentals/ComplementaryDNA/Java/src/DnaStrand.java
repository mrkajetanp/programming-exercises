/**
 * Created by cajetan on 7/13/17.
 */

public class DnaStrand {
    public static String makeComplement(String dna) {
        return dna.chars().map(c -> {
            switch (c) {
                case 'T':
                    return 'A';

                case 'A':
                    return 'T';

                case 'C':
                    return 'G';

                case 'G':
                    return 'C';

                default:
                    throw new IllegalArgumentException();
            }
        }).collect(StringBuilder::new,
                StringBuilder::appendCodePoint,
                StringBuilder::append).toString();
    }
}