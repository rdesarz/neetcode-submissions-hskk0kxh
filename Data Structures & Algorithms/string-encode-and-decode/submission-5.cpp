class Solution {
public:

    string encode(const vector<string>& strs) {
        string out;
        for (const auto& st : strs) {
            out.push_back('#');
            out += to_string(st.size());
            out.push_back('#');
            out += st;
        }
        return out;
    }

    vector<string> decode(const string& s) {
    vector<string> out;
    int i = 0;
    const int n = (int)s.size();

    while (i < n) {
        // Expect '#'
        ++i;  // skip '#'

        // Read length up to next '#'
        int len = 0;
        while (i < n && s[i] != '#') {
            len = len * 10 + (s[i] - '0');
            ++i;
        }
        ++i; // skip '#'

        // Read payload
        out.push_back(s.substr(i, len));
        i += len;
    }
    return out;
}
};
