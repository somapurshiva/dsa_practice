import java.util.*;

class Program {
    public static int minNumberOfCoinsForChange(int n, int[] denoms) {
        int[] minCoins = new int[n + 1];
        Arrays.fill(minCoins, Integer.MAX_VALUE);
        minCoins[0] = 0;
        for (int denom: denoms) {
            for (int amt = 1; amt < n + 1; amt++) {
                if (denom <= amt) {
                    int compare = minCoins[amt - denom] == Integer.MAX_VALUE ? minCoins[amt - denom] : minCoins[amt - denom] + 1;
                    minCoins[amt] = Math.min(minCoins[amt], compare);
                }
            }
        }
        return minCoins[n] == Integer.MAX_VALUE ? -1 : minCoins[n];
    }

    public static void main(String[] args) {
        System.out.print(minNumberOfCoinsForChange(7, new int[] {1,5,10}));
    }
}
