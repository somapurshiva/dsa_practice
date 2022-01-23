import java.util.Arrays;

class Solution {
    public int uniquePaths(int m, int n) {
        int[][] pathsArr = new int[m][n];
        for (int[] arr : pathsArr)
            Arrays.fill(arr, 1);
        for (int row = 1; row < m; row++) {
            for (int col = 1; col < n; col++) {
                pathsArr[row][col] = pathsArr[row-1][col] + pathsArr[row][col-1];
            }
        }
        return pathsArr[m-1][n-1];
    }
}