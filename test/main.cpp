#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <stack>
using namespace std;

void append(stack<string>& history, string& S, string W){
    history.push(S);
    S+=W;
}
void deleteChars(stack<string>& history, string& S, int k){
    history.push(S);
    int size = S.size();
    S = S.substr(0, size - k);
}
void print(string S, int k){
    if(k >= 0 && k < S.size())
      cout << S.at(k) << endl;
}
void undo(stack<string> history, string &S){
    if(!history.empty()){
        S = history.top();
        history.pop();
    }
}
int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */  
    stack<string> history;
    string editor = "";
    int q;
    int operation;
    cin >> q;
    for(int i = 0; i < q; i++)
    {
        cin >> operation;
        switch(operation)
        {
            case 1:{
                string str;
                cin >> str;
                append(history,editor,str);
                break;
            }
            case 2:{
                int ch;
                cin >> ch;
                deleteChars(history,editor,ch);
                break;
            }
            case 3:{
                int ch;
                cin >> ch;
                if(ch >= 0 && ch < editor.size())
                  cout << editor.at(ch) << endl;;
                break;
            }
            case 4:{
                undo(history,editor);
                break;
            }
            case 5:{
                return 0;
            }
        }
    }
    return 0; 
}
