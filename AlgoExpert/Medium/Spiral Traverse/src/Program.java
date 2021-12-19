import java.util.*;

class Program {
    public static List<Integer> spiralTraverse(int[][] array) {
        List<Integer> retList = new ArrayList<>();
        int startCol = 0, endCol = array[0].length - 1, startRow = 0, endRow = array.length - 1;
        int row, col;
        while (startCol <= endCol && startRow <= endRow) {
            for (col = startCol, row = startRow; col <= endCol; col++) {
                retList.add(array[row][col]);
            }
            for (row = startRow + 1, col = endCol; row <= endRow; row++) {
                retList.add(array[row][col]);
            }
            for (col = endCol - 1, row = endRow; col >= startCol; col--) {
                if (endRow == startRow) break;
                retList.add(array[row][col]);
            }
            for (row = endRow - 1, col = startCol; row > startRow; row--) {
                if (endCol == startCol) break;
                retList.add(array[row][col]);
            }
            // Update the boundaries
            startRow++; endRow--; startCol++; endCol--;
        }
        return retList;
    }

    public static void main(String[] args) {
        int[][] arr = new int[][] {
                {1,2,3,4},
                {5,6,7,8},
                {9,10,11,12},
                {13,14,15,16}
        };
        spiralTraverse(arr).forEach(num -> System.out.print(num + " "));
    }
}
