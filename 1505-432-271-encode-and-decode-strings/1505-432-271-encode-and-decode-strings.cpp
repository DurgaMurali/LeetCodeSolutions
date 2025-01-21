class Codec {
public:

    // Encodes a list of strings to a single string.
    string encode(vector<string>& strs) {
        string encoded_str;
        string en_str = "*#%";
        for(int i=0; i<strs.size(); ++i)
        {
            encoded_str += strs[i] + en_str;
        }

        //std::cout << encoded_str << std::endl;
        return encoded_str;
    }

    // Decodes a single string to a list of strings.
    vector<string> decode(string s) {
        vector<string> decoded_str;

        string en_str = "*#%";
        size_t pos = s.find(en_str);
        int index = 0;
        while(pos != string::npos)
        {
            string str = s.substr(index, pos-index);
            decoded_str.push_back(str);
            index += (pos-index)+en_str.size();
            pos = s.find(en_str, index);
        }

        if(index < s.size())
            decoded_str.push_back(s.substr(index));

        return decoded_str;
    }
};

// Your Codec object will be instantiated and called as such:
// Codec codec;
// codec.decode(codec.encode(strs));