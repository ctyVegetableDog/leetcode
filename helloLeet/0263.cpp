//ugly number

/*
	just logic
*/

class Solution {
public:
    bool isUgly(int num) {
        if (num <= 0) return false;
        int k[3] = {2, 3, 5};
        for (int i = 0; i < 3; i++) {
            while (num %k[i] == 0)
                num /= k[i];
        }
        return num == 1;
    }
};
