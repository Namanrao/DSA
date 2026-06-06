class Solution:
    def helper(self , string : str ) -> str:
        result= ""
        previous = string[0]
        count  =1 
        for i in range(1,len(string)):
            current = string[i]
            if(current == previous):
                count  = count +1
            else:
                result = result + str(count)
                result = result + previous
                previous = current
                count = 1
                
        result = result+str(count)
        result = result + previous

        return result

    def countAndSay(self, n: int) -> str:
        if(n == 1):
            return "1"
        else:
            result = "1"
            for i in range(n-1):
                result = self.helper(result)
        
        return result

        