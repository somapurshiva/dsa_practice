public class PalindromicString {
    public String firstPalindrome(String[] words) {
        String retStr = "";
        for (String str : words) {
            if (isPalindrome(str))
                return str;
        }
        return retStr;
    }

    private boolean isPalindrome(String str) {
        int left = 0;
        int right  = str.length() - 1;
        while (left < right) {
            if (str.charAt(left) != str.charAt(right))
                return false;
            left++;
            right--;
        }
        return true;
    }

    public static void main(String[] args) {
        PalindromicString ps = new PalindromicString();
        String[] strArr = new String[] {"abc","car","ada","racecar","cool"};
        System.out.println(ps.firstPalindrome(strArr));
    }
}
