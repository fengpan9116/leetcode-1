class Solution(object):
    def coinChange(self, coins, amount):
        """
        :type coins: List[int]
        :type amount: int
        :rtype: int
        """
        fff = 0xFFFFFFFF
        dyna = [0] + [fff]*amount
        for i in xrange(amount+1):
            for c in coins:
                if i + c <= amount:
                    dyna[i+c] = min(dyna[i]+1, dyna[i+c])
                    
        return dyna[amount] if dyna[amount] != fff else -1
        