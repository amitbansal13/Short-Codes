def MCGW():
    ls=[]
    for i in range(16):
        binary=bin(i).replace("0b","")
        binary='0'*(4-len(binary))+binary#pad with zeros
        ls.append(binary)
    prohibited=[(1,2),(2,3)]#either cabbage and goat are togehter/goat and wolf
    valid=[]
    for i in range(len(ls)):
        if ls[i][0]!=ls[i][1] and ls[i][1]==ls[i][2]:
            continue
        if ls[i][0]!=ls[i][2] and ls[i][2]==ls[i][3]:
            continue
        valid.append(ls[i])
#     print(valid)
    return valid
valid=MCGW()
dic={0:'M',1:'C',2:'G',3:'W'}
for i in valid:
    l1=[];l2=[];
#     print(len(i))
    for j in range(len(i)):
        if i[j]=='0':
            l1.append(dic[j])
        else:
            l2.append(dic[j])
    print(l1,l2)