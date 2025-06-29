#include <bits/stdc++.h>
using namespace std;

bool isSafe(int node, vector<vector<bool>>& graph, int c, int v, vector<int> &color, int col){
    for(int k=0; k<v; k++)
        if(graph[node][k] && color[k] == col)
            return false;
    return true;
}

bool graphColoring(int node, vector<vector<bool>>& graph, int c, int v, vector<int> &color){
    if(node==v)
        return true;

    for(int col=1; col<=c; col++){
        if(isSafe(node, graph, c, v, color, col)){
            color[node] = col;
            if (graphColoring(node+1, graph, c, v, color))
                return true;
            color[node] = 0;
        }
    }
    return false;
}

int main() {
    int v,c,e;
    cout<<"Enter number of Vertices: ";
    cin>>v;
    cout<<"Enter number of Colors: ";
    cin>>c;
    cout<<"Enter number of edges: ";
    cin>>e;
    vector<vector<bool>> graph(v, vector<bool>(v, false));
    vector<int> color(v, 0);

    for(int i=0; i<e; i++){
        int t1, t2;
        cout<<"Enter the nodes you want to connect for edge "<<i<<": ";
        cin>>t1;
        cin>>t2;
        graph[t1][t2] = 1;
        graph[t2][t1] = 1;
    }

    if (graphColoring(0, graph, c, v, color))
        cout << "Yes, coloring is possible\n";
    else
        cout << "No, coloring is not possible\n";

    return 0;
}