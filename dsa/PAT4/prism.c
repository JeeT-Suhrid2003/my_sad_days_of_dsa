#include <stdio.h>
#include <limits.h>
#include <stdbool.h>

int minkey(bool mstset[],int key[]){
    int min=INT_MAX,min_index;

    for(int i=0;i<5;i++){
        if(key[i]<min && mstset[i]==false)
            min=key[i], min_index=i;
    }
    return min_index;
}

void printing(int parent[],int graph[5][5]){
    printf("edge \tweight\n");
    for(int i=1;i<5;i++){
        printf("%d -%d \t%d \n",parent[i],i,graph[parent[i]][i]);
    }
}

void prismmst(int graph[5][5]){
    int parent[5];
    int key[5];
    bool mstset[5];

    for(int i=0;i<5;i++){
        mstset[i]=false, key[i]=INT_MAX;
    }

    key[0]=0;
    parent[0]=-1;

    for(int count=0;count<5-1;count++){
        int u=minkey(mstset,key);
        mstset[u]=true;

        for(int i=0;i<5;i++){
            if(graph[u][i]&& mstset[i]==false&& graph[u][i]<key[i])
                parent[i]=u, key[i]=graph[u][i];

        }


    }
    printing(parent,graph);
}
int main(){
    int graph[5][5]={ 
    { 0, 2, 0, 6, 0 },
    { 2, 0, 3, 8, 5 },
    { 0, 3, 0, 0, 7 },
    { 6, 8, 0, 0, 9 },
    { 0, 5, 7, 9, 0 } };
    prismmst(graph);
}