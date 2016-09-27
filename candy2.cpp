class Solution {
public:
    int candy(vector<int>& ratings) {
        if (ratings.size() < 1) return 0;
        vector<int> candies(ratings.size(), 1);
        for (int i = 1; i < ratings.size(); i++)
            if (ratings[i] > ratings[i-1]) candies[i] = candies[i-1] + 1;
        int res = candies.back();
        for (int i = ratings.size()-2; i >= 0; i--){
            int temp = 1;
            if (ratings[i] > ratings[i+1]) temp = candies[i+1] + 1;
            res += max(temp, candies[i]);
            candies[i] = temp;
        }
        return res;
    }
};