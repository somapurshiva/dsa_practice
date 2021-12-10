import java.util.*;

class Program {

    public boolean generateDocument(String characters, String document) {
        Map<Character, Integer> keyMap = new HashMap<>();
        for (char c : characters.toCharArray())
            keyMap.put(c, keyMap.getOrDefault(c, 0)+1);
        for (char c : document.toCharArray()) {
            if (!keyMap.containsKey(c) || keyMap.get(c) == 0)
                return false;
            keyMap.put(c, keyMap.get(c)-1);
        }
        return true;
    }

    public static void main(String[] args) {
        Program p = new Program();
        System.out.println(p.generateDocument("Bste!hetsi ogEAxpelrt x ", "AlgoExpert is the Best!"));
    }
}
