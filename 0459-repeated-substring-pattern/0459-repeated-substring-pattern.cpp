class Solution {
public:
    bool repeatedSubstringPattern(string s) {
        string doubled = s + s;
        doubled = doubled.substr(1, doubled.size() - 2);
        return doubled.find(s) != string::npos;
    }
};