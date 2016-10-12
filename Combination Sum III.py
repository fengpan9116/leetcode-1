class Solution(object):
    def combinationSum3(self, k, n):
        """
        :type k: int
        :type n: int
        :rtype: List[List[int]]
        """
        candidates = [i for i in range(1, 10)]
        Solution.res = []
        self.curse(candidates, [], 0, n, k)
        return Solution.res
        
    def curse(self, candidates, rest, start_idx, target, k):
        if len(rest) > k: return
        if target == 0 and len(rest) == k:
            Solution.res.append(rest)
            return
        for i in range(start_idx, len(candidates)):
            if i > start_idx and candidates[i-1] == candidates[i]: continue
            if candidates[i] <= target:
                self.curse(candidates, rest + [candidates[i]], i+1, target-candidates[i], k)