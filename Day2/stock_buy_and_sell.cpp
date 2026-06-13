class Solution {
public:
    int maxProfit(vector<int>& prices) {

        int minPrice = INT_MAX;
        int answer = 0;

        for(int i=0;i<prices.size();i++)
        {
            minPrice = min(minPrice, prices[i]);
            answer = max(answer, prices[i] - minPrice);
        }
        return answer;
    }
};
