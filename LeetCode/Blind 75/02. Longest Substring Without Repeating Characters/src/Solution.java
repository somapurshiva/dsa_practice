import java.util.HashSet;
import java.util.Set;

public class Solution {
    public int lengthOfLongestSubstring(String s) {
        int len = s.length();
        if (len == 0) {
            return 0;
        }
        int currMax = 0, lowPtr = 0, highPtr = 0;
        Set<Character> substr = new HashSet<>(len);
        Character charInContention = null;
        while (highPtr < len && lowPtr < len) {
            if (null != charInContention) {
                char c = s.charAt(lowPtr);
                if (charInContention.equals(c)) {
                    charInContention = null;
                } else {
                    substr.remove(c);
                }
                lowPtr++;
            } else {
                char c = s.charAt(highPtr);
                if (!substr.contains(c)) {
                    substr.add(c);
                    highPtr++;
                } else {
                    charInContention = c;
                    highPtr++;
                    if (currMax < substr.size()) {
                        currMax = substr.size();
                    }
                }
            }
        }
        if (currMax < substr.size()) {
            currMax = substr.size();
        }
        return currMax;
    }

    public static void main(String args[]) {
        Solution s = new Solution();
        System.out.println(s.lengthOfLongestSubstring(" "));
    }
}
