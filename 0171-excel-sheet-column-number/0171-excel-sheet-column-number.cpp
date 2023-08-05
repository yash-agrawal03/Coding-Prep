							// \U0001f609\U0001f609\U0001f609\U0001f609Please upvote if it helps \U0001f609\U0001f609\U0001f609\U0001f609
class Solution {
public:
    int titleToNumber(string columnTitle) {
        int result = 0;
        for(char c : columnTitle)
        {
			//d = s[i](char) - 'A' + 1 (we used  s[i] -  'A' to convert the letter to a number like it's going to be C)

            int d = c - 'A' + 1;
            result = result * 26 + d;
        }
        return result;
    }
};