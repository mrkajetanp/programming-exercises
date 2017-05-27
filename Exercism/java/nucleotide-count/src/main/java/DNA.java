import java.util.HashMap;
import java.util.Map;

public class DNA {
    private String chain;
    private Map<Character, Integer> counts;

    public DNA(String chain) {
        this.chain = chain;
        counts = new HashMap<>();
        countOccurrences();
    }

    private void countOccurrences() {
        counts.put('A', 0);
        counts.put('C', 0);
        counts.put('G', 0);
        counts.put('T', 0);

        for (char c : chain.toCharArray()) {
            if (counts.containsKey(c))
                counts.replace(c, counts.get(c)+1);
        }
    }

    public int count(char nucleotide) {
        if (counts.containsKey(nucleotide))
            return counts.get(nucleotide);
        else
            throw new IllegalArgumentException();
    }

    public Map<Character, Integer> nucleotideCounts() {
        return counts;
    }
}
