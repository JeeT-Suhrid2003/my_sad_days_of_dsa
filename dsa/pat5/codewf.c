// You are using GCC
#include <stdio.h>

#define INF 999

void floyd(int n, int graph[n][n]){
    int dist[n][n];
    
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            dist[i][j] =graph[i][j];
            
        }
    }
    
    for(int k=0;k<n;k++){
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                if(dist[i][k] != INF && dist[k][j] != INF){
                    if(dist[i][j]> dist[i][k] +  dist[k][j]){
                        dist[i][j]= dist[i][k] + dist[k][j];
                    }
                }
            }
        }
    }
    
    
    printf("transitive clousure\n");
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            printf("%d ",dist[i][j]);
        }
        printf("\n");
    }
}

int main(){
    int n,e;
    int u,v,w;
    scanf("%d %d",&n,&e);
    int graph[n][n];
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            if(i==j){
                graph[i][j]=0;
            }
            else
            graph[i][j]=INF;
        }
    }
    
    for(int i=0;i<e;i++){
        scanf("%d %d %d",&u,&v,&w);
        graph[u-1][v-1]=w;
    }
    
    printf("matrix input\n");
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            printf("%d ",graph[i][j]);
        }
        printf("\n");
    }
    floyd(n,graph);
}















