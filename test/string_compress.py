
def min(word):
    i=0
    flag = False
    nword = word
    while i+2<len(word):
        if word[i] is word[i+2]:
            flag = True
            break
        i+=2
    if flag is True:
        temp = str(int(word[i+1])+int(word[i+3]))
        nword = word[:i]+word[i]+temp+word[i+4:]
    return nword

def ops(s,k):
    word = s
    while k>0:
        i=1
        flag = False
        while i<len(word):
            if word[i]=='1':
                flag = True
                break
            i+=2
        if flag is True:
            word = word[:i-1]+word[i+1:]
            k-=1
            word = min(word)
            length = len(word)
            continue
        mini = int(word[1])
        j = 1
        i=1
        while i<len(word):
            if int(word[i])<mini:
                mini = int(word[i])
                j=i
            i+=2
        if mini>=k:
            temp = str(mini-k)
            word = word[:j]+temp+word[j+1:]
            word = min(word)
            k=0
        else:
            temp = k-mini
            k=temp
            word=word[:j-1]+word[j+1:]
            word=min(word)
        length = len(word)
    return length

print(ops("a2b2a2",2))