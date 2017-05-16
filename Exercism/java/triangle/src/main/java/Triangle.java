/**
 * Created by cajetan on 5/16/17.
 */
public class Triangle {
    private double sideA;
    private double sideB;
    private double sideC;

    public Triangle(double sideA, double sideB, double sideC) throws TriangleException {
        this.sideA = sideA;
        this.sideB = sideB;
        this.sideC = sideC;

        if (sideA <= 0 || sideB <= 0 || sideC <= 0 ||
                sideA+sideB <= sideC || sideB+sideC <= sideA ||
                sideC+sideA <= sideB) {
            throw new TriangleException();
        }
    }

    public TriangleKind getKind() {
        if (sideA == sideB && sideB == sideC)
            return TriangleKind.EQUILATERAL;

        if (sideA == sideB || sideB == sideC || sideA == sideC)
            return TriangleKind.ISOSCELES;

        return TriangleKind.SCALENE;
    }
}
