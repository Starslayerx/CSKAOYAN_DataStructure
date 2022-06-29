#include <iostream>
#include <vector>
#include <stack>
#include <unordered_map>

using namespace std;

unordered_map<char, int> m = {{'(', -1},
                              {')', 10},
                              {'+', 1},
                              {'-', 1},
                              {'*', 2},
                              {'/', 2}};

// 中缀表达式转后缀表达式
string trans(char fourm[])
{
    string res = "";

    stack<char> s;
    for (int i = 0; fourm[i] != '\0'; ++i)
    {
        char c = fourm[i];

        if ((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z'))
            res += c;
        else {
            if (c == '(')
                s.push('(');
            else if (c == ')')
            {
                while (s.top() != '(')
                {
                    res += s.top();
                    s.pop();
                }
                s.pop();
            }
            else
            {
                while (!s.empty() && m[s.top()] >= m[c])
                {
                    res += s.top();
                    s.pop();
                }
                s.push(c);
            }
        }
    }

    // 不要忘了栈里面可能还剩有元素
    while (!s.empty())
    {
        res += s.top();
        s.pop();
    }

    return res;
}

int main()
{
    char forum1[100] = "a+b-a*((c+d)/e-f)+g";
    char forum2[100] = "A+B-C*D/E+F";

    cout << trans(forum1) << '\n';


    return 0;
}
/*
 * 代码逻辑
 *
 * 对a~z A~Z: 直接加入后缀表达式
 * 左括号(: 直接加入
 * 右括号): 一直出栈，直到将'('出栈，并都加入后缀表达式
 * 加减乘除符号: 保证栈内符号优先级严格增,即若栈顶元素优先级高于或等于入栈元素，则出栈(并加入后缀表达式)；否则入栈
 *
 * 最后检测栈是否为空，若不空则全部出栈并加入后缀表达式
 */