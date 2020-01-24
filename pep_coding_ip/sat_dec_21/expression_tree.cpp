// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

struct et
{
	char value;
	et* left, *right;
	
	et(char x){
	    value = x;
	    left = right = NULL;
	}
};

bool isOperator(char c)
{
	if (c == '+' || c == '-' ||
			c == '*' || c == '/' ||
			c == '^')
		return true;
	return false;
}

void inorder(et *t)
{
	if(t)
	{
		inorder(t->left);
		printf("%c ", t->value);
		inorder(t->right);
	}
}

et* constructTree(char []);

int main()
{   
    int t;
    cin>>t;
    while(t--){
    char postfix[25];
	cin>>postfix;
	et* r = constructTree(postfix);
	inorder(r);
	cout<<endl;
}
return 0;
}// } Driver Code Ends
/*struct et
{
	char value;
	et* left, *right;
};*/

//function to construct expression tree
et* constructTree(char postfix[])
{
    stack<et*> stk;
    for(int i=0;postfix[i]!='\0';i++) {
        if(postfix[i]>='a' && postfix[i]<='z') {
            et *newnode=new et(postfix[i]);
            stk.push(newnode);
        } else {
            et *newnode=new et(postfix[i]);
            et *right=stk.top();stk.pop();
            et *left=stk.top();stk.pop();
            newnode->left=left;
            newnode->right=right;
            stk.push(newnode);
        }
    }
    // cout<<endl;
    
    return stk.top();
}
