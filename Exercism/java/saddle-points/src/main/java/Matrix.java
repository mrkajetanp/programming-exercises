import java.util.HashSet;
import java.util.List;
import java.util.Set;

final class Matrix {

    private List<List<Integer>> data;

    public Matrix(List<List<Integer>> data) {
        this.data = data;
    }

    public Set<MatrixCoordinate> getSaddlePoints() {
        Set<MatrixCoordinate> result = new HashSet<>();

        for (List<Integer> list : this.data) {
            for (int i : list) {
                if (i == getMinInColumn(list.indexOf(i)) && i == getMaxInRow(list))
                    result.add(new MatrixCoordinate(data.indexOf(list), list.indexOf(i)));
            }
        }

        return result;
    }

    private int getMinInColumn(int idx) {
        int result = data.get(0).get(idx);

        for (List<Integer> list : data) {
            if (list.get(idx) < result)
                result = list.get(idx);
        }

        return result;
    }

    private int getMaxInRow(List<Integer> list) {
        int result = 0;

        for (int i : list) {
            if (i > result)
                result = i;
        }

        return result;
    }
}
