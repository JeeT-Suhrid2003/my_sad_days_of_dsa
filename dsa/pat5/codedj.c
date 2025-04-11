// You are using GCC

#include <stdio.h>
#include <limits.h>

int minidis(int dist[], int visit[],int n){
    int min= INT_MAX,min_index;
    for(int v=0;v<n;v++){
        if(!visit[v] && dist[v]<=min){
            min=dist[v];
            min_index=v;
        }
    }
    return min_index;
}

void dj(int n,int graph[n][n], int src){
    
    int dist[100], visit[100];
    
    for(int i=0;i<n;i++){
        dist[i]=INT_MAX;
        visit[i]=0;
        
    }
    dist[src]=0;
    for(int count=0;count<n-1; count++){
        int u = minidis(dist,visit,n);
        visit[u]=1;
        
        for(int v=0;v<n;v++){
            if(!visit[v] && graph[u][v] && dist[u] != INT_MAX && dist[u]+graph[u][v]<dist[v]){
                dist[v]=dist[u]+graph[u][v];
            }
        }
    }
    printf("vertex\n");
    for(int i=0;i<n;i++){
        printf("%d %d\n",i,dist[i]);
    }
}

int main(){
    int n,src;
    scanf("%d",&n);
    int graph[n][n];
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            scanf("%d",&graph[i][j]);
        }
    }
    scanf("%d",&src);
    dj(n,graph,src);
}










