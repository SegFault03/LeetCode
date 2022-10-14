#SOLUTION: https://leetcode.com/problems/decode-ways/submissions/822431260/
def numDecodings(s: str) -> int:
    map ={}
    i=len(s)-1
    while i>=0:
        word = s[i:]
        if len(word)>=2 and word[0]!='0':                       #This is when string is of length >= 2
            a = map[word[1:]]                                   #Take the first character and find the number of ways in which the rest of the string can be decoded
            if 1 <= int(word[:2]) <= 26:                        #Check if the first two character can be combined to form an alphabet
                if map.get(word[2:]) is not None:               #This is nessecary, as the key may not always exist.
                    b = 1*map[word[2:]]
                else:
                    b = 1
            else:
                b=0
            map[word]=a+b                                       #Store the total number of ways
        elif word[0]=='0':
            map[word]=0
        else:
            map[word]=1                                        #This is when the string is only of length 1
        i=i-1
    return map[s]                                              #Return the final value

print(numDecodings("1202103"))

#NOTES:
#For a string "abcd", the total number of ways it can be decoded:
#decode('abcde') = decode('a')*decode('bcde'), and decode('bcde') = decode('b')*decode('cde'), and so on it goes recursively.
#Since at every step, we will have to repetetively calculate decode('abc...'), its better to store the decode values for future reference.
#And this is where Dynamic Programming comes into play.
#Here we have used a bottom up approach to solve this problem, to make sure that the smallest subproblems are calculated first (and also because
# ..a top down approach warrants a recursive implementation, while the bottom up approach can be implemented iteratively) and stored for future refrence
#That way, we can be sure that when we have to solve a problem, we can solve it directly by referring to the stored values, since all the smaller problems
#that the bigger problem depends upon have already been solved.

#ALGORITHM
#decode('abc...efg') = decode('a') * decode('bc...efg') + decode('ab') * decode('cd...efg') if a!=0 and 1 <= ab <= 24
#for i = s.length-1 to 0:                                                               //Start from the end, to solve the smallest strings first
#   word = s.substring(i)                                                               //Extract the i to s.length string of s
#   if word[0] is not 0 and word.length >= 2:                                           //Check if there exists a leading zero and if string length >= 2
#      a = map[word[1]]                                                                 //Of a string 'abcd', find the number of ways in which 'bcd' can be decoded
#                                                                                       //(This has already been solved, so it will always be available)
#      if 1 <= int(word.substring(0,2)) <= 26:                                          //Check if the first two characters form a valid alphabet (10 to 26)
# See above code for more help