#pragma once
#include <set>
#include <vector>
using namespace std;

//classe che definisce un arco generico
class Edge
{
    private:
        int sorg;
        int dest;
        int peso;
    public:
        Edge(int s,int d,int p){ sorg=s; dest=d; peso=p;}        //costruttore con parametri
        int get_Src(){ return sorg;}
        int get_Dest(){ return dest;}
        int get_Peso(){ return peso;}
        void set_Sorg(int s){ this->sorg=s;}
        void set_Dest(int d){ this->dest=d;}
        void set_Peso(int p){ this->peso=p;}
};

//classe che definisce un nodo generico
class Node
{
    private:
        int data;           //campo data
        int costo;         //qualità del cammino corrente
        set<int> s;         //serie di nodi del cammino corrente
    public:
        Node(){;}           //costruttore di default
        int get_Data(){ return data;}
        int get_Costo(){ return costo;}
        set<int> get_SNode(){ return s;}
        void set_Data(int x){ this->data=x;}
        void set_Costo(int y){ this->costo=y;}
        void set_SetNode(set<int>s1){ this->s=s1;}

};

// classe che definisce un grafo
class Graph
{
	private:
        vector<vector<Edge>> adjList;           //lista di adiacenze rappresentato mediante vector di vector
    public:
        Graph(vector<Edge>edges, int N);        //costruttore con parametri: lista e quantità totale di nodi
        void BFS(Graph g,int src);              //BFS modificata per calcolare i cammini massimi partendo da una sorgente
        void longestPath(int source,int N);     //stampa dei cammini massimi per ogni nodo sorgente del grafo
};
