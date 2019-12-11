//hash map

class Solution:
    def getS(self, str):
        mp = {}
        s = ""
        cnt = 0
        for each in str:
            if mp.get(each) == None:
                mp[each] = cnt
                cnt += 1
            s += chr(mp[each])
        return s
    def wordPattern(self, pattern: str, str: str) -> bool:
        str_list = str.split(' ');
        return self.getS(str_list) == self.getS(pattern)
