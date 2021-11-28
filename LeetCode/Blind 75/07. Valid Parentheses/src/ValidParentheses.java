import java.util.ArrayDeque;
import java.util.Deque;

public class ValidParentheses {
    public boolean isValid(String s) {
        Deque<Character> stack = new ArrayDeque<>(s.length());
        char stackC;
        for (int i = 0; i < s.length(); i++) {
            char c = s.charAt(i);
            if (c == '(' || c == '{' || c == '[') {
                stack.push(c);
            } else if (c == ')' || c == '}' || c == ']') {
                if (stack.isEmpty())
                    return false;
                stackC = stack.pop();
                if ((c == ')' && stackC != '(') || (c == '}' && stackC != '{') || (c == ']' && stackC != '['))
                    return false;
            }
        }
        return stack.isEmpty();
    }

    public static void main(String[] args) {
        ValidParentheses p = new ValidParentheses();
        System.out.println(p.isValid("["));
    }
}
