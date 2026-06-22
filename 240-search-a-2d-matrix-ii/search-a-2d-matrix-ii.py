class Solution:
    def searchMatrix(self, matrix: List[List[int]], target: int) -> bool:
        rows  = len(matrix)
        cols = len(matrix[0])

        currentRow = 0
        currentColumn = cols-1

        while(currentRow<rows and currentColumn >=0):
            currentElement = matrix[currentRow][currentColumn]

            if(currentElement == target):
                return True

            elif (currentElement > target):
                # you can surely not find in the rows below , so move left
                currentColumn = currentColumn - 1
            else:
                # if the the currentElement is smaller , you can't find target in the left anymore, so move downward
                currentRow  = currentRow +1
        

        return False
        