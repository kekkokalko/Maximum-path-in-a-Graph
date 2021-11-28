#include "Servizio.hpp"
#include <iostream>

using namespace std;
vector<Edge>edges;   //vettore globale di archi
char HeaderFile[]="Intestazione.txt";        //nome del file di intestazione

int main()
{
    Servizio servizio;
    int i;
    int node_loaded=0;          //numero di nodi del grafo esaminato
    string node_file;           //nome del file contenente le informazioni del grafo
    servizio.visualizza_header(HeaderFile);
    while(node_loaded==0)
        {
            node_file=servizio.get_Nodefile();
            cout<<endl;
            node_loaded = servizio.carica_n_nodi(node_file);
        }
    cout<<endl;
    i=servizio.caricanodi(node_file);
    cout<<"---------------------------IMPLEMNETAZIONE-----------------------------"<<endl;
    for(i=0;i<node_loaded;i++)
    {
        Graph g(edges,node_loaded);                 //costruzione del grafo
        servizio.risultato(i,node_loaded,g);        //implementazione della BFS e LongestPath
        cout<<endl;
    }
	return 0;
}
