#include <iterator>
#include <cmath>
#include <iostream>

#include <list>
#include <queue>
#include <stack>
#include <vector>
#include <map>

#include "BFS.h"

using namespace std;

BFS::BFS(ADJList graph,Airport start){
    
    queue_.push(start);
    for(int i =0; i<7699; i++){
        visited.push_back(false);
    }
    visited[graph.find(start.code)]=true;

    while(!queue_.empty()){
        Airport node = queue_.front();
        

        ADJList::edgeList templ = graph.getList(node.code);
        ADJList::edge* temp = templ.getHead();
        while(temp != NULL){
            if(visited[graph.find(temp->destination.code)] == false){
                visited[graph.find(temp->destination.code)] = true;
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

vector<Airport> BFS::Shortest(ADJList graph,Airport a,Airport b){
    vector<Airport> path;
    queue<Airport> q;
    vector<bool> v;
    int dist[7699];
    vector<Airport> previous;
    for(int i = 0;i<7699;i++){
        dist[i] = INFINITY;
        Airport tempair = Airport();
        previous.push_back(tempair);
        v.push_back(false);
    }
    dist[graph.find(a.code)] = 0;
    v[graph.find(a.code)] = true;
    q.push(a);
    while(!q.empty()){
        Airport node = q.front();
        ADJList::edgeList templ = graph.getList(node.code);
        ADJList::edge* temp = templ.getHead();
        while(temp != NULL){
            if(v[graph.find(temp->destination.code)]==false){
                v[graph.find(temp->destination.code)] = true;
                if((dist[graph.find(node.code)] + temp->weight) < dist[graph.find(temp->destination.code)]){
                    dist[graph.find(node.code)] += temp->weight;
                    previous[graph.find(temp->destination.code)] = node;
                    q.push(temp->destination);
                    temp = temp->next;
                }
                else{
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
    unsigned int i = graph.find(b.code);
    while(!(previous[i].code == a.code)){
        stack.push(previous[i]);
        unsigned int temp = graph.find(previous[i].code);
        i = temp;
    }
    stack.push(previous[i]);
    for(unsigned int i = 0;i<stack.size();i++){
        path.push_back(stack.top());
        stack.pop();
    }

    return path;
}

