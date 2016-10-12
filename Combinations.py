class Solution(object):
    def combine(self, n, k):
        """
        :type n: int
        :type k: int
        :rtype: List[List[int]]
        """
        Solution.res = []
        self.curse([], 1, n, k)
        return Solution.res
        
    def curse(self, rest, start_idx, n, k):
        if k == 0:
            Solution.res.append(rest)
            return
        for i in range(start_idx, n-k+2):
            self.curse(rest + [i], i+1, n, k-1)