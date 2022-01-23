import java.util.ArrayList;
import java.util.HashMap;
import java.util.List;
import java.util.Map;

class Solution {
    public String minWindow(String s, String t) {
        // If either of the strings are empty, we won't have a match. return blank in that case
        if (s.length() == 0 || t.length() == 0)
            return "";
        // Form the map containing al the chars in T and their counts
        Map<Character, Integer> dicT = new HashMap<>(t.length());
        for (int i = 0; i < t.length(); i++) {
            int count = dicT.getOrDefault(t.charAt(i), 0);
            dicT.put(t.charAt(i), count + 1);
        }
        // Create a int variable that holds the total unique characters in T which will help us compare the window counts with dicT counts
        int required = dicT.size();

        // Form the filteredS counts
        List<Pair<Integer, Character>> filteredS = new ArrayList<>();
        for (int i = 0; i < s.length(); i++) {
            char chr = s.charAt(i);
            if (dicT.containsKey(chr)) {
                filteredS.add(new Pair<>(i, chr));
            }
        }

        // Declare the variables that will be used to evaluate the current window to check if all chars are available in T or now
        int l = 0, r = 0, formed = 0;
        int[] ans = {-1, 0, 0};
        Map<Character, Integer> windowCounts = new HashMap<>();

        // We will scan the filteredS list as it is the relevant subset and try to form initial window, further expanding and contracting that window to get our right answer
        while (r < filteredS.size()) {
            char c = filteredS.get(r).getValue();
            int count = windowCounts.getOrDefault(c, 0);
            windowCounts.put(c, count + 1);

            // Check if the current window count for the current character is the same as the count in dicT. If so, increment formed to move closer to the required count
            if (dicT.containsKey(c) && windowCounts.get(c).intValue() == dicT.get(c).intValue())
                formed++;

            // Now, contract the window till the point it becomes undesirable i.e. formed < required
            while (l <= r && formed == required) {
                c = filteredS.get(l).getValue();

                // Find the smallest window till now
                int start = filteredS.get(l).getKey();
                int end = filteredS.get(r).getKey();
                if (ans[0] == -1 || end - start + 1 < ans[0]) {
                    ans[0] = end - start + 1;
                    ans[1] = start;
                    ans[2] = end;
                }
                // Before contracting the window by incrementing l, update the "formed" variable by comparing the current char at l and its count with the dicT
                windowCounts.put(c, windowCounts.get(c) - 1);
                if (dicT.containsKey(c) && windowCounts.get(c) < dicT.get(c))
                    formed--;

                l++;
            }

            r++;
        }

        return ans[0] == -1 ? "" : s.substring(ans[1], ans[2] + 1);
    }

    public static void main(String[] args) {
        Solution s = new Solution();
        System.out.println(s.minWindow("ADOBECODEBANC", "ABC"));
    }
}

class Pair <V,T> {
    private V key;
    private T value;

    Pair(V key, T value) {
        this.key = key;
        this.value = value;
    }

    public V getKey() {
        return key;
    }

    public T getValue() {
        return value;
    }
}
