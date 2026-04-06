class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        std::stack<int> s;
        for(int i=0;i<tokens.size();++i)
        {
            if(tokens[i] == "+")
            {
                int lhs = s.top();
                s.pop();
                int rhs = s.top();
                s.pop();
                s.push(rhs + lhs);
            }
            else if(tokens[i] == "-")
            {
                int lhs = s.top();
                s.pop();
                int rhs = s.top();
                s.pop();
                s.push(rhs - lhs);
            }
            else if(tokens[i] == "*")
            {
                int lhs = s.top();
                s.pop();
                int rhs = s.top();
                s.pop();
                s.push(rhs * lhs);
            }
            else if(tokens[i] == "/")
            {
                int lhs = s.top();
                s.pop();
                int rhs = s.top();
                s.pop();
                s.push(rhs / lhs);
            }
            else
            {
            s.push(std::stoi(tokens[i]));

            }

        }

        return s.top();
    }

};
