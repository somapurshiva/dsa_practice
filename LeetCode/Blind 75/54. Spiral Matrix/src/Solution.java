import java.util.ArrayList;
import java.util.List;

public class Solution {
    public List<Integer> spiralOrder(int[][] matrix) {
        List<Integer> retList = new ArrayList<>();
        int i, j, iMin = 0, jMin = 0, iMax = matrix.length - 1, jMax = matrix[0].length - 1;
        while (true) {
            // First play on the i-axis and vary j from jMin to jMax
                for (j = jMin; j <= jMax; j++)
                    retList.add(matrix[iMin][j]);
                iMin++;
                if (iMin > iMax) break;
            // Next go down the row to reach iMax
                for (i = iMin; i <= iMax; i++)
                    retList.add(matrix[i][jMax]);
                jMax--;
                if (jMin > jMax) break;
            // Next up we go reverse till jMin
                for (j = jMax; j >= jMin; j--)
                    retList.add(matrix[iMax][j]);
                iMax--;
                if (iMin > iMax) break;
                for (i = iMax; i >= iMin; i--)
                    retList.add(matrix[i][jMin]);
                jMin++;
                if (jMin > jMax) break;
        }
        return retList;
    }

    public static void main(String[] args) {
        int[][] matrix = new int[][] {
                {1,2,3,4,5},
                {6,7,8,9,10},
                {11,12,13,14,15},
                {16,17,18,19,20},
                {21,22,23,24,25}

//                {1},{2},{3}

//                {1,2,3,4},
//                {5,6,7,8},
//                {9,10,11,12}

//                {2,5,8},
//                {4,0,-1}

//                {1,2,3},
//                {4,5,6},
//                {7,8,9}
        };
        Solution s = new Solution();
        List<Integer> list = s.spiralOrder(matrix);
        System.out.println(list);
    }
}
