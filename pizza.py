def dist(i,j,x,y):
    return ((i-x)**2)+((j-y)**2)
def PDMap(h,w,pizzaLoc):#Assign houses to nearest Pizza location h,w is the height and width of city map
#pizzaLoc is the list containing coordinates of pizza shops on maps
    arr=[[0 for i in range(w)] for j in range(h)]
    for j in range(w):
        for i in range(h):
            min_dist=float('inf')#max value initially
            for k in range(len(pizzaLoc)):
                x,y=pizzaLoc[k]
                min_dist=min(min_dist,dist(i,j,x,y))
            count=0
            index=0
            for k in range(len(pizzaLoc)):
                x,y=pizzaLoc[k]
                if dist(i,j,x,y)==min_dist:
                    index=k
                    count+=1
            if count>1:
                arr[i][j]='X'
            else:
                arr[i][j]=index
    return arr

def mTightPrint(m):
    for i in range(len(m)):
        line=''
        for j in range(len(m[0])):
            line+=str(m[i][j])
        print(line)


# In[70]:
