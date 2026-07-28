#include <bits/stdc++.h>
using namespace std;
int main(){

  string s="anagram";
  string a="nagarm";

//   sort(s.begin(),s.end());
//   sort(a.begin(),a.end());
//   for(int i=0;i<s.size();i++){
//     if(s[i]!=a[i]){
//         cout<<"false";
//         break;
//     }
//   }

 vector<int>arr(255,0);
 for(int i=0;i<a.size();i++){
    arr[a[i]]++;

 }
 for(int i=0;i<s.size();i++){
    arr[s[i]]--;
    
 }
 for(int i=0;i<arr.size();i++){
    if(arr[i]!=0){
        cout<<"false";
    }
 }

}