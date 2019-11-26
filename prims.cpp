#include<bits/stdc++.h>
using namespace std;

int minindex(int key[],bool set[],int n){
  int min=999,min_index;
  for(int i=0;i<n;i++){
    if(set[i]==false && key[i]<min){
      min=key[i];
      min_index=i;
    }
  }
  return min_index;
}

void print(int p[],vector<vector<int>> g,int n){
  cout<<"Edge\tWeight\n";
  for(int i=1;i<n;i++)
    cout<<p[i]<<"-"<<i<<"\t"<<g[i][p[i]]<<"\n";
}

void prims(vector<vector<int>> g,int n){
  int parent[n],key[n];
  bool set[n];

  for(int i=0;i<n;i++){
    key[i]=999;
    set[i]=false;
  }

  key[0]=0;
  parent[0]=-1;

  for(int i=0;i<n;i++){
    int u=minindex(key,set,n);
    set[u]=true;
    for(int v=0;v<n;v++){
      if(g[u][v] && set[v]==false && g[u][v]<key[v]){
        parent[v]=u;key[v]=g[u][v];
      }
    }
  }

  print(parent,g,n);
}


int main(){
  int n;
  cout<<"Enter number of elements in lists:\n";
  cin>>n;
  vector<vector<int>> a;
  for(int i=0;i<n;i++){
    vector<int> temp;
    for(int j=0;j<n;j++){
      int ele;
      cin>>ele;
      temp.push_back(ele);
    }
    a.push_back(temp);
  }

  prims(a,n);
  return 0;
}
