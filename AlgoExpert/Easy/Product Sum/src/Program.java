import java.util.*;

class Program {
    // Tip: You can use `element instanceof ArrayList` to check whether an item
    // is an array or an integer.
    public static int productSum(List<Object> array) {
        return productSumLevel(array, 1);
    }

    private static int productSumLevel(List<Object> array, int level) {
        int sum = 0;
        for (Object o : array) {
            if (o instanceof Integer)
                sum += (Integer)o;
            else if(o instanceof List)
                sum += productSumLevel((List<Object>) o, level + 1);
        }
        return sum * level;
    }
}
