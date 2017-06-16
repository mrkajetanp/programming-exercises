import java.util.Collections;

public class RunLengthEncoding {
    public String encode(String data) {
        StringBuilder result = new StringBuilder();

        if (data.isEmpty())
            return result.toString();

        int count = 1;
        char currChar = data.charAt(0);

        for (int i = 1 ; i < data.length() ; ++i) {
            if (data.charAt(i) != currChar) {
                if (count != 1)
                    result.append(count);
                result.append(currChar);

                currChar = data.charAt(i);
                count = 1;
            } else {
                count++;
            }
        }

        if (count != 1)
            result.append(count);
        result.append(currChar);

        return result.toString();
    }

    public String decode(String encodedData) {
        StringBuilder result = new StringBuilder();

        if (encodedData.isEmpty())
            return result.toString();

        StringBuilder number = new StringBuilder();

        for (char c : encodedData.toCharArray()) {
            if (Character.isDigit(c)) {
                number.append(c);
            } else {
                if (number.length() != 0) {
                    result.append(String.join("",
                            Collections.nCopies(Integer.parseInt(number.toString()),
                                    String.valueOf(c))));
                } else {
                    result.append(c);
                }
                number.setLength(0);
            }
        }

        return result.toString();
    }
}
