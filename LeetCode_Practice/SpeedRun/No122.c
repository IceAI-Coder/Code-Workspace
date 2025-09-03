// https://leetcode.com/problems/best-time-to-buy-and-sell-stock-ii/?envType=study-plan-v2&envId=top-interview-150

int maxProfit(int* prices, int pricesSize) {
    if(pricesSize == 1){
        return 0;
    }

    int index_localMin = -1;
    int index_localHigh = -1;

    int profit = 0;
    int curr_profit = 0;
    for(int i=0; i<pricesSize; i++){
        // find local min first then find local high
        if(index_localMin == -1){
            index_localMin = i;
        }
        else{
            // Alreay have local min value, try to find local high
            // if new value smaller than local min, then save this new value as local min
            // if new value higher than local min, then it will be local high
            
            if(index_localHigh == -1){
                if(prices[i] < prices[index_localMin]){
                    index_localMin = i;
                }
                else if(prices[i] > prices[index_localMin]){
                    index_localHigh = i;
                }
            }
            else{
                if(prices[i] < prices[index_localHigh]){
                    profit += (prices[index_localHigh] - prices[index_localMin]);
                    index_localMin = i;
                    index_localHigh = -1;
                }
                else if(prices[i] > prices[index_localHigh]){
                    index_localHigh = i;
                }
            }
        }
    }
    if(index_localMin != -1 && index_localHigh != -1){
        profit += (prices[index_localHigh] - prices[index_localMin]);
    }

    return profit;
}

int main(){
    int p[6] = {7,1,5,3,6,4};
    printf("%d\n", maxProfit(p, 6));
    return 0;
}