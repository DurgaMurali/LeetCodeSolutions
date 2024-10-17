class Solution {
public:
    uint32_t reverseBits(uint32_t n) {
        uint32_t reverse_n = 0;
        int num_bits = 8 * sizeof(uint32_t);

        int count = 0;
        while(count < num_bits)
        {
            int digit = n%2;
            reverse_n = reverse_n << 1;
            reverse_n = reverse_n | digit;
            n = n/2;
            count++;
        }

        return reverse_n;
    }
};