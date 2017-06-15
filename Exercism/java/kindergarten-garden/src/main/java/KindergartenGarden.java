import java.util.ArrayList;
import java.util.List;

public class KindergartenGarden {
    private char[] rowOne;
    private char[] rowTwo;

    public KindergartenGarden(String garden, String[] students) {
        String[] temp = garden.split("\\r?\\n");
        rowOne = temp[0].toCharArray();
        rowTwo = temp[1].toCharArray();
    }

    public KindergartenGarden(String garden) {
        String[] temp = garden.split("\\r?\\n");
        rowOne = temp[0].toCharArray();
        rowTwo = temp[1].toCharArray();
    }

    public List<Plant> getPlantsOfStudent(String student) {
        int number = Character.toLowerCase(student.charAt(0)) - 97;
        List<Plant> result = new ArrayList<>();

        result.add(choosePlant(rowOne[number*2]));
        result.add(choosePlant(rowOne[number*2+1]));
        result.add(choosePlant(rowTwo[number*2]));
        result.add(choosePlant(rowTwo[number*2+1]));

        return result;
    }

    private Plant choosePlant(char c) {
        switch (c) {
            case 'R':
                return Plant.RADISHES;

            case 'C':
                return Plant.CLOVER;

            case 'G':
                return Plant.GRASS;

            case 'V':
                return Plant.VIOLETS;
        }

        return null;
    }
}