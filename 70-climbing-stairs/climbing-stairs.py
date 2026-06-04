class Solution:

    def solve(self, n:int , dp:List[int]) ->int:
        if(n ==0 or  n== 1):
            return 1
        elif(n==2):
            return 2
        elif(dp[n]!=-1):
            return dp[n]
        else:
            dp[n] = (self.solve(n-1, dp) + self.solve(n-2, dp))
        return dp[n]

    def climbStairs(self, n: int) -> int:
        dp = [-1]*(n+1)

        if(dp[n] != -1):
            return dp[n]
        else:
            return self.solve(n ,dp)