class Solution {
public:
    int compress(vector<char>& chars) {
        int size = chars.size();
        int low_index = -1;
        int high_index = -1;
        string result = "";

        if (size == 1)
            return size;

        for(int i=1; i<size; i++)
        {
            if (chars[i-1] == chars[i])
            {
                if (low_index == -1)
                    low_index = i-1;
                high_index = i;
            }
            
            if (((chars[i-1] != chars[i]) && (i < size-1)) || (chars[i-1] == chars[i] && i == size-1))
            {
                int total = high_index - low_index + 1;
                if (total > 1)
                {
                    result += chars[i-1];
                    result += to_string(total);
                }
                else 
                    result += chars[i-1];

                low_index = -1;
                high_index = -1;
            }

            if (chars[i-1] != chars[i] && i == size-1)
            {
                int total = high_index - low_index + 1;
                if (total > 1)
                {
                    result += chars[i-1];
                    result += to_string(total);
                }
                else 
                    result += chars[i-1];

                result += chars[i];

                low_index = -1;
                high_index = -1;
            }
        }

        for (int j=0; j<result.length(); j++)
            chars[j] = result[j];
        
      return result.length();  
    }
};