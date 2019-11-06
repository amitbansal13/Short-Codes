def crypto(m,N,order):
    inp=input('Please enter your choice (E/D): ').lower()
    while(inp!='e' and inp!='d'):
        inp=input('Invalid choice, please try again: ').lower()
    
    ls=[[] for i in range(N)]#making a list of n lists representing n columns
    if inp=='e':#encryption
        i=0
        while i<len(m):
            for j in range(len(order)):#appeiding the elements columnwise
                if i<len(m):
                    ls[j].append(m[i])
                else:
                    ls[j].append('z')#filling emmpty elements with 'z'
                i+=1
        crypt=''
        for i in order:#reading in the order represented by order
            for alpha in ls[i-1]:#reading alphabets
                crypt=crypt+alpha
        return crypt
    else:
        index=0
        for i in order:
            for j in range(len(m)//N):#appending the elmeents represented by order
                ls[i-1].append(m[index])
                index+=1
        decrypt=''
        for i in range(len(ls[0])):#reading len(m)/N characters
            for j in range(N):
                decrypt=decrypt+ls[j][i]
        return decrypt

print(crypto('hellohowdoyoudo',3,(1,2,3)))
print(crypto('hellohowdoyoudo',3,(2,3,1)))
print(crypto('eowydlhdoohloou',3,(2,3,1)))
print(crypto('ordpfhntanlntpoeeondtanayteimieaolrbffkz',4,(2,3,1,4)))
print(crypto('harrypotterandvoldemort',5,(2,1,4,3,5)))