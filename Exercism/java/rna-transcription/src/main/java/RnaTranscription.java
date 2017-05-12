public class RnaTranscription {
    public String ofDna(String dnaString) {
        StringBuilder result = new StringBuilder("");

        for (char c : dnaString.toCharArray()) {
            switch (c) {
                case 'G':
                    result.append('C');
                    break;

                case 'C':
                    result.append('G');
                    break;

                case 'T':
                    result.append('A');
                    break;

                case 'A':
                    result.append('U');
                    break;
            }
        }

        return result.toString();
    }
}
