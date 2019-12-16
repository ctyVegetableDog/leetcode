//KMP

class Solution {
public:
    int strStr(string haystack, string needle) {
        int hsize = haystack.size(), nsize = needle.size(),k = -1, j = 0;
        if (nsize == 0) return 0;
        if (hsize == 0) return -1;
        int next[nsize];
        next[0] = -1;
        while (j < nsize - 1) {
            if (k == -1 || needle[j] == needle[k]) {
                k++;
                j++;
                next[j] = k;
            } else k = next[k];
        }
        k = 0;
        j = 0;
        while (k < hsize && j < nsize) {
            if (j == -1 || haystack[k] == needle[j]) {
                k++;
                j++;
            } else j = next[j];
        }
        if (j == nsize) return k-j;
        else return -1;
    }
};
