import java.util.*;

/**
 * Created by cajetan on 6/21/17.
 */
public class School {
    private HashMap<String, Integer> studentGrades;

    public School() {
        this.studentGrades = new HashMap<>();
    }

    public int numberOfStudents() {
        return this.studentGrades.size();
    }

    public void add(String name, int grade) {
        this.studentGrades.put(name, grade);
    }

    public List<String> grade(int x) {
        List<String> result = new ArrayList<>();

        this.studentGrades.forEach((k, v) -> {
            if (v == x)
                result.add(k);
        });

        return result;
    }

    public Map<Integer, List<String>> studentsByGradeAlphabetical() {
        HashMap<Integer, List<String>> result = new HashMap<>();

        for (int grade : this.studentGrades.values()) {
            List<String> gradeList = new ArrayList<>();

            this.studentGrades.forEach((k, v) -> {
                if (v == grade)
                    gradeList.add(k);
            });

            result.put(grade, gradeList);
            Collections.sort(gradeList);
        }

        return result;
    }

}
