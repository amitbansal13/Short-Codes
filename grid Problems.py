
from copy import deepcopy 
def subgrid_values(grid, row, col): 
    val = [] 
    #get dimension of inner box 
    n = int(len(grid)**(0.5)) 
    #get starting row and starting col  
    r = (row//n)*n 
    c = (col//n)*n 
    for i in range(r, r+n): 
        for j in range(c, c+n): 
            val.append(grid[i][j]) 

    return val



def valid_grid(grid, num, r, c):
    for i in range(len(grid)):
        if grid[i][c]==num:
            return False
        
    for i in range(len(grid[0])):
        if grid[r][i]==num:
            return False
    lst=subgrid_values(grid,r,c)
    
    for i in lst:
        if i==num:
            return False
    return True

def row(grid,num,r):
    ans=[]
    for i in range(len(grid[0])):
        if grid[r][i]==num:
            ans.append(grid)
            return ans
    
    for i in range(len(grid[0])):
        temp=deepcopy(grid)
        if valid_grid(grid,num,r,i) and grid[r][i]=='x':
            temp[r][i]=num
            ans.append(temp)
    return ans


# In[71]:


def grids_augmented_with_number(grid,num):#generate all possible grids with num in each row
    ans=row(grid,num,0)
    for i in range(1,len(grid)):
        temp_ans=[]
        for grids in ans:
            temp_ans.extend(row(grids,num,i))
        ans=temp_ans
    
    final_ans=[]
    for grids in ans:
        count=0
        for i in range(len(grid)):
            for j in range(len(grid[0])):
                if grids[i][j]==num:
                    count+=1
        if count==len(grid):
            final_ans.append(grids)
    return final_ans


# In[72]:


lite_grid = [[1,'x','x','x'],['x','x','x','x'],['x','x','x','x'],['x',2,'x','x'],]



full_grid = [[2,'x','x','x'],['x',3,2,4],['x','x',4,2],[1,2,3,'x'],]



grid_A = [['x','x',1,'x'],[4,'x','x','x'],['x','x','x',2],['x',3,'x','x'],]



# In[73]:


grids_augmented_with_number(lite_grid,1)


# In[74]:


grids_augmented_with_number(full_grid,1)


# In[75]:


grids_augmented_with_number(grid_A,1)