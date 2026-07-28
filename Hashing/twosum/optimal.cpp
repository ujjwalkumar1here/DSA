// #include<bits/stdc++.h>
// using namespace std;
// int main(){
//     vector<int>arr={1,3,4,5,7};
//     int target =10;

//    bool a=false;

//     for(int i=0;i<arr.size();i++){
//         for(int j=i+1;j<arr.size();j++){

//             if(arr[i]+arr[j]==target){
//                 cout<<i<<" "<<j;
//                a=true;
//             };


//         };
//     };
//     if(!a){
//         cout<<"no matching pair";
//     };
// }


#include<bits/stdc++.h>
using namespace std;

int main(){

    vector<int>arr={1,2,3,4,5,6,7};
    int target = 9;

    unordered_map<int,int>mp;

    for(int i=0;i<arr.size();i++){
        int a=target-arr[i];
        if(mp.find(a)!=mp.end()){
            cout<<i<<" "<<mp[a];
            break;
        }


        mp[arr[i]]=i;

    }
}