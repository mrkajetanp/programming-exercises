import java.util.Arrays;
import java.util.stream.Collectors;

public class WhichAreIn {

    public static String[] inArray(String[] array1, String[] array2) {
        return Arrays.stream(array1)
                .filter(s -> Arrays.stream(array2).anyMatch(st -> st.contains(s)))
                .sorted()
                .collect(Collectors.toList())
                .toArray(new String[0]);
    }

}
