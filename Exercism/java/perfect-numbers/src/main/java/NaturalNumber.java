import jdk.nashorn.internal.runtime.arrays.IntOrLongElements;

final class NaturalNumber {
    private Classification classification;

    public NaturalNumber(int number) {
        if (number <= 0)
            throw new IllegalArgumentException("You must supply a natural number (positive integer)");

        this.classification = classify(number);
    }

    public Classification getClassification() {
        return classification;
    }

    private Classification classify(int number) {
        int aliquot = aliquotSum(number);

        if (aliquot == number)
            return Classification.PERFECT;
        else if (aliquot > number)
            return Classification.ABUNDANT;
        else
            return Classification.DEFICIENT;
    }

    private int aliquotSum(int num) {
        int result = 0;

        for (int i = 1 ; i < num ; ++i) {
            if (num%i == 0)
                result += i;
        }

        return result;
    }
}
