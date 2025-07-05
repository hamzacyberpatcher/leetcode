class Solution {
public:
    int strStr(string haystack, string needle) {

        if (needle == haystack)
            return 0;
    

     for(int i = 0; i < haystack.size(); i++)   
     {
        int matches = 0;
        for(int j = i, k = 0; j < i + needle.size() && j < haystack.size(); j++, k++)
            if (haystack[j] == needle[k])
                matches++;
            else
                break;
        
        if (matches == needle.size())
            return i;
     }

     return -1;
    }
};
