class Solution(object):
    def lexicalOrder(self, n):
        """
        :type n: int
        :rtype: List[int]
        """
        stk = [1]
        res = []
        while stk:
            a = stk.pop()
            res.append(a)
            if a % 10 < 9 and a+1 <= n: stk.append(a+1)
            if a*10 <= n: stk.append(a*10)
        return res