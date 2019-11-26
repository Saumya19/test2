#include<bits/stdc++.h>
using namespace std;

bool isSubSet(int a[],int n,int sum){
  if(sum==0)return true;
  if(n==0 && sum!=0) return false;

  if(a[n-1]>sum)
    return isSubSet(a,n-1,sum);
  return isSubSet(a,n-1,sum) || isSubSet(a,n-1,sum-a[n-1]);
}

bool find(int a[],int n){
  int sum=0;
  for(int i=0;i<n;i++)
    sum+=a[i];
  if(sum%2!=0)
    return false;
  return isSubSet(a,n,0);
}

int main(){
  int n;
  cout<<"enter number of elements\n";
  cin>>n;
  int a[n];
  cout<<"enter elements\n";
  for(int i=0;i<n;i++)
    cin>>a[i];
  if(find(a,n))
    cout<<"True";
  else
    cout<<"False";
  return 0;
}
