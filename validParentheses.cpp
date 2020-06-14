#include <iostream>
#include <string>
#include <stack>

class Solution {
  public:
    bool isValid(std::string s) 
    {
        std::stack<char> exist;
        for ( auto &ch : s )
        {
            if ( exist.empty() )
                exist.push(ch);

            else if ( (ch == ')') ||
                 (ch == ']') ||
                 (ch == '}') )
            {
                std::string pair {std::string(1, exist.top())};
                pair.push_back(ch);

                if ( (pair != "()") &&
                     (pair != "[]") &&
                     (pair != "{}") )
                    return false;
                else
                    exist.pop();
            }
            else
                exist.push(ch);
        }

        return exist.empty();

    }
};

bool testPass()
{
    Solution Check;

    bool passed = true;
    passed = passed && Check.isValid("()");
    passed = passed && Check.isValid("()[]{}");
    passed = passed && !Check.isValid("(]");
    passed = passed && !Check.isValid("](");
    passed = passed && !Check.isValid("([)]");
    passed = passed && Check.isValid("{[]}()");

    return passed;
}

int main()
{
    std::cout << (testPass() ? "success" : "failed") << "\n";
    // std::stack<char> pairs;
    // std::string word {"{}[]()"};
    // for (auto &member : word)
    // {
    //     std::cout << pairs.top() << ' ';
    //     pairs.push(member);
    // }

    return 0;
}