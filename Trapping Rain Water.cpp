class Solution {
public:
    int trap(vector<int>& height) {
        int total = 0, i = 0;
        while (i < height.size()){
            if (height[i] == 0){
                i++;
                continue;
            }
            // Look for right bound
            int j = i+2;
            int min = height[i+1], max = height[i+1];
            for (; j < height.size(); j++){
                if (height[j] > max) max = height[j];
                //if (height[j] < min) min = height[j];
                if (height[j] >= height[i]) break;
                else if (height[j] < max){
                    j--;
                    break;
                }
                else if (j == height.size()-1 && height[j] > max) break;
            }
            if (j >= height.size() || j-i < 2){
                i++;
                continue;
            }
            int h = height[i] > height[j] ? height[j] : height[i];
            for (int m = i+1; m < j; m++)
                total += h-height[m];
            i = j+1;
        }
        return total;
    }
};