public class QueenAttackCalculator {
    private BoardCoordinate posOne;
    private BoardCoordinate posTwo;

    public QueenAttackCalculator(BoardCoordinate positionOne, BoardCoordinate positionTwo) {
        if (positionOne == null || positionTwo == null)
            throw new IllegalArgumentException("You must supply valid board coordinates for both Queens.");

        if (positionOne.equals(positionTwo))
            throw new IllegalArgumentException("Queens may not occupy the same board coordinate.");

        this.posOne = positionOne;
        this.posTwo = positionTwo;
    }

    public boolean canQueensAttackOneAnother() {
        return (posOne.getX() == posTwo.getX() ||
                posOne.getY() == posTwo.getY() ||
        Math.abs(posOne.getX() - posTwo.getX()) == Math.abs(posOne.getY() - posTwo.getY()));
    }
}
