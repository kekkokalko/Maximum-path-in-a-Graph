#include "Graph.hpp"
#include <iostream>
#include <queue>
#include <vector>
#include <set>
#include <climits>
#include <iterator>
int quality[100];       //array globale che definisce la qualità dei vari cammini massimi

Graph::Graph(vector<Edge> edges,int N)
{
    adjList.resize(N);      //dato il numero totale di nodi si definisce la lunghezza della lista di adiacenze di N elementi totali
    for(auto &edge: edges)  //tramite questo ciclo si ggiungono i vari archi al DAG
    {
        int src=edge.get_Src();
        int dest=edge.get_Dest();
        int weight=edge.get_Peso();
        adjList[src].push_back(edge);  //aggiungo l'arco alla lista di adiacenze
    }
    for(int i=0;i<N;i++)
        quality[i]=-INT_MIN;            //inizializzazione dell'array che contiene le qualità dei vari cammini massimi
}

void Graph::BFS(Graph g,int s)
{
	Node k;
	queue<Node> q;          //coda che contiene i nodi del grafo
	set<int> vertici;      //contenitore set che mantiene i nodi già calcolati del cammino, inizialmente vuoto
	k.set_Data(s);
	k.set_Costo(0);         //qualità del cammino dalla sorgente a sè stesso
	q.push(k);
	while(!q.empty())
	{
		Node node=q.front();
		q.pop();
		int v=node.get_Data();
		int cost=node.get_Costo();
		vertici=node.get_SNode();      //'vertici' conterrà i nodi che si trovano nel cammino calcolato al passo precedente
		for(Edge edge : g.adjList[v])   //visita della lista di adiacenza del nodo estratto dalla coda
		{
			if (vertici.find(edge.get_Dest())==vertici.end())    //se il nodo destinazione dell'arco esaminato non è stato già inserito in 'vertici'
			{                                                    //dovrà essere inserito nel contenitore s1 che indica la lista di nodi facente parte del cammino massimo
				set<int>s1=vertici;         //aggiungo il nodo al nuovo cammino
				s1.insert(edge.get_Dest());
				if(quality[edge.get_Dest()]<edge.get_Peso()+cost)     //verifico la qualità del cammino insieme al nuovo arco
                    quality[edge.get_Dest()]=edge.get_Peso()+cost;    //aggiorno la qualità del cammino esaminato
				//inserisco nella coda ogni vertice che era destinazione dell'arco esaminato
				k.set_Data(edge.get_Dest());
				k.set_Costo(cost+edge.get_Peso());
				k.set_SetNode(s1);
				q.push(k);
			}
		}
	}
}

//definito l'array quality che indica la qualità dei cammini si stampa a video il suo contenuto
void Graph::longestPath(int source,int N){

    int i;
    for(i=0;i<N;i++)
    {
        if(i==source)
            cout<<"Nodo "<<i<<"= "<<0<<endl;
        else
            {
                if(quality[i]==INT_MIN)
                    cout<<"Nodo "<<i<<"= "<<"-INFINITO"<<endl;
                else
                    cout<<"Nodo "<<i<<"= "<<quality[i]<<endl;
            }
    }
}
