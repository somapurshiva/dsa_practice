class Solution {
    public int maxProfit(int[] prices) {
        int maxProfit = 0;
        int minBuy = prices[0];
        for (int price : prices) {
            if (price < minBuy)
                minBuy = price;
            int currProfit = price - minBuy;
            if (currProfit > maxProfit)
                maxProfit = currProfit;
        }
        return maxProfit;
    }
}