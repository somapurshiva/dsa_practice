class Solution {
    public boolean isPalindrome(String s) {
        int leftPtr = 0, rightPtr = s.length() - 1;
        while (leftPtr <= rightPtr) {
            char leftChar = s.charAt(leftPtr);
            char rightChar = s.charAt(rightPtr);

            if (!((leftChar >= 'a' && leftChar <= 'z') || (leftChar >= 'A' && leftChar <= 'Z') || (leftChar >= '0' && leftChar <= '9'))) {
                leftPtr++;
                continue;
            }
            if (!((rightChar >= 'a' && rightChar <= 'z') || (rightChar >= 'A' && rightChar <= 'Z') || (rightChar >= '0' && rightChar <= '9'))) {
                rightPtr--;
                continue;
            }
            if (leftChar == rightChar || (((leftChar - 'a' == rightChar - 'A') || (leftChar - 'A' == rightChar - 'a'))
                    && (!(leftChar >= '0' && leftChar <= '9') && !(rightChar >= '0' && rightChar <= '9')))) {
                leftPtr++;
                rightPtr--;
            } else return false;
        }
        return true;
    }

    public static void main(String[] args) {
        Solution s = new Solution();
        System.out.println(s.isPalindrome("0P"));
    }
}