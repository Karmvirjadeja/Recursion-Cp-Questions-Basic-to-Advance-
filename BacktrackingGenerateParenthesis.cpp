Here first take the parenthesis and then back track and see if the combination is possible or not 




#include<bits/stdc++.h>
using namespace std;

void generateParenthesis(string Output,int n,int open,int close,int idx){
   if(idx==2*n){
    cout<<Output<<endl;
    return;
   }

   //Adding the opening brackets
 if(open<n){
    generateParenthesis(Output+'(',n,open+1,close,idx+1);
 }

   //Adding the closing brackets
   if(close<open){
    generateParenthesis(Output+')',n,open,close+1,idx+1);
   }

}
int main(){
    int n;
    cin>>n;

    generateParenthesis("",n,0,0,0);

}
