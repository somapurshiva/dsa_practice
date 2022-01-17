import java.util.HashSet;
import java.util.Set;

class Solution {
    int size;

    public int totalNQueens(int n) {
        size = n;
        return backtrack(0, new HashSet<>(), new HashSet<>(), new HashSet<>());
    }

    private int backtrack(int rowIdx, Set<Integer> col, Set<Integer> diagonal, Set<Integer> antiDiagonal) {
        // If we have crossed all the rows, we have a solution. Thus, we can return the solution as 1
        if (rowIdx == size)
            return 1;
        int solutions = 0;
        // Go through all the columns and evaluate
        for (int colIdx = 0; colIdx < size; colIdx++) {
            int diagonalIdx = rowIdx - colIdx;
            int antiDiagonalIdx = rowIdx + colIdx;
            // If the current indices are already present on the hash sets, we cannot place the queen in the current column
            if (col.contains(colIdx) || diagonal.contains(diagonalIdx) || antiDiagonal.contains(antiDiagonalIdx))
                continue;
            // If we are able to place the queen at the current column, update the hash sets to track the affected places and call the next recursion
            col.add(colIdx);
            diagonal.add(diagonalIdx);
            antiDiagonal.add(antiDiagonalIdx);

            // Call the next recursion to get the number of solutions from this position
            solutions += backtrack(rowIdx + 1, col, diagonal, antiDiagonal);

            // Once we have the solutions from current state, we need to backtrack back. Hence, clearing the current affected places from the Hash sets
            col.remove(colIdx);
            diagonal.remove(diagonalIdx);
            antiDiagonal.remove(antiDiagonalIdx);
        }
        return solutions;
    }

    public static void main(String[] args) {
        Solution s = new Solution();
        for (int i = 0; i < 10; i++) {
            System.out.println(s.totalNQueens(i));
        }
    }
}