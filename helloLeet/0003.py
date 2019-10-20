//slide window

class Solution:
    def lengthOfLongestSubstring(self, s: str) -> int:
        l = len(s)
        st = set()
        i = 0
        j = 0
        ans = 0
        while(i < l and j < l):
            if s[j] not in st:
                st.add(s[j])
                j += 1
                ans = max(ans, j - i)
            else:
                st.remove(s[i])
                i += 1
        return ans
