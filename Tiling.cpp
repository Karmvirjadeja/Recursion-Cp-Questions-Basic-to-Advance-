/*
Given a "4*n" board and tiles of size "4*1" , cout the number of ways to tile
the given board using the 4*1 tiles

A tile can either be placed horizontally i.e as a 1*4 tile or vetically i.e as 4*1 tile 


Input : N

Output : No of ways 

*/


#include<bits/stdc++.h>
using namespace std;

int NoOfWays(int n){
    if(n<=3) return 1;
    return NoOfWays(n-1)+NoOfWays(n-4);
}

int main(){
    cout<<NoOfWays(10)<<endl;
}

