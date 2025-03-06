class Solution {
public:
    bool isNumber(string &c) {
        return (c != "+" && c != "-" && c != "/" && c != "*");
    }

    int evalRPN(vector<string>& tokens) {
        vector<int> N;

        for(auto& tok : tokens) {
            if (isNumber(tok)) N.push_back(stoi(tok));
            else {
                int res = 0;
                int New = N.back(); N.pop_back();
                int Old = N.back(); N.pop_back();

                if (tok == "+") res = New + Old;
                else if (tok == "-") res = Old - New;
                else if (tok == "*") res = Old * New;
                else res = Old / New;

                N.push_back(res);
            }
        }
    
    
        return N.back();
    }
};

