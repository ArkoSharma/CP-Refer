#include<bits/stdc++.h>
#define fo(i,a,b) for(int i=a;i<b;i++)
int parent[2001];
bool ice[2001];
int find (int d){
  if(d==parent[d]){
    return d;
  }
  //else
  return parent[d]=find(parent[d]);
}
void unions(int x,int y){
  if(parent[x]!=parent[y]){
    parent[parent[x]]=parent[y];
  }
}
int main(){
  int n;
  memset(ice,0,sizeof(ice));
  scanf("%d",&n);
  parent[0]=-1;
  fo(i,1,2001){
    parent[i]=i;
  }
  while(n--){
    int x,y;
    scanf("%d %d",&x,&y);
    ice[x]=ice[y+1000]=1;
    if(find(x)==find(y+1000)){
        continue;
    }
    unions(x,y+1000);
  }
  int placed[2001],ans=0;
  memset(placed,0,sizeof placed);
  fo(i,1,2001){
    //if this ice cube is not given in ques
    if(!ice[i]){
      continue;
    }
    //if the representative of this ice cube has not been placed
    //mistake ---required "find" here 
    //placed[parent[i]] may give wrong answer as we need the final parent of the ice block,which we get from find 
    if(!placed[find(i)]){
      //then place it
      placed[parent[i]]=1;
      ans++;
    }

  }
  printf("%d",ans-1);// ans contains beginning ice cube too, which is subtracted
}
