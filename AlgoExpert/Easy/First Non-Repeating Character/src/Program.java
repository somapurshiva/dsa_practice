import java.util.*;

class Program {

    public int firstNonRepeatingCharacter(String string) {
        Map<Character, Integer> keyMap = new HashMap<>();
        for (int i = 0; i < string.length(); i++) {
            keyMap.put(string.charAt(i), keyMap.getOrDefault(string.charAt(i),0)+1);
        }
        for (int i = 0; i < string.length(); i++) {
            if (keyMap.get(string.charAt(i)) == 1)
                return i;
        }
        return -1;
    }
    public static void main(String[] args) {
        Program p = new Program();
        System.out.println(p.firstNonRepeatingCharacter("abcdcaf"));
    }
}
