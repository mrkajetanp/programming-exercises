public class BoardCoordinate {
    private int x;
    private int y;

    public BoardCoordinate(int x, int y) {
        if (x < 0)
            throw new IllegalArgumentException("Coordinate must have positive rank.");

        if (x > 7)
            throw new IllegalArgumentException("Coordinate must have rank <= 7.");

        if (y < 0)
            throw new IllegalArgumentException("Coordinate must have positive file.");

        if (y > 7)
            throw new IllegalArgumentException("Coordinate must have file <= 7.");

        this.x = x;
        this.y = y;
    }

    public int getX() {
        return x;
    }

    public int getY() {
        return y;
    }

    @Override
    public boolean equals(Object o) {
        if (this == o)
            return true;

        if (o == null || getClass() != o.getClass())
            return false;

        BoardCoordinate that = (BoardCoordinate) o;

        if (x != that.x)
            return false;

        return y == that.y;
    }

    @Override
    public int hashCode() {
        int result = x;
        result = 31 * result + y;
        return result;
    }
}
