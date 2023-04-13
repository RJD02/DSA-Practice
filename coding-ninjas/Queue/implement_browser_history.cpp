#include<bits/stdc++.h>
using namespace std;

/*
#include<bits/stdc++.h>
using namespace std;

int main()
{
    
       // 1 ---- visit
       // 2 ---- back
       // 3 ---- forward
    string input;
    cin>>input;
    BrowserHistory obj(input);
    int i,k;
    cin>>i;
    while(i)
    {
        switch(i)
        {
            case 1: cin>>input;
                    obj.visit(input);
                    break;
            case 2: cin>>k;
                    input=obj.back(k);
                    cout<<input<<endl;
                    break;
            case 3: cin>>k;
                    input=obj.forward(k);
                    cout<<input<<endl;
                    break;
            default: return 0;
        }
        cin>>i;
    }
    return 0;
}
*/

class BrowserHistory {
    stack<string> history, future;
    string current;

public:
    BrowserHistory(string homepage) {
        current = homepage;
    }
    
    void visit(string url) {
        history.push(current);
        current = url;
        future = stack<string>();
    }
    
    string back(int steps) {
        while(!history.empty() and steps--) {
            future.push(current);
            current = history.top();
            history.pop();
        }
        return current;
    }
    
    string forward(int steps) {
        while(!future.empty() and steps--) {
            history.push(current);
            current = future.top();
            future.pop();
        }
        return current;
    }
};



int main()
{
    /*
       1 ---- visit
       2 ---- back
       3 ---- forward
    */
    string input;
    cin>>input;
    BrowserHistory obj(input);
    int i,k;
    cin>>i;
    while(i)
    {
        switch(i)
        {
            case 1: cin>>input;
                    obj.visit(input);
                    break;
            case 2: cin>>k;
                    input=obj.back(k);
                    cout<<input<<endl;
                    break;
            case 3: cin>>k;
                    input=obj.forward(k);
                    cout<<input<<endl;
                    break;
            default: return 0;
        }
        cin>>i;
    }
    return 0;
}