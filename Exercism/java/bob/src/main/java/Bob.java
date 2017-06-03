/**
 * Created by cajetan on 6/3/17.
 */

public class Bob {
    public String hey(String message) {
        if (message.isEmpty() || message.chars().allMatch(Character::isWhitespace))
            return "Fine. Be that way!";

        if (message.chars().noneMatch(Character::isAlphabetic)) {
           if (message.endsWith("?"))
               return "Sure.";
           else
               return "Whatever.";
        }

        if (message.chars()
                .allMatch(c -> !(Character.isAlphabetic(c)) ||
                        Character.isUpperCase(c))) {

            return "Whoa, chill out!";
        }

        if (message.endsWith("?"))
            return "Sure.";

        return "Whatever.";
    }
}
