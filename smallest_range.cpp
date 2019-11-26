#include<bits/stdc++.h>
using namespace std;

void find(vector<vector<int>> a,int n,int k){
  int i,minval,maxval,minrange,minel,maxel,flag,minindex;
  int p[k+1];
  for(i=0;i<=k;i++)
    p[i]=0;
  minrange=999;

  while(1){
    minindex=-1;
    minval=999;
    maxval=-1;
    flag=0;

    for(i=0;i<k;i++){
      if(p[i]==n){
        flag=1;break;
      }

      if(p[i]<n && a[i][p[i]]<minval)
      {
        minindex=i;
        minval=a[i][p[i]];
      }

      if(p[i]<n && a[i][p[i]]>maxval)
        maxval=a[i][p[i]];
    }

    if(flag)
      break;
    p[minindex]++;
    if((maxval-minval)<minrange){
      minel=minval;
      maxel=maxval;
      minrange=maxel-minel;
    }
  }
  cout<<"The smallest range:"<<minel<<" "<<maxel<<"\n";
}


int main(){
  int k,n;
  cout<<"Enter number of lists:\n";
  cin>>k;
  cout<<"Enter number of elements in lists:\n";
  cin>>n;
  vector<vector<int>> a;
  for(int i=0;i<k;i++){
    vector<int> temp;
    for(int j=0;j<n;j++){
      int ele;
      cin>>ele;
      temp.push_back(ele);
    }
    a.push_back(temp);
  }

  find(a,n,k);
  return 0;
}
