class Solution {
    public String longestPalindrome(String str) {
        int[] longest = new int[] {0,1};
        for (int i = 1; i < str.length(); i++) {
            int[] odd = this.getPalindromeIdxAt(str, i - 1, i + 1);
            int[] even = this.getPalindromeIdxAt(str, i - 1, i);
            int[] currLongest = odd[1] - odd[0] > even[1] - even[0] ? odd : even;
            longest = currLongest[1] - currLongest[0] > longest[1] - longest[0] ? currLongest : longest;
        }
        return str.substring(longest[0], longest[1]);
    }

    private int[] getPalindromeIdxAt(String str, int leftIdx, int rightIdx) {
        while (leftIdx >= 0 && rightIdx < str.length() && str.charAt(leftIdx) == str.charAt(rightIdx)) {
            leftIdx--; rightIdx++;
        }
        return new int[] { leftIdx + 1, rightIdx };
    }
}