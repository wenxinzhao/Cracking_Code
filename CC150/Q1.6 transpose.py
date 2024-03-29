class MatrixProcessor:

    def __init__(self, matrix):
        self.n=len(matrix)
        self.m=len(matrix[0])
        self.matrix = matrix

    def __str__(self):
        rowstring=""
        for row in self.matrix:
            rowstring = rowstring + "["
            for cell in row:
                rowstring = rowstring + " " + str(cell) + " "
            rowstring = rowstring + "]\n"            
        return rowstring

    def rotate90CW(self):
        
        columnlist=[]
        for row in self.matrix:
            #set up a list for columns
            columnlist.append([])        
        for row in self.matrix:
            columnindex=0
            for cell in row:
                columnlist[columnindex].append(cell)
                columnindex += 1
        newmatrix=[]
        for col in columnlist:
            newmatrix.append(reversed(col))
        self.matrix=newmatrix
#testing
        
mat1= MatrixProcessor([[1,2,3,4],[5,6,7,8],[9,10,11,12],[13,14,15,16]])

print ("M by N matrix has dimensions " + str(mat1.m) + " by " + str(mat1.n))

print ("Visual representation of contents:")
print (str(mat1)  )                


mat1.rotate90CW()

print ("Visual representation of contents after rotating 90 degrees clockwise:")
print (str(mat1)   )
