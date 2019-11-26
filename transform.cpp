#include<bits/stdc++.h>
using namespace std;

int min(int x,int y,int z){
  return min(min(x,y),z);
}

int edit(string s1,string s2,int m,int n){
  if(m==0) return n;
  if(n==0) return m;
  if(s1[m-1]==s2[n-1])
    return edit(s1,s2,m-1,n-1);
  return 1+ min( edit(s1,s2,m,n-1),
                edit(s1,s2,m-1,n),
                edit(s1,s2,m-1,n-1)
              );
}

int main(){
  string s1,s2;
  cout<<"Enter two strings\n";
  cin>>s1;
  cout<<"enter string 2:\n";
  cin>>s2;
  cout<<edit(s1,s2,s1.length(),s2.length());
  return 0;
}
