/**
 * Created by cajetan on 5/25/17.
 */
public class PhoneNumber {
    private String number;

    public PhoneNumber(String number) {
        StringBuilder result = new StringBuilder("");

        for (char c : number.toCharArray()) {
            if (!Character.isDigit(c) && c != '-' && c != ' ' && c != '.' && c != '(' && c != ')')
                throw new IllegalArgumentException("Illegal character in phone number. Only digits, spaces, parentheses, hyphens or dots accepted.");

            if (Character.isDigit(c))
                result.append(c);
        }

        if (result.length() < 10 || result.length() > 11)
            throw new IllegalArgumentException("Number must be 10 or 11 digits");

        if (result.length() > 10 && result.charAt(0) != '1')
            throw new IllegalArgumentException("Can only have 11 digits if number starts with '1'");

        if (result.length() == 11)
            result.deleteCharAt(0);

        this.number = result.toString();
    }

    public String getNumber() {
        return number;
    }
}
