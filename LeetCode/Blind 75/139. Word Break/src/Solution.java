import java.util.*;

class Solution {
    public boolean wordBreak(String s, List<String> wordDict) {
//        return bruteForce(s, wordDict);
//        return memoization(s, wordDict);
//        return bfs(s, wordDict);
        return dp(s, wordDict);
    }

    private boolean bruteForce(String s, List<String> wordDict) {
        return wordSearchRecur(s, new HashSet<>(wordDict), 0);
    }

    private boolean wordSearchRecur(String s, Set<String> wordDict, int start) {
        if (start == s.length())
            return true;

        for (int end = start + 1; end <= s.length(); end++) {
            if (wordDict.contains(s.substring(start, end)) && wordSearchRecur(s, wordDict, end)) {
                return true;
            }
        }
        return false;
    }

    private boolean memoization(String s, List<String> wordDict) {
        return wordMemo(s, new HashSet<>(wordDict), 0, new Boolean[s.length()]);
    }

    private boolean wordMemo(String s, Set<String> wordDict, int start, Boolean[] memo) {
        if (start == s.length())
            return true;
        if (memo[start] != null)
            return memo[start];
        for (int end = start + 1; end <= s.length(); end++) {
            if (wordDict.contains(s.substring(start, end)) && wordMemo(s, wordDict, end, memo)) {
                return memo[start] = true;
            }
        }
        return memo[start] = false;
    }

    private boolean bfs(String s, List<String> wordDict) {
        Set<String> wordDictSet = new HashSet<>(wordDict);
        Queue<Integer> queue = new ArrayDeque<>();
        boolean[] visited = new boolean[s.length()];

        // Start at index 0
        queue.add(0);
        while (!queue.isEmpty()) {
            int start = queue.poll();
            if (visited[start])
                continue;
            for (int end = start + 1; end <= s.length(); end++) {
                if (wordDictSet.contains(s.substring(start, end))) {
                    queue.add(end);
                    if (end == s.length())
                        return true;
                }
            }
            visited[start] = true;
        }
        return false;
    }

    private boolean dp(String s, List<String> wordDict) {
        Set<String> wordDictSet = new HashSet<>(wordDict);
        boolean[] dp = new boolean[s.length() + 1];
        dp[0] = true;

        for (int i = 1; i <= s.length(); i++) {
            for (int j = 0; j < i; j++) {
                if (dp[j] && wordDictSet.contains(s.substring(j, i))) {
                    dp[i] = true;
                    break;
                }
            }
        }

        return dp[s.length()];
    }

    public static void main(String[] args) {
        Solution s = new Solution();
        System.out.println(s.wordBreak("applepenapple", Arrays.asList("apple","pen")));
        System.out.println(s.wordBreak("catsandog", Arrays.asList("cats","dog","sand","and","cat")));
        System.out.println(s.wordBreak("leetcode", Arrays.asList("leet","code")));
    }
}