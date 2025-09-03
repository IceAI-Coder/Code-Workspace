// https://leetcode.com/problems/best-time-to-buy-and-sell-stock/?envType=study-plan-v2&envId=top-interview-150

int maxProfit(int* prices, int pricesSize) {
    if(pricesSize == 1){
        return 0;
    }
    int profit = 0;

    int curr_lowest = 10000;

    for(int i=0; i<pricesSize; i++){
        if(curr_lowest > prices[i]){
            curr_lowest = prices[i];
        }

        if(prices[i] - curr_lowest > profit){
            profit = prices[i] - curr_lowest;
        }

    }
    return profit;
}