#include <bits/stdc++.h>
using namespace std;
int main(){
    vector<int>arr={1,2,4,4,5,6};
   
    set<int>s;
    for(int i=0;i<arr.size();i++){
        if(s.find(arr[i])!=s.end()){
            cout<<"true";
        }
        s.insert(arr[i]);
    }
}