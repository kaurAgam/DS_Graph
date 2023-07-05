#include <iostream>
#include<bits/stdc++.h>
using namespace std;

class graph{

    public:

    int v=0;
    bool directed=false;
    vector<vector<int>> g;

    graph(int n,bool b){
        v=n;
        directed=b;
        g.assign(v,{});}

    void addedge(int x,int y){
        if(directed==true){
            g[x].push_back(y);
        }
        else{
            g[x].push_back(y);
            g[y].push_back(x);
        }
    }
    void display(){
        for(int i=0;i<v;i++){
            cout<<"Adjacency list of "<<i<<"th Vertex: head";
            for(auto x:g[i]){cout<<"->"<<x;}
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
                if(visited[x]!=1){ 
                    cout<<"->"<<x;
                    visited[x]=1;
                    q.push(x);}
            }
            q.pop();
        }
        cout<<endl;
    }

    void dfs2(int vertex,vector<int>& visited){
        visited[vertex]=1;
        for(auto x:g[vertex]){
            if(visited[x]==0){
                cout<<"->"<<x;
                dfs2(x,visited);}}
        
        }

    void dfs(int v1){
        cout<<"DFS: "<<v1;
        vector<int> v2(v,0);
        dfs2(v1, v2);
        cout<<endl;
    }
};

int main() {
    graph g1(5,false);
    g1.addedge(0,1);
    g1.addedge(0,2);
    g1.addedge(1,2);
    g1.addedge(1,3);
    g1.addedge(2,4);
    g1.addedge(3,4);
    g1.display();
    g1.bfs(4);
    g1.dfs(0);
    graph g2(4,false);
    g2.addedge(0,1);
    g2.addedge(0,2);
    g2.addedge(1,2);
    g2.addedge(1,3);
    g2.display();
return 0;
}