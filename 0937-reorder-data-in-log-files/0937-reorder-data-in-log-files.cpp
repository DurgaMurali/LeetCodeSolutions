class Solution {
public:
    static bool compare_function(string str1, string str2)
    {
        int pos1 = str1.find_first_of(' ');
        string key1 = str1.substr(0, pos1);
        string value1 = str1.substr(pos1+1, str1.size()-pos1-1);
        int pos2 = str2.find_first_of(' ');
        string key2 = str2.substr(0, pos2);
        string value2 = str2.substr(pos2+1, str2.size()-pos2-1);

        int val_comp = value1.compare(value2);
        if(val_comp < 0)
            return true;
        else if(val_comp > 0)
            return false;
        else
        {
            int key_comp = key1.compare(key2);
            if(key_comp <= 0)
                return true;
            else
                return false;
        }
    }

    vector<string> reorderLogFiles(vector<string>& logs) {
        vector<string>::iterator itr = logs.begin();
        vector<string> letter_logs;
        vector<string> digit_logs;
        
        for(; itr != logs.end(); ++itr)
        {
            string str = *itr;
            int pos = str.find_first_of(' ');
            if(isdigit(str.substr(pos+1, 1).at(0)))
                digit_logs.push_back(*itr);
            else
                letter_logs.push_back(*itr);
        }

        std::sort(letter_logs.begin(), letter_logs.end(), compare_function);
        letter_logs.insert(letter_logs.end(), digit_logs.begin(), digit_logs.end());

        return letter_logs;
    }

    
};