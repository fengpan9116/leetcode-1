class Solution(object):
    def combinationSum(self, candidates, target):
        """
        :type candidates: List[int]
        :type target: int
        :rtype: List[List[int]]
        """
        candidates.sort()
        Solution.res = []
        self.curse(candidates, [], 0, target)
        return Solution.res
        
    def curse(self, candidates, rest, start_idx, target):
        if target == 0:
            Solution.res.append(rest)
            return
        for i in range(start_idx, len(candidates)):
            if i > start_idx and candidates[i-1] == candidates[i]: continue
            elif candidates[i] <= target:
                self.curse(candidates, rest + [candidates[i]], i, target-candidates[i])
        