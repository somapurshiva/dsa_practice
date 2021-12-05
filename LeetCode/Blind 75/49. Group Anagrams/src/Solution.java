import java.util.*;

public class Solution {
    public List<List<String>> groupAnagrams(String[] strs) {
        // Create a HashMap that will store the sorted char array string as key and all matching strings as a value
        Map<String, List<String>> retMap = new HashMap<>(strs.length);
        for (String str : strs) {
            // Convert the incoming string as a char array and sort the input to form a new String
            char[] chars = str.toCharArray();
            Arrays.sort(chars);
            String keyStr = new String(chars);
            retMap.computeIfAbsent(keyStr, k -> new ArrayList<>());
            retMap.get(keyStr).add(str);
        }
        return new ArrayList<>(retMap.values());
    }

    public static void main(String[] args) {
        String[] arr = {"eat","tea","tan","ate","nat","bat"};
        Solution s = new Solution();
        System.out.println(s.groupAnagrams(arr));
    }
}
