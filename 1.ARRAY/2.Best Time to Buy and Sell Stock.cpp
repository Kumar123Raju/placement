/*
ye question simple hai lekin thoda tricky hai....isme hum phale piche ko maxnumber me store kar lenge.....aur j ko decrement karte jayenge aur jahan 
maxnumber se bada number milega usko maxnumber me store kr denge..sath sath he (maxnumber-arr[j]) kar ke profit nikalte jayenge
leetcode: https://leetcode.com/problems/best-time-to-buy-and-sell-stock/
*/
 int maxProfit(vector<int>& prices) {
        int maxnum=prices[prices.size()-1];
        int maxprofit=0;
        for(int i=prices.size()-1; i>=0; i--){
            if(maxnum<prices[i]) maxnum=prices[i];
            maxprofit=max(maxprofit,maxnum-prices[i]);
        }
        return maxprofit;
        
    }
