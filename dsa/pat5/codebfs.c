#include <stdio.h>
#include <limits.h>
#include <stdbool.h>
void bfs(int graph[7][7],int n, int source, int goal){
    int queue[7];
    int front=0,rear=0;
    int parent[7];
    bool visted[7]={false};

    queue[rear++]=source;
    visted[source]=true;
    parent[source]=-1;

    while(front<rear){
        int node= queue[front++];
        if(node==goal) break;

        for(int i=0;i<n;i++){
            if(graph[node][i]==1 && !visted[i]){
                queue[rear++]=i;
                visted[i]=true;
                parent[i]=node;

            }
        }
        
    }
    int path[7],length=0;
        for(int v=goal;v!=-1; v=parent[v]){
            path[length++]=v;
        }
        for(int i=length-1;i>=0;i--){
            printf("%d ", path[i]);
        }
}


int main() {
    int n;
    scanf("%d", &n);
    int graph[7][7];
    
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            scanf("%d", &graph[i][j]);
        }
    }
    
    int source, goal;
    scanf("%d %d", &source, &goal);
    
    if (source < 0 || goal < 0 || source >= n || goal >= n) {
        printf("Not found\n");
        return 0;
    }
    
    bfs(graph, n, source, goal);
    
    return 0;
}
