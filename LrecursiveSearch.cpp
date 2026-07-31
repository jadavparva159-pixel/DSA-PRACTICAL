#include<bits/stdc++.h>
using namespace std;

int recursiveSearch(string arr[],int n, int index,string target){
    if(index==n)return -1; 
    if(arr[index]==target)return index;
    
   return  recursiveSearch(arr, n, index+1, target);

}
  
  int main(){
    string plates[]={"GJ01AB1234", "GJ05XY5678", "MH12CD9876", "RJ14PQ1111"};
    int n = 4;
    string target= "MH12CD9876";

    int ans = recursiveSearch(plates, n, 0, target);
   if(ans!=-1){ cout<< "found the target:"<<ans;}

   else {cout<<"not found";}

  }