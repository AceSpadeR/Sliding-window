#include <iostream>
#include <unordered_set>
#include <string>

using namespace std;

string Find_Longest_Substring(string str) {
    //Set for storing right values
    unordered_set<char> set;
    // Maxlength and start give index start and end of substring
    int left = 0, right = 0, maxLength = 0, start = 0;
    string longestSubstring;
    // Iterate through the str using right index
    while (right < str.length()) {
        // Check if right index is in the set
        if(set.find(str[right]) == set.end()){
            // Insert right index if not in set
            set.insert(str[right]);
            // get length of current substring
            if (right - left + 1 > maxLength) {
                // Only updated the indexs when new sub index is larger
                maxLength = right - left + 1;
                start = left;
            }
            right++;
        } else {
            set.erase(str[left]);
            left++;
        }
    }
    // Get substring from string
    longestSubstring = str.substr(start, maxLength);
    return longestSubstring;

}


int main(){
    string str = "";
    cout << "Enter String:";
    getline(cin, str);
    
    cout << Find_Longest_Substring(str);
    


    return 0;
}