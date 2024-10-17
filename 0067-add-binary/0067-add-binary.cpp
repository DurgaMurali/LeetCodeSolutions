class Solution {
public:
    string addBinary(string a, string b) {
        string::reverse_iterator str1 = a.rbegin();
        string::reverse_iterator str2 = b.rbegin();
        int carry = 0;
        string result = "";

        while(str1 != a.rend() && str2 != b.rend())
        {
            string ch1(1, *str1);
            int first = atoi(ch1.c_str());
            string ch2(1, *str2);
            int second = atoi(ch2.c_str());
            carry = carry + first + second;
            result = to_string(carry%2) + result;
            carry = carry >> 1;

            ++str1;
            ++str2;
        }

        while(str1 != a.rend())
        {
            string ch1(1, *str1);
            int first = atoi(ch1.c_str());
            carry = carry + first;
            result = to_string(carry%2) + result;
            carry = carry >> 1;

            ++str1;
        }

        while(str2 != b.rend())
        {
            string ch1(1, *str2);
            int first = atoi(ch1.c_str());
            carry = carry + first;
            result = to_string(carry%2) + result;
            carry = carry >> 1;

            ++str2;
        }
        if(carry > 0)
            result = to_string(carry%2) + result;

        return result;
    }
};