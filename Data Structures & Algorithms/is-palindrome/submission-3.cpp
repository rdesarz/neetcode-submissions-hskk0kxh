class Solution {
public:
    bool isPalindrome(string s) {
    int p1 = 0;
    int p2 = (int)s.size() - 1;

    auto is_alnum = [&](char c){
        return ('a'<=c && c<='z') || ('A'<=c && c<='Z') || ('0'<=c && c<='9');
    };
    auto lower = [&](char c){
        if ('A'<=c && c<='Z') c += ('a' - 'A');
        return c;
    };

    while (p1 < p2) {
        while (p1 < p2 && !is_alnum(s[p1])) ++p1;
        while (p1 < p2 && !is_alnum(s[p2])) --p2;

        if (lower(s[p1]) != lower(s[p2])) return false;
        ++p1; --p2;
    }
    return true;
}
};
