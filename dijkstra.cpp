#include<bits/stdc++.h>
using namespace std;
void dijkstra(vector<vector<int>> c,int src,int n){
  int dist[n],vist[n],count=1,min=0,u=0;
  for(int j=0;j<n;j++)
    dist[j]=c[src][j];

  for(int j=0;j<n;j++)
    vist[j]=0;

  dist[src]=0;
  vist[src]=1;
  while(count!=(n))
  {
    min=999;
    for(int j=0;j<n;j++){
      if(dist[j]<min && vist[j]!=1){
        min=dist[j];
        u=j;
      }
    }
    vist[u]=1;
    count++;
    for(int j=0;j<n;j++){
      if((min+c[u][j])<dist[j] && vist[j]!=1){
        dist[j]=min+c[u][j];
      }
    }
  }
  for(int j=0;j<n;j++){
    cout<<src<<" ->"<<j<<"="<<dist[j]<<"\n";
  }
}



int main(){
  int n,src;
  cout<<"enter number of nodes\n";
  cin>>n;
  vector<vector<int>> c;
  cout<<"enter the cost matrix\n";
  for(int i=0;i<n;i++){
    vector<int> temp;
    for(int j=0;j<n;j++){
      int ele;
      cin>>ele;
      temp.push_back(ele);
    }
    c.push_back(temp);
  }

  dijkstra(c,0,n);
  /*
  999 4  999 999 999 999 999 8 999
  4 999 8 999 999 999 999 11 999
  999 8 999 7 999 4 999 999 2
  999 999 7 999 9 14 999 999 999
  999 999 999 9 999 10 999 999 999
  999 999 4 14 10 999 2 999 999
  999 999 999 999 999 2 999 1 6
  8 11 999 999 999 999 1  999 7
  999 999 2 999 999 999 6 7 999
  output:
  0 ->0=0
0 ->1=4
0 ->2=12
0 ->3=19
0 ->4=21
0 ->5=11
0 ->6=9
0 ->7=8
0 ->8=14
  */
  return 0;
}
