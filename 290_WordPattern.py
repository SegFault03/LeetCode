def wordPattern(pattern: str, s: str) -> bool:
        words = s.split()
        d1={}
        d2={}
        if len(words) != len(pattern):
            return False
        for i in range(len(pattern)):
            if d1.get(pattern[i]) is None and d2.get(words[i]) is None:
                d1[pattern[i]] = words[i]
                d2[words[i]] = pattern[i]
            else:
                if d1.get(pattern[i])!=words[i] or d2.get(words[i])!=pattern[i]:
                    return False
        return True
print(wordPattern("abcdab","dog car dog bc dog car"))
