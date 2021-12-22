import java.util.*;

class Program {
    public static int numberOfWaysToMakeChange(int n, int[] denoms) {
//        Integer currCount = 0;
//        for (int i = 0; i < denoms.length; i++) {
//            if (updateCount(i, n, denoms)) currCount++;
//        }
//        return currCount;
        int[] ways = new int[n + 1];
        // Base case: to reach a count of 0, we have to choose no coins. Thus, one way to select the coins.
        ways[0] = 1;
        for (int denom : denoms) {
            for (int amt = 1; amt < n + 1; amt++) {
                if (denom <= amt) {
                    ways[amt] += ways[amt - denom];
                }
            }
        }
        return ways[n];
    }

    private static boolean updateCount(int idx, int targetSum, int[] denoms) {
        if (idx == -1)
            return false;
        // If targetSum is less than current denom, no point in continuing
        if (targetSum / denoms[idx] == 0)
            return updateCount(idx - 1, targetSum % denoms[idx], denoms);
        // First check if the targetSum can be completely divided by the current denomination, if so the currCount can be updated and we can return
        if (targetSum % denoms[idx] == 0) {
            return true;
        }
        // Otherwise, grab the max coins you can from the current denom and recursively call the same function with reduced targetSum fro the previous index
        else {
            return updateCount(idx - 1, targetSum % denoms[idx], denoms);
        }
    }

    public static void main (String[] args) {
        System.out.print(numberOfWaysToMakeChange(9, new int[]{5}));
    }
}
