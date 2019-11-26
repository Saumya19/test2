#include<bits/stdc++.h>
using namespace std;

void knapsack(int w[],int v[],int n,int wt){
  int c[n+1][wt+1];
  for(int i=0;i<=n;i++)c[i][0]=0;
  for(int i=0;i<=wt;i++)c[0][i]=0;
  for(int i=1;i<=n;i++){
    for(int j=1;j<=wt;j++){
      if(j-w[i] >=0)
        c[i][j]=max(c[i-1][j],v[i]+c[i-1][j-w[i]]);
      else
        c[i][j]=c[i-1][j];
      }
  }
  cout<<"Total Price:"<<c[n][wt]<<"\n";
  int i=n,j=wt,sum=0;
  while(i>0 && j>0){
    if(c[i-1][j]==c[i][j])i--;
    else{
      if(c[i][j]==c[i-1][j-w[i]]+v[i]){
        cout<<"w:"<<w[i]<<" v:"<<v[i]<<"\n";
        sum+=v[i];
        j=j-w[i];
        i--;
      }
    }
  }
  if(sum==c[n][wt])cout<<endl;
  else
    cout<<"w:"<<w[i]<<" v:"<<v[i]<<"\n";
}


int main(){
  cout<<"Enter knapsack capacity:\n";
  int n,wt;
  cin>>wt;
  cout<<"Enter number of items:\n";
  cin>>n;
  int w[n+1],v[n+1];
  cout<<"enter weights\n";
  for(int i=1;i<=n;i++)
    cin>>w[i];
  cout<<"enter values\n";
  for(int j=1;j<=n;j++)
    cin>>v[j];
  knapsack(w,v,n,wt);
  return 0;
}
