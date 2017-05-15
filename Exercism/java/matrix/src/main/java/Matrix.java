/**
 * Created by cajetan on 5/15/17.
 */
public class Matrix {
    private int[][] rows;

    public Matrix(String matrix) {
        // split into rows
        String[] mArr = matrix.split("\\r?\\n");
        rows = new int[mArr.length][mArr[0].length()];

        // remove whitespace from each row and convert into int arrays
        for (int i = 0 ; i < mArr.length ; ++i)
            rows[i] = mArr[i].replaceAll("\\s", "").chars().
                    map(Character::getNumericValue).toArray();
    }

    public int getRowsCount() {
        return rows.length;
    }

    public int getColumnsCount() {
        return rows[0].length;
    }

    public int[] getRow(int a) {
        return rows[a];
    }

    public int[] getColumn(int a) {
        int[] result = new int[rows.length];

        for (int i = 0 ; i < rows.length ; ++i)
            result[i] += rows[i][a];

        return result;
    }
}
