class Solution {

    void remSpaces(string & str) {
        for (int i = 0; i < str.length(); i++) {
            if (str[i] == ' ') {
                str.erase(str.begin() + i);
                i--;
            }
        }
    }

    string convert(string str) {
        remSpaces(str);

        string res = "";

        stack < char > s;

        unordered_map < char, int > prec {
            {
                '+',
                1
            }, {
                '-',
                1
            }, {
                '*',
                2
            }, {
                '/',
                2
            }, {
                '~',
                3
            }
        };

        for (int i = 0; i < str.length(); i++) {
            char token = str[i];

            if (token == '-') {
                if (i == 0 || str[i - 1] == '(' || prec.find(str[i - 1]) != prec.end())
                    token = '~';
            }

            if (token == '(') {
                s.push(token);
            }

            if (token == ')') {
                while (s.top() != '(') {
                    char ch = s.top();
                    s.pop();
                    res += ch;
                }

                s.pop();
            }

            if (prec.find(token) != prec.end()) {
                if (token == '~') {
                    while (!s.empty() && s.top() != '(' && prec[s.top()] > prec[token]) {
                        char ch = s.top();
                        s.pop();
                        res += ch;
                    }

                    s.push(token);
                } else {
                    while (!s.empty() && s.top() != '(' && prec[s.top()] >= prec[token]) {
                        char ch = s.top();
                        s.pop();
                        res += ch;
                    }

                    s.push(token);
                }
            }

            if (token >= '0' && token <= '9') {
                char ch = str[i];
                while (ch >= '0' && ch <= '9') {
                    res += ch;
                    i++;
                    ch = str[i];
                }
                i--;
                res += ' ';
            }
        }

        while (!s.empty()) {
            char ch = s.top();
            res += ch;
            s.pop();
        }

        return res;

    }

    public:
        long long int calculate(string str) {
            string rpn = convert(str);

            stack < long long int > s;

            for (int i = 0; i < rpn.length(); i++) {
                char token = rpn[i];

                if (token == ' ')
                    continue;

                if (token >= '0' && token <= '9') {
                    char ch = rpn[i];
                    long long int n = 0;

                    while (ch != ' ' && i < rpn.length()) {
                        n *= 10;
                        n += static_cast < int > (ch - '0');
                        i++;
                        ch = rpn[i];
                    }

                    cout << n << endl;

                    s.push(n);
                    i--;
                }

                if (token == '~') {
                    int n = s.top();
                    s.pop();
                    s.push(-n);
                }

                if (token == '+' || token == '-' || token == '*' || token == '/') {
                    int b = s.top();
                    s.pop();
                    int a = s.top();
                    s.pop();

                    if (token == '+')
                        s.push(a + b);
                    else if (token == '-')
                        s.push(a - b);
                    else if (token == '*')
                        s.push(a * b);
                    else if (token == '/')
                        s.push(a / b);
                }
            }

            return s.top();

        }
};
