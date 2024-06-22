/*
Count the number of binary strings with no consecutive ones that can be formed using a binary string of length n


Input : N

Output : Count of Strings
*/

#include<bits/stdc++.h>
using namespace std;


int countStrings(int n){
    if(n==0) return 1;
    if(n==1) return 2;

    return countStrings(n-1)+countStrings(n-2);
}

int main(){
    cout<<countStrings(3)<<endl;
}

