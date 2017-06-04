/**
 * Created by cajetan on 6/4/17.
 */
public class PascalsTriangleGenerator {
    public int[][] generateTriangle(int height) {
        if (height < 0)
            throw new IllegalArgumentException();

        if (height == 0)
            return new int[0][];

        int[][] result = new int[height][];

        result[0] = new int[1];
        result[0][0] = 1;

        for (int i = 1 ; i < height ; ++i) {
            result[i] = new int[i+1];
            result[i][0] = 1;
            result[i][i] = 1;

            for (int j = 1 ; j < i ; ++j) {
                result[i][j] = result[i-1][j-1]+result[i-1][j];
            }
        }

        return result;
    }
}
