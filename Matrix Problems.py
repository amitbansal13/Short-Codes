def can_hike_to(elevation_map:List[List[int]],start:List[int],dest:List[int],supplies:int)->bool:
    while start[0]!=dest[0] and start[1]!=dest[1]:
        x,y=start[0],start[1]
#         print(x,y)
        change_north=abs(elevation_map[x-1][y]-elevation_map[x][y])
        change_west=abs(elevation_map[x][y-1]-elevation_map[x][y])
        if change_north<=change_west:#going north
            start[0]-=1
            supplies-=change_north
        else:
            start[1]-=1
            supplies-=change_west

    if start[0]==dest[0]:
        #if going only west
        while(start[1]>dest[1]):
            x,y=start[0],start[1]
            start[1]-=1
            change_west=abs(elevation_map[x][y-1]-elevation_map[x][y])
            supplies-=change_west
            
    elif start[1]==dest[1]:
        #if going only north
        while(start[0]>dest[0]):
            x,y=start[0],start[1]
            start[0]-=1
            change_north=abs(elevation_map[x-1][y]-elevation_map[x][y])
            supplies-=change_north
#     print(supplies)
    if supplies>=0:#If it is feasible then return True
        return True
    return False


# In[59]:


map = [[1, 6, 5, 6],[2, 5, 6, 8],[7, 2, 8, 1],[4, 4, 7, 3]]


# In[60]:


can_hike_to(map, [3, 3], [2, 2], 10)


# In[61]:


can_hike_to(map, [3, 3], [2, 2], 8)


# In[62]:


can_hike_to(map, [3, 3], [3, 0], 7)


# In[65]:


can_hike_to(map, [3, 3], [3, 0], 6)


# In[63]:


can_hike_to(map, [3, 3], [0, 0], 18)


# In[64]:


can_hike_to(map, [3, 3], [0, 0], 17)


# In[39]:


def get_lower_resolution(elevation_map:List[List[int]])->List[List[int]]:
    if len(elevation_map)%2==0:
        n_rows=len(elevation_map)//2
    else:
        n_rows=len(elevation_map)//2+1
    if len(elevation_map[0])%2==0:
        n_cols=len(elevation_map)//2
    else:
        n_cols=len(elevation_map[0])//2+1
    
    ls=[[0 for i in range(n_cols)] for i in range(n_rows)]
    l=0;r=0;
    for i in range(0,len(elevation_map)-1,2):
        r=0
        for j in range(0,len(elevation_map[0])-1,2):
            ls[l][r]=(elevation_map[i][j]+elevation_map[i][j+1]+elevation_map[i+1][j]+elevation_map[i+1][j+1])//4
            r+=1
        l+=1
    if (len(elevation_map))%2==1:
        n=len(elevation_map)
        m=len(elevation_map[0])
        r=0
        l=n_rows-1
        for i in range(0,m-1,2):
#             print(i)
            ls[l][r]=(elevation_map[n-1][i]+elevation_map[n-1][i+1])//2
            r+=1
#         print(l,r)
        ls[l][r]=elevation_map[n-1][m-1]
    if len(elevation_map[0])%2==1:
        n=len(elevation_map)
        m=len(elevation_map[0])
        l=0
        r=n_cols-1
        for i in range(0,n-1,2):
            ls[l][r]=(elevation_map[i][m-1]+elevation_map[i+1][m-1])//2
            l+=1
        ls[l][r]=elevation_map[n-1][m-1]
    return ls


# In[40]:


get_lower_resolution([[1, 6, 5, 6], [2, 5, 6, 8],[7, 2, 8, 1],[4, 4, 7, 3]])


# In[41]:


get_lower_resolution([[7, 9, 1], [4, 2, 1],[3, 2, 3]])


# In[1]:


from typing import List
UNIQUE_3X3 = [[1,2,3],[9,8,7],[4,5,6]]
UNIQUE_4X4 = [[10,2,3,30],[9,8,7,11],[4,5,6,12],[13,14,15,16]]
THREE_BY_THREE=[[1,2,1],[4,6,5],[7,8,9]]
FOUR_BY_FOUR = [[1,2,6,5],[4,5,3,2],[7,9,8,1],[1,2,1,4]]


# In[2]:


def find_peak(elevation_map:List[List[int]])->List[int]:
    ls=[0,0]#to store the maximum value
    for i in range(len(elevation_map)):
        for j in range(len(elevation_map[0])):
            if elevation_map[ls[0]][ls[1]]<elevation_map[i][j]:
                ls[0],ls[1]=i,j
    return ls


# In[3]:


find_peak(UNIQUE_3X3)


# In[4]:


find_peak(UNIQUE_4X4)


# In[7]:


def is_sink(elevation_map:List[List[int]],cell:List[int])->bool:
    if cell[0]>len(elevation_map)-1 or cell[1]>len(elevation_map[0])-1:
        return False
    if cell[0]<0 or cell[1]<0:
        return False
    
    for i in range(cell[0]-1,cell[0]+2):
        for j in range(cell[1]-1,cell[1]+2):
            if j>=0 and i>=0 and             j<len(elevation_map[0]) and i<len(elevation_map) and             not (elevation_map[cell[0]][cell[1]]<=elevation_map[i][j]):
                return False
    return True


# In[8]:


is_sink(THREE_BY_THREE,[0,3])


# In[9]:


is_sink(THREE_BY_THREE,[0,2])


# In[10]:


is_sink(THREE_BY_THREE,[1,1])


# In[11]:


is_sink(FOUR_BY_FOUR,[2,3])


# In[12]:


is_sink(FOUR_BY_FOUR,[3,2])


# In[13]:


is_sink(FOUR_BY_FOUR,[1,3])


# In[ ]:


THREE_BY_THREE_COPY=[[1,2,1],[4,6,5],[7,8,9]]
FOUR_BY_FOUR_COPY = [[1,2,6,5],[4,5,3,2],[7,9,8,1],[1,2,1,4]]


# In[ ]:


def update_elevation(elevation_map:List[List[int]],start:List[int],stop:List[int],delta:int)->None:
    #if in same row and same col
    if start[0]==stop[0] and start[1]==stop[1]:
        elevation_map[start[0]][start[1]]+=delta
    elif (start[0]==stop[0]):#if in same row
        for i in range(start[1],stop[1]+1):
            elevation_map[start[0]][i]+=delta
    else:#if in same col
        for i in range(start[0],stop[0]+1):
            elevation_map[i][start[1]]+=delta


# In[ ]:


def find_peak(elevation_map:List[List[int]])->List[int]:
    ls=[0,0]#to store the maximum value
    for i in range(len(elevation_map)):
        for j in range(len(elevation_map[0])):
            if elevation_map[ls[0]][ls[1]]<elevation_map[i][j]:
                ls[0],ls[1]=i,j
    return ls
