/**
 * Created by cajetan on 5/9/17.
 */

public class Acronym {
    private String phrase;
    private String acronym;

    public Acronym(String phrase) {
        this.phrase = phrase;

        makeAcronym();
    }

   public String get() {
        return acronym;
   }

   private void makeAcronym() {
        StringBuilder result = new StringBuilder("");

        for (String word: phrase.replace('-', ' ').split(" ")) {
            if (word.chars().filter(Character::isAlphabetic).
                    allMatch(Character::isUpperCase)) {

                result.append(word.charAt(0));
            } else {
                result.append(Character.toUpperCase(word.charAt(0)));

                for (int c : word.chars().skip(1).filter(Character::isUpperCase).toArray()) {
                    result.append((char)c);
                }
            }
        }

        this.acronym = result.toString();
   }
}
