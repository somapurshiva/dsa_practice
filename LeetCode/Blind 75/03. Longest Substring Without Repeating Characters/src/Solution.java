import java.util.HashSet;
import java.util.Set;

public class Solution {
    public int lengthOfLongestSubstringComplex(String s) {
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

    public int lengthOfLongestSubstring(String s) {
        // Keep Two pointers. Evaluate the string between pointers. If the last occurrence of current char happens within the sliding window, we need to slide the left pointer to one position to the right of the duplicate char
        int leftPtr = 0, rightPtr = 0, maxLength = 0;
        // Array will hold the last position in the String for the ASCII char
        Integer[] lastPosArr = new Integer[128];
        while (rightPtr < s.length()) {
            char c = s.charAt(rightPtr);
            // Check if the current char has already appeared in the window. If so, we need to slide it
            Integer lastPos = lastPosArr[c];
            if (lastPos != null && lastPos >= leftPtr && lastPos < rightPtr) leftPtr = lastPos + 1;
            lastPosArr[c] = rightPtr;
            maxLength = Math.max(maxLength, rightPtr - leftPtr + 1);
            rightPtr++;
        }
        return maxLength;
    }

    public static void main(String args[]) {
        Solution s = new Solution();
        System.out.println(s.lengthOfLongestSubstring("abcdba"));
    }
}
