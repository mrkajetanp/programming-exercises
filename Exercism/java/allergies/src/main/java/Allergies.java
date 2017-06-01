import java.util.ArrayList;
import java.util.Collections;

/**
 * Created by cajetan on 6/1/17.
 */
public class Allergies {
    private ArrayList<Allergen> allergens;

    public Allergies(int num) {
        this.allergens = new ArrayList<>();

        if (num >= 256) {
            num -= Integer.highestOneBit(num - 1);
        }

        if (num >= 128) {
            allergens.add(Allergen.CATS);
            num -= 128;
        }

        if (num >= 64) {
            allergens.add(Allergen.POLLEN);
            num -= 64;
        }

        if (num >= 32) {
            allergens.add(Allergen.CHOCOLATE);
            num -= 32;
        }

        if (num >= 16) {
            allergens.add(Allergen.TOMATOES);
            num -= 16;
        }

        if (num >= 8) {
            allergens.add(Allergen.STRAWBERRIES);
            num -= 8;
        }

        if (num >= 4) {
            allergens.add(Allergen.SHELLFISH);
            num -= 4;
        }

        if (num >= 2) {
            allergens.add(Allergen.PEANUTS);
            num -= 2;
        }

        if (num >= 1)
            allergens.add(Allergen.EGGS);

        Collections.reverse(allergens);
    }

    public boolean isAllergicTo(Allergen gen) {
        return allergens.contains(gen);
    }

    public ArrayList<Allergen> getList() {
        return allergens;
    }
}
