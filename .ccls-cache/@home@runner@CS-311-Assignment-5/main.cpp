//#luisRodriguezA5

#include <iostream>
using namespace std;


struct edge{
  int vrt_edge;
  edge *next;
};


class Graph {
private:
int v;
edge** adj;
void DFUtil(int v,bool vistited[]);


public:
Graph(int V); // constructor
void addEdge(int v,int w); // function to add an edge
void BFS(int s); // prints BFS Traversal 
void DFS(int v); // prints
void DFSUtil(int v, bool visited[]);

};

class Queue{
private:
edge* head = nullptr;



public:  
Queue()
{
  head = nullptr;
}

int dequeue();
void enqueue(int input);
void display();
int size();

};



int main() {
Graph g(10);
cout << "adding edges!" << endl;
g.addEdge(10, 5);
g.addEdge(5, 25);
g.addEdge(10,100);
g.addEdge(5, 75);
cout << "BFS" << endl;
g.BFS(10);
  
cout << endl;
cout << "DFS traversal" << endl;
g.DFS(10);



  
}
int Queue::size(){
    int count = 0;
    edge* current = head; // start at the head of the list
    while (current != nullptr) {
        count++;
        current = current->next; // move to the next node
    }
    return count;
}


void Queue::enqueue(int input){

  
  edge* temp = this->head;
 
      if (head == nullptr)
      {
        head = new edge{input,nullptr};
        temp = head;
      }
      else
      {
      temp->next = new edge{input,nullptr};
      temp = temp->next;
      }


      
    
  cout << endl;
}
void Queue::display()
{
   edge* temp = head;
  if(this->head == nullptr)
  {
    cout << "List is empty" << endl;
    return;
  }
  cout << "Now displaying Queue " << endl;
  while(temp != nullptr) 
  {
    cout << temp->adj_vtx << " ";
    temp = temp->next;
  }
  cout << endl;
}

int Queue::dequeue(){
  int tempValue;
  
  edge* temp = head;
   
  if(head == nullptr)
  {
    return 0;
  }
  
  this->head = this->head->next;
  
  tempValue = temp->adj_vtx;
  
  delete temp;
  temp = nullptr;
  
  return tempValue;
 }

Graph::Graph(int v){
  this->v = v;
   adj = new edge*[v];
  
  for(int i = 0; i<v; i++)
  {
    adj[i] = nullptr;
  }
}
void Graph::addEdge(int v,int w){ 
 edge* new_edge = new edge;
  new_edge->adj_vtx = w;
  new_edge->next = adj[v];
  adj[v] = new_edge;

}
void Graph::DFS(int v){
  bool *visited = new bool[v];
  for(int i = 0; i< v; i++ ){
    visited[i] = false;
  }
  DFSUtil(v,visited);
}
void Graph::DFSUtil(int v, bool visited[]){
  visited[v] = true;
  cout << v << " ";
  for(edge* e = adj[v];e != nullptr;e = e->next)
  if(!visited[e->adj_vtx]) 
    DFSUtil(e->adj_vtx,visited);
  
}
void Graph::BFS(int s){
  bool *visited = new bool[v];
  for(int i = 0; i<v; i++)
    visited[i] = false;  //setting all vertex to false
  Queue q;
  visited[v] = true;
  q.enqueue(s);
  
  while(q.size() != 0) // checking if queue is empty
  {
    s = q.dequeue();

    cout << s << " " << endl;

    for(edge* e = adj[s]; e!= nullptr; e = e->next){
      if(!visited[e->adj_vtx]){
        visited[e->adj_vtx] = true;
        q.enqueue(e->adj_vtx);
      }
    }
    
  }
}
