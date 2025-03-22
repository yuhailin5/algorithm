/*
 * @Description: 栈的应用：表达式计算与转换
 * @Author: 天涯过客
 * @Date: 2025-03-22 17:38:41
 */
#include<bits/stdc++.h>
using namespace std;

bool isDigit(char c) {
    return c>='0'&&c<='9';
}

bool isOperator(char c) {
    return c=='+'||c=='-'||c=='*'||c=='/';
}

bool isLeft(char c) {
    return c=='(';
}

bool isRight(char c) {
    return c==')';
}
int getPriority(char c) {
    if (c=='+'||c=='-') {
        return 1;
    }else if (c=='*'||c=='/') {
        return 2;
    }
    return 0;// '('停止弹出
}

string getBackExpression(string s) {
    stack<char> op;
    string res;
    for (int i = 0;i<s.size();i++) {
        char cur = s[i];
        if (isDigit(cur)) {
            res.push_back(cur);
        }else if (isLeft(cur)) {
            op.push(cur);
        }else if (isRight(cur)) {
            while (!op.empty()&&op.top()!='(') {
                res.push_back(op.top());
                op.pop();
            }
            op.pop();
        }else if (isOperator(cur)) {
            int curPriority = getPriority(cur);
            while (!op.empty()&&getPriority(op.top())>=curPriority) {
                res.push_back(op.top());
                op.pop();
            }
            op.push(cur);
        }
    }
    while (!op.empty()) {
        res.push_back(op.top());
        op.pop();
    }
    return res;
}


void test() {
    string s = "1+2*3+(4*5+6)*7";
    cout<<getBackExpression(s)<<endl;
    s = "1+2*3";
    cout<<getBackExpression(s)<<endl;
    s = "1+2*3+4";
    cout<<getBackExpression(s)<<endl;
    s = "1+2*3/4+5";
    cout<<getBackExpression(s)<<endl;
}

int main() {
    test();
    return 0;
}