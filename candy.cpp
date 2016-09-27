class Solution {
public:
    int candy(vector<int>& ratings) {
        if (ratings.size() < 1) return 0;
        if (ratings.size() == 1) return 1;
        candies.insert(candies.begin(), ratings.size(), 0);
        // find local minima, allocate 1
        for (int i = 0; i < ratings.size(); i++){
            if (i == 0 && ratings[i] <= ratings[i+1] ||
                i == ratings.size()-1 && ratings[i] <= ratings[i-1] ||
                ratings[i] <= ratings[i+1] && ratings[i] <= ratings[i-1]){
                candies[i] = 1;
                satisfied++;
            }
        }
        while (satisfied < ratings.size()){
            // check left&right of local minima.
            for (int i = 0; i < candies.size(); i++){
                if (candies[i] != 0){
                    // if x <= x+1 or x-1, put i+1
                    // check left
                    if (i > 0 && candies[i-1] == 0){
                        candies[i-1] = candies[i] + 1;
                        satisfied++;
                        // check if 2.1 makes new neighbors. if true, solve conflict
                        if (i-2 >= 0 && candies[i-2] != 0){
                            if (ratings[i-2] > ratings[i-1] && candies[i-2] <= candies[i-1])
                                candies[i-2] = candies[i-1] + 1;
                            else if (ratings[i-1] > ratings[i-2] && candies[i-1] <= candies[i-2]) 
                                candies[i-1] = candies[i-2] + 1;
                        }
                    }
                    // check right
                    if (i+1 < candies.size() && candies[i+1] == 0){
                        candies[i+1] = candies[i] + 1;
                        satisfied++;
                        // check if 2.1 makes new neighbors. if true, solve conflict
                        if (i+2 < candies.size() && candies[i+2] != 0){
                            if (ratings[i+2] > ratings[i+1] && candies[i+2] <= candies[i+1])
                                candies[i+2] = candies[i+1] + 1;
                            else if (ratings[i+1] > ratings[i+2] && candies[i+1] <= candies[i+2])
                                candies[i+1] = candies[i+2] + 1;
                        }
                    }
                    
                }
            }
        }
        int res = 0;
        for (auto i : candies) res += i;
        return res;
    }
private:
    vector<int> candies;
    int satisfied = 0;
};