import java.util.*;

class Program {
    public static boolean balancedBrackets(String str) {
        ArrayDeque<Character> stack = new ArrayDeque<>(str.length());
        Map<Character, Character> brackets = new HashMap<>(3);
        brackets.put(')', '(');
        brackets.put(']', '[');
        brackets.put('}', '{');
        for (char c : str.toCharArray()) {
            if (brackets.containsValue(c))
                stack.push(c);
            else if (brackets.containsKey(c)) {
                if (stack.isEmpty())
                    return false;
                char currC = stack.pop();
                if (currC != brackets.get(c))
                    return false;
            }
        }
        return stack.isEmpty();
    }
}
