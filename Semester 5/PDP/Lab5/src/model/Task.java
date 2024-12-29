package model;


public final class Task implements Runnable {
    private final int start;
    private final int end;
    private final Polynomial p1;
    private final Polynomial p2;
    private final Polynomial result;

    public Task(int start, int end, Polynomial p1, Polynomial p2, Polynomial result) {
        this.start = start;
        this.end = end;
        this.p1 = p1;
        this.p2 = p2;
        this.result = result;
    }

    @Override
    public void run() {
        for (int index = start; index < end; index++) {
            //case - no more elements to calculate
            if (index > result.getCoefficients().size()) {
                return;
            }
            // find all pairs of terms from p1 and p2 whose degrees sum to the current index
            for (int j = 0; j <= index; j++) {
                if (j < p1.getCoefficients().size() && (index - j) < p2.getCoefficients().size()) {
                    int value = p1.getCoefficients().get(j) * p2.getCoefficients().get(index - j);
                    result.getCoefficients().set(index, result.getCoefficients().get(index) + value);
                }
            }
        }
    }
}