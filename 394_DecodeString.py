def decodeString(s):
    s+=']'
    i=0
    wrd=""
    while(i<len(s)):
        if 49<=ord(s[i])<=57:
            tmp = decodeString(s[i+2:])
            l = len(tmp)
            wrd+=tmp*int(s[i])
            i += 3 + l
            continue
        elif s[i] == ']':
            return wrd
        else:
            wrd+=s[i]
            i+=1

print(decodeString("2[ab3[cd2[ef]dc]2[cd]]"))
