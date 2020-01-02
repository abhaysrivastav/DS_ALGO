#include <iostream>
#include <list>

using namespace std;

class Graph{

private:
    int V;
    list<int> *adj;
public:
    Graph(int V);

    // Function to add an edge to the graph
    void addEdge(int v, int w);

    //print BFS traversal
    void BFS(int s);
};

Graph::Graph(int V){
    this->V = V;
    adj = new list<int>[V];
}

void Graph::addEdge(int v, int w){
    adj[v].push_back(w);
}

void Graph::BFS(int s){

    // Mark all the vertices as not visited
    bool *visited = new bool[V];
    for(int i = 0; i < V; i++){
        visited[i] = false;
    }

    //Create a queue for BFS
    list<int> queue;
    visited[s] = true;
    queue.push_back(s);

    list<int>::iterator itr;
    int tmp;
    while(!queue.empty()){
        tmp = queue.front();
        cout << tmp << endl;
        queue.pop_front();

        for(itr = adj[tmp].begin(); itr!= adj[tmp].end();++itr){
            if(!visited[*itr]){
                visited[*itr] = true;
                queue.push_back(*itr);
            }
        }
    }
}


int main()
{
    // Create a graph given in the above diagram
    Graph g(4);
    g.addEdge(0, 1);
    g.addEdge(0, 2);
    g.addEdge(1, 2);
    g.addEdge(2, 0);
    g.addEdge(2, 3);
    g.addEdge(3, 3);

    cout << "Following is Breadth First Traversal "
         << "(starting from vertex 2) \n";
    g.BFS(2);

    return 0;

}
