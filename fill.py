def fill(image, tone, seed):
    def check(x,y,initial_value):#to check if an index is a valid move 
        if x<0 or x>=len(image):
            return False
        if y<0 or y>=len(image[0]):
            return False
        if image[x][y]!=initial_value:
            return False
        return True
    
    copyList=[]
    initial_value=image[seed[0]][seed[1]]
    
    for i in range(len(image)):
        copyList.append(image[i].copy())
    
    ls=[seed]
    
    visited=[]
    for i in range(len(image)):
        visited.append([])
        for j in range(len(image[0])):
            visited[i].append(False)
    
    while ls!=[]:
        x,y=ls[0][0],ls[0][1]
#         print(ls)
        del ls[0]
#         print(ls)
        copyList[x][y]=tone
        visited[x][y]=True
        for i in range(x-1,x+2):
            for j in range(y-1,y+2):
#                 print((i,j))
                if x==i and y==j:
                    continue
                if check(i,j,initial_value) and visited[i][j]==False:
                    ls.append((i,j))
    
    return copyList

