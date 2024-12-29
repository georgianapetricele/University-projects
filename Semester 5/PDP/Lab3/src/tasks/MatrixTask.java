package tasks;

import model.Matrix;

import java.util.AbstractMap;
import java.util.ArrayList;
import java.util.List;

public abstract class MatrixTask extends Thread{
    protected final List<AbstractMap.SimpleEntry<Integer, Integer>> elements;
    protected final int startRow, startColumn, elementCount;
    protected final Matrix A, B, C;
    protected int K;

    public MatrixTask (int startRow, int startColumn, int elementCount, Matrix A, Matrix B, Matrix C){
        this.startRow = startRow;
        this.startColumn = startColumn;
        this.elementCount = elementCount;
        this.A = A;
        this.B = B;
        this.C = C;
        this.elements = new ArrayList<>();
        computeElements();
    }

    public MatrixTask (int startRow, int startColumn, int elementCount, int K, Matrix A, Matrix B, Matrix C){
        this.startRow = startRow;
        this.startColumn = startColumn;
        this.elementCount = elementCount;
        this.K = K;
        this.A = A;
        this.B = B;
        this.C = C;
        this.elements = new ArrayList<>();
        computeElements();
    }

    protected abstract void computeElements();

    public int computeMatrixElement(Matrix A, Matrix B, int row, int column) {
        int result = 0;
        if (row < A.rows() && column < B.columns()) {
            int i = 0;
            while (i < A.columns()) {
                result += A.get(row, i) * B.get(i, column);
                i++;
            }
            return result;
        } else {
            throw new IllegalArgumentException();
        }
    }

    @Override
    public void run() {
        for (AbstractMap.SimpleEntry<Integer, Integer> element : elements) {
            int row = element.getKey();
            int column = element.getValue();
            C.set(row, column, computeMatrixElement(A, B, row, column));
        }
    }
}