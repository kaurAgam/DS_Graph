#include <iostream>
#include<bits/stdc++.h>
using namespace std;

class graph{

    public:

    int v=0;
    bool directed=false;
    vector<vector<pair<int,int>>> g;

    graph(int n,bool b){
        v=n;
        directed=b;
        g.assign(v,{});}

    void addedge(int x,int y,int weight){
        if(directed==true){
            g[x].push_back({y,weight});
        }
        else{
             g[x].push_back({y,weight});
             g[y].push_back({x,weight});
        }
    }
    void display(){
        for(int i=0;i<v;i++){
            cout<<"Adjacency list of "<<i<<"th Vertex: head";
            for(auto x:g[i]){cout<<" - ["<<x.second<<"] -> "<<x.first;}
            cout<<endl;      }}

    void bfs(int vertex){
        int i=vertex;
        cout<<"BFS: "<<i;
        queue<int> q;
        q.push(i);
        vector<int> visited(v,0);
        visited[i]=1;
        while(q.empty()!=true){
            i=q.front();
            for(auto x:g[i]){
                if(visited[x.first]!=1){ 
                    cout<<"->"<<x.first;
                    visited[x.first]=1;
                    q.push(x.first);}
            }
            q.pop();
        }
        cout<<endl;
    }
    void dfs2(int vertex,vector<int>& visited){
        visited[vertex]=1;
        for(auto x:g[vertex]){
            if(visited[x.first]==0){
                cout<<"->"<<x.first;
                dfs2(x.first,visited);}}
        
        }

    void dfs(int v1){
        cout<<"DFS: "<<v1;
        vector<int> v2(v,0);
        dfs2(v1, v2);
        cout<<endl;
    }
};

int main() {
    graph g1(7,false);
    g1.addedge(0,1,10);
    g1.addedge(0,2,67);
    g1.addedge(1,6,6);
    g1.addedge(2,3,45);
    g1.addedge(2,6,0);
    g1.addedge(3,4,34);
    g1.addedge(3,5,4);
    g1.addedge(4,5,8);
    g1.addedge(5,6,71);
    g1.display();
    g1.bfs(3);
    g1.dfs(0);
    
return 0;
}