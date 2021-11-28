#include "Servizio.hpp"
#include <iostream>
#include <sstream>
#include <fstream>
#include <string>

extern vector<Edge> edges;

//procedura che acquisisce il nome del file contenente i valori grafo
string Servizio::get_Nodefile()
{
    string s;
    cout<<"Digitare il nome del file di input ";
    cin>>s;
    s="./Data/"+s+".txt";
    return s;
}

//procedura che acquisisce il numero dei nodi del grafo da analizzare
int Servizio::carica_n_nodi(string node_file)
{

    string line;
    int n_nodi;
    ifstream readFile(node_file);
    if(readFile.fail())
        {
            cout<<"File non trovato!"<<endl;
            return 0;
        }
    getline(readFile,line);
    stringstream stream(line);
    stream>>n_nodi;
    cout<<"Numero dei nodi del grafo da analizzare= "<<n_nodi;
    cout<<endl;
    readFile.close();
    return n_nodi;
}

//procedura che acquisisce i valori dei nodi del grafo (nodo sorgente, nodo destinazione, peso dell'arco)
int Servizio::caricanodi(string node_file)
{
    string line;
    int x,y,z;
    int n_nodi;
    ifstream readFile(node_file);
    if (readFile.fail())
        {
            cout<<"File non trovato!"<<endl;
            return 0;
        }
    getline(readFile,line);             //salto della riga vuota del file
    stringstream stream(line);
    stream>>n_nodi;
    cout<<"Grafo avente:"<<endl;
    cout<<line<<" (numero nodi e numero archi)"<<endl;
    while(!readFile.eof())
        {
            getline(readFile,line);
            stringstream stream(line);
            stream>>x;
            stream>>y;
            stream>>z;
            edges.push_back({x,y,z});
        }
    cout<<endl;
    readFile.close();
    return n_nodi;
}

//procedura che definisce i cammini massimi per poi visualizzare a schermo la qualità, e quindi il peso totale, del cammino
void Servizio::risultato(int s, int N, Graph g)
{
    g.BFS(g,s);
    cout<<"Qualita' del collegamento dal nodo "<< s << ": \n";
    g.longestPath(s,N);

}

//procedura per visualizzare l'intestazione dell'output
int Servizio::visualizza_header(string FileName)
{
    string line;
    ifstream HeaderFile;
    HeaderFile.open("./Data/"+FileName);
    if(!HeaderFile)
        {
            cout<< "Errore di apertura del file: "<< "FileName";
            return 0;   // stop
        }
    while(getline(HeaderFile,line))
        cout<<line << endl;
    return 1;
}
