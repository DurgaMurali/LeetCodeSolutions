class Solution {
public:
    int hammingWeight(int n) {
        int bit_count = 0;

        while(n > 0)
        {
            int digit = n%2;
            if(digit)
                bit_count++;
            n=n/2;
        }

        return bit_count;
    }
};