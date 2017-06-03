class CollatzCalculator {

    int computeStepCount(int start) {
        if (start <= 0)
            throw new IllegalArgumentException("Only natural numbers are allowed");

        int cnt = 0;

        while (start > 1) {
            if (start%2 == 0) {
                start /= 2;
            } else {
                start *= 3;
                start++;
            }

            cnt++;
        }

        return cnt;
    }

}
