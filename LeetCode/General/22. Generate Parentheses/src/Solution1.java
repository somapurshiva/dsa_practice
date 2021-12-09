import java.util.*;

public class Solution1 {
    public List<String> generateParenthesis(int n) {
//        return bruteForceApproach(n);
        return backtrackingApproach(n);
    }

    private List<String> backtrackingApproach(int n) {
        List<String> retList = new ArrayList<>();
        backtrack(retList, new StringBuilder(), 0, 0, n);
        return retList;
    }

    private void backtrack(List<String> results, StringBuilder intermediateStr, int open, int close, int max) {
        if (intermediateStr.length() == max * 2)
            results.add(intermediateStr.toString());
        if (open < max) {
            intermediateStr.append('(');
            backtrack(results, intermediateStr, open + 1, close, max);
            intermediateStr.deleteCharAt(intermediateStr.length() - 1);
        }
        if (close < open) {
            intermediateStr.append(')');
            backtrack(results, intermediateStr, open, close + 1, max);
            intermediateStr.deleteCharAt(intermediateStr.length() - 1);
        }
    }

    private List<String> bruteForceApproach(int n) {
        List<String> retList = new ArrayList<>();
        generateAll(new char[2 * n], 0, retList);
        return retList;
    }

    private void generateAll(char[] chars, int pos, List<String> results) {
        if (pos == chars.length) {
            if (isValid(chars))
                results.add(new String(chars));
        } else {
            chars[pos] = '(';
            generateAll(chars, pos + 1, results);
            chars[pos] = ')';
            generateAll(chars, pos + 1, results);
        }
    }

    private boolean isValid(char[] chars) {
        int balance = 0;
        for (char c : chars) {
            if (c == '(')
                balance++;
            else
                balance--;
            if (balance < 0) return false;
        }
        return balance == 0;
    }

    public static void main(String[] args) {
        Solution1 s = new Solution1();
        System.out.println(s.generateParenthesis(2));
    }
}
