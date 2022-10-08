def permute(s,i,l):
    if i==len(s)-1:
        print(s)
    else:
        temps=[s[i] for i in range(len(s))]
        for j in range(i,len(s)):
            temp=temps[i]
            temps[i]=temps[j]
            temps[j]=temp
            permute(temps,i+1,l)

permute(['a','b','c','d'],0,[])