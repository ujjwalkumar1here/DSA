# include<bits/stdc++.h>
using namespace std;
int main(){
    vector<int>arr={3,2,3};
  int n=arr.size();
    // vector<int>a(n,0);

    // for(int i=0;i<arr.size();i++){
    //     int count=1;

    //     for(int j=i+1;j<arr.size();j++){
    //         if(arr[i]==arr[j])count++;
    //         a[i]=count;

    //     }
    //      a[i]=count;

    // }
  

    // for(int i=0;i<a.size();i++){
    //     if(a[i]>n/2)cout<<"true";
    // }


            // better approach
    // unordered_map<int,int>mp;
    // for(int i=0;i<arr.size();i++){
    //     mp[arr[i]]++;
    // }

    // for(auto it:mp){
    //     if(it.second>n/2)cout<<"true";
    // }


     int candidate=0;
     int vote=0;

     for(int i=0;i<arr.size();i++){
        if(vote==0){
            candidate=arr[i];
        }

        if(arr[i]==candidate)vote++;
        else vote--;
     }

   cout<<candidate;
}