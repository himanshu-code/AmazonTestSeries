#include<bits/stdc++.h>
using namespace std;
int convertToFiveRec(int n){
    if(n==0)return 0;
    int digit=n%10;
    if(digit==0)digit=5;
    
    return convertToFiveRec(n/10)*10+digit;
}
int convertToFive(int n){
    if(n ==0)return 5;
    return convertToFiveRec(n);
}
int main(){
    int n;
    cin>>n;
    cout<<convertToFive(n);
}