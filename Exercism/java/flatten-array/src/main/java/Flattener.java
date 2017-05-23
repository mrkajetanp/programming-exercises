import java.util.ArrayList;
import java.util.List;

final class Flattener {

    public <E> ArrayList<E> flatten(List<E> input) {
        ArrayList<E> result = new ArrayList<>();

        for (Object o : input) {
            if (o == null)
                continue;

            if (o instanceof List) {
                System.out.println("List!");
                result.addAll(flatten((List) o));
            } else {
                result.add((E) o);
            }
        }

        return result;
    }

}
