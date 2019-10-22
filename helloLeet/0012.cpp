//table

class Solution {
public:
    string intToRoman(int num) {
        string s1[10] = {"", "I", "II", "III", "IV", "V", "VI", "VII", "VIII", "IX"};
        string s2[10] = {"", "X", "XX", "XXX", "XL", "L", "LX", "LXX", "LXXX", "XC"};
        string s3[10] = {"", "C", "CC", "CCC", "CD", "D", "DC", "DCC", "DCCC", "CM"};
        string s4[4] = {"", "M", "MM", "MMM"};
        return s4[num/1000] + s3[(num%1000)/100] + s2[(num%100)/10] + s1[(num%10)];
    }
};
