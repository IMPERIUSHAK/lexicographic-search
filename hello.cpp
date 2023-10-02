#include<iostream>
#include<vector>
#include<string>
using namespace std;
string find_string( int mid,const string s,const vector<int>&a){
        string c="";
        if(mid==0){
            mid+=1;
        }
        int k=a[mid],t=a[mid-1];
        while(t<=k){
            if(s[t]!=' '){
                c+=s[t];
            }
            t++;
        }
        return c;
}
int binary_search(const vector<int>&a,const string key,const string s){
    int left = 1,right = a.size()-1;
    
    while( left <= right ){
        int mid = (right+left)/2;
        if(find_string(mid,s,a)>key){
            right = mid-1;
        }
        else{
            left = mid+1;
        }
        if(find_string(mid,s,a)==key){
            return mid;
        }
    }
   return -1;
}
int main(){

    //input data
    int n , i = 0 , j = 0;
    cin >> n;
    string s = " ";
    vector<int> arr( n + 1 ) ;
    arr[0] = 0;
    string a,b;
    
    while( i < n ){
        cin >> a;
        s += a;
        j += a.length() + 1;
        arr[i+1] = j;
        s += " ";
        i++;
    }
    int m,k=0;
    cin>>m;
    while(k<m){
        cin>>b;
        cout<<binary_search(arr,b,s)<<endl;
        k++;
    }
}
