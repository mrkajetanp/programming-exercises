/**
 * Created by cajetan on 5/15/17.
 */
public class LuhnValidator {

    public boolean isValid(String number) {
        number = number.trim();
        if (number.length() <= 1)
            return false;

        int sum = 0;

        for (int c : number.chars().filter(c -> !Character.isWhitespace(c)).toArray()) {
            if (!Character.isDigit(c))
                return false;
        }

        int[] digits = number.chars().filter(c -> !Character.isWhitespace(c)).
                map(Character::getNumericValue).toArray();

        // reverse the array
        for (int i = 0 ; i < digits.length/2 ; i++) {
            int temp = digits[i];
            digits[i] = digits[digits.length - i - 1];
            digits[digits.length - i - 1] = temp;
        }

        for (int i = 0 ; i < digits.length ; i++) {
            if (i % 2 != 0) {
                if (digits[i]*2 > 9)
                    sum += digits[i]*2-9;
                else
                    sum += digits[i]*2;
            } else {
                sum += digits[i];
            }
        }

        return sum % 10 == 0;
    }
}
