public class Solution {
    public void setZeroes(int[][] matrix) {
        boolean firstColZero = false;

        for (int i = 0; i < matrix.length; i++) {
            if (matrix[i][0] == 0)
                firstColZero = true;
            for (int j = 1; j < matrix[0].length; j++) {
                if (matrix[i][j] == 0) {
                    matrix[i][0] = 0;
                    matrix[0][j] = 0;
                }
            }
        }

        // Update all rows and cols except first
        // Rows
        for (int i = 1; i < matrix.length; i++) {
            if (matrix[i][0] == 0) {
                for (int j = 1; j < matrix[0].length; j++)
                    matrix[i][j] = 0;
            }
        }
        // Cols
        for (int j = 1; j < matrix[0].length; j++) {
            if (matrix[0][j] == 0) {
                for (int i = 1; i < matrix.length; i++)
                    matrix[i][j] = 0;
            }
        }

        // Fix first row and col now
        if (matrix[0][0] == 0) {
            for (int i = 1; i < matrix[0].length; i++)
                matrix[0][i] = 0;
        }
        if (firstColZero) {
            for (int i = 0; i < matrix.length; i++)
                matrix[i][0] = 0;
        }
    }

    public static void main(String[] args) {
        Solution s = new Solution();
        int[][] arr = new int[][] {
                {0,1,2,0},
                {3,4,5,2},
                {1,3,1,5}
        };
        s.setZeroes(arr);
    }
}