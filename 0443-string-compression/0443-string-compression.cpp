class Solution {
public:
    int compress(vector<char>& chars) {
    int index = 0, n = chars.size();
    for (int i = 0; i < n;) {
    char c = chars[i];
    int count = 0;
    while (i < n && chars[i] == c) {
    ++i;
    ++count;
    }
    chars[index++] = c;
    if (count > 1) {
    for (char digit : to_string(count)) chars[index++] = digit;
        }
    }
    return index;
}
};