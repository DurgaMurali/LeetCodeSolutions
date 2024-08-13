class Solution {
public:
    int maxVowels(string s, int k) {
        int max_vowels = 0;
        int num_vowels = 0;
        int size = s.length();

        for(int i=0; i<k; i++)
            if(s[i]=='a' || s[i]=='e' || s[i]=='i' || s[i]=='o' || s[i]=='u')
                num_vowels++;

        for(int i=0; i<=size-k; i++)
        {
            if (i>0)
            {
                if(s[i-1]=='a' || s[i-1]=='e' || s[i-1]=='i' || s[i-1]=='o' || s[i-1]=='u')
                    num_vowels--;

                if(s[i+k-1]=='a' || s[i+k-1]=='e' || s[i+k-1]=='i' || s[i+k-1]=='o' || s[i+k-1]=='u')
                    num_vowels++;
            }

            if(num_vowels > max_vowels)
                max_vowels = num_vowels;
        }

        return max_vowels;
    }
};