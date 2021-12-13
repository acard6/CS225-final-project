#include <iterator>
#include <cmath>

#include <list>
#include <queue>
#include <stack>
#include <vector>
#include <map>

BFS::BFS(const Airport& start){
    ADJList graph = ADJList();
    std::vector<Airport> path;
    start_ = start;
    queue_.push(start_);
    for(int i =0; i<7699; i++){
        visited.push_back(false);
    }
    visited[find(start.name)]=true;

    while(!queue_.empty()){
        Airport node* = queue_.front();
        

        edgeList templ = graph.getList(node);
        edge temp = templ.getHead();
        while(temp != NULL){
            if(visited[find(temp.destination.name)]==false){
                visited[find(temp.destination.name)] == true;
                queue_.push(temp.destination);
                temp = temp.next;
            }
            else{
                temp = temp.next;
            }
        }
        queue_.pop();
    }
}
vector<Airport> BFS::Shortest(Airport a,Airport b){
    ADJList graph = ADJList();
    std::vector<Airport> path;
    std::queue<Airport> q;
    std::vector<bool> v;
    int dist[7699];
    std::vector<Airport> previous;
    for(int i = 0;i<7699;i++){
        dist[i] = INFINITY;
        previous.push_back(NULL);
        v.push_back(false);
    }
    dist[find(a.name)] = 0;
    previous[find(a.name)] = -1;
    v[find(a.name)] = true
    q.push(a);
    while(!q.empty()){
        Airport node* = q.front();
        edgeList templ = graph.getList(node);
        edge temp = templ.getHead();
        while(temp != NULL){
            if(v[find(temp.destination.name])==false){
                if((dist[find(node.name)] + temp.weight) < dist[find(temp.destination.name)]){
                    dist[find(node.name)] =+ temp.weight;
                    previous[find(temp.destination.name)] = node;
                    q.push(temp.destination);
                    temp.next;
                    dist[find(temp.destination.name)] =+ temp.weight;
                    previous[find(temp.destination.name)] = *node;
                    q.push(temp.destination);
                    temp = temp.next;
                }
                else{
                    dist[find(node.name)] =+ temp.weight;
                    previous[find(node.name)] = temp.destination;
                    q.push(temp.destination);
                    temp = temp.next;
                }
            }
            else{
                temp = temp.next;
            }
        }
        q.pop();
    }
    stack<Airport> stack;
    int i = find(b.name);
    while(previous[i]!= -1){
        stack.push(previous[i]);
        int temp = find(previous[i].name);
        i = temp;
    }
    stack.push(previous[find(a.name)]);
    for(unsigned int i = 0;i<stack.size();i++){
        path.push(stack.top());
        stack.pop();
    }

    return path;
}

