import java.util.HashSet;

/**
 * Created by cajetan on 5/28/17.
 */
public class Robot {
    private HashSet<String> namesInUse;
    private String name;

    public Robot() {
        namesInUse = new HashSet<>();
        name = generateName();

        while (namesInUse.contains(name))
            name = generateName();

        namesInUse.add(name);
    }

    private String generateName() {
        StringBuilder result = new StringBuilder();

        result.append((char)(65 + Math.random() * 26));
        result.append((char)(65 + Math.random() * 26));
        result.append((int)(100 + Math.random() * 899));

        return result.toString();
    }

    public String getName() {
        return name;
    }

    public void reset() {
        while (namesInUse.contains(name))
            name = generateName();

        namesInUse.add(name);
    }
}
