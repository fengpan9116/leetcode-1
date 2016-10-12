public class Solution {
    public int combinationSum4(int[] nums, int target) {
        Arrays.sort(nums);
        int dyna[] = new int[target+1];
        dyna[0] = 1;
        for (int i = 1; i <= target; i++){
            for (int j : nums){
                if (j <= i) dyna[i] += dyna[i-j];
                else break;
            }
        }
        return dyna[target];
    }
}