class Solution {
    private static int ROWS;
    private static int COLS;

    public boolean exist(char[][] board, String word) {
        ROWS = board.length;
        COLS = board[0].length;

        for (int i = 0; i < ROWS; i++) {
            for (int j = 0; j < COLS; j++) {
                if (backtrack(board, i, j, word, 0))
                    return true;
            }
        }
        return false;
    }

    private boolean backtrack(char[][] board, int row, int col, String word, int offset) {
        if (offset == word.length())
            return true;
        if (row < 0 || row == ROWS || col < 0 || col == COLS || board[row][col] != word.charAt(offset))
            return false;

        // If not we will explore
        // If we have come here, we have already matched the letter. Therefore, we can modify the value to non-alpha to not match the cell again
        board[row][col] = '$';
        // Now explore in the 4 directions and if you find the function returning true, return true. Else backtrack
        int[] rowOffsets = { 0, 1, 0, -1 };
        int[] colOffsets = { 1, 0, -1, 0 };

        for (int off = 0; off < 4; off++) {
            if (backtrack(board, row + rowOffsets[off], col + colOffsets[off], word, offset + 1))
                return true;
        }
        // If we have reached here, we could find a match in our exploration. Therefore, backtrack and return false
        board[row][col] = word.charAt(offset);
        return false;
    }
}