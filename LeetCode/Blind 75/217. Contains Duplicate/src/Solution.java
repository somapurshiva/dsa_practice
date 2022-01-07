import java.util.HashSet;
import java.util.Set;

class Solution {
    public boolean containsDuplicate(int[] nums) {
        Set<Integer> elements = new HashSet<>(nums.length);
        for (int num : nums) {
            if (elements.contains(num))
                return true;
            elements.add(num);
        }
        return false;
    }
}
