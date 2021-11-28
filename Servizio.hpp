#include "Graph.hpp"
#include <string>

using namespace std;

//classe Servizio che implementa l'esercizio
class Servizio
{
    public:
        Servizio(){;}
        string get_Nodefile();
        int carica_n_nodi(string node_file);
        int caricanodi(string node_file);
        void risultato(int s,int N,Graph g);
        int visualizza_header(string FileName);
};


