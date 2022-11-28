def decodeString(s):
    stack =[]
    s = "1[" + s + "]"
    i = 0
    wrd=""
    m=""
    while(i < len(s)):
        if s[i] == ']':
            while(stack[len(stack)-1] !='[' and len(stack) > 0):
                wrd=stack.pop()+wrd
            stack.pop()
            while(len(stack) > 0 and 48 <= ord(stack[len(stack)-1]) <= 57 and len(stack[len(stack)-1])==1):
                m=stack.pop()+m
            stack.append(wrd*int(m))
            m=""
            wrd=""
        else:
            stack.append(s[i])
        i+=1
    return stack[0]
   

print(decodeString("10[leetcode]"))
print(decodeString("2[ab3[cd2[ef]dc]2[cd]]"))
