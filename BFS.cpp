#include <iterator>
#include <cmath>

#include <list>
#include <queue>
#include <stack>
#include <vector>
#include <map>

#include "BFS.h"

using namespace std;

BFS::BFS(Airport* start){
    ADJList graph = ADJList();
    vector<Airport> path;
    queue_.push(start);
    for(int i =0; i<7699; i++){
        visited.push_back(false);
    }
    visited[graph.find(start->name)]=true;

    while(!queue_.empty()){
        Airport node * = queue_.front();
        

        ADJList::edgeList templ = graph.getList(node.name);
        ADJList::edge* temp = templ.getHead();
        while(temp != NULL){
            if(visited[graph.find(temp->destination.name)] == false){
                visited[graph.find(temp->destination.name)] = true;
                queue_.push(temp->destination);
                temp = temp->next;
            }
            else{
                temp = temp->next;
            }
        }
        queue_.pop();
    }
}

vector<Airport> BFS::Shortest(Airport* a,Airport* b){
    ADJList graph = ADJList();
    vector<Airport> path;
    queue<Airport> q;
    vector<bool> v;
    int dist[7699];
    vector<Airport> previous;
    for(int i = 0;i<7699;i++){
        dist[i] = INFINITY;
        previous.push_back(new Airport());
        v.push_back(false);
    }
    dist[graph.find(a->name)] = 0;
    v[graph.find(a->name)] = true;
    q.push(a);
    while(!q.empty()){
        Airport node * = q.front();
        ADJList::edgeList templ = graph.getList(node.name);
        ADJList::edge* temp = templ.getHead();
        while(temp != NULL){
            if(v[graph.find(temp->destination.name)]==false){
                v[graph.find(temp->destination.name)] = true;
                if((dist[graph.find(node.name)] + temp->weight) < dist[graph.find(temp->destination.name)]){
                    dist[graph.find(node.name)] += temp->weight;
                    previous[graph.find(temp->destination.name)] = node;
                    q.push(temp->destination);
                    temp = temp->next;
                }
            }
            else{
                temp = temp->next;
            }
        }
        q.pop();
    }
    stack<Airport> stack;
    int i = graph.find(b->name);
    while(!(previous[i].name == a->name)){
        stack.push(previous[i]);
        int temp = graph.find(previous[i].name);
        i = temp;
    }
    stack.push(&a);
    //stack.push(previous[graph.find(a->name)]);
    for(unsigned int i = 0;i<stack.size();i++){
        path.push_back(stack.top());
        stack.pop();
    }

    return path;
}

