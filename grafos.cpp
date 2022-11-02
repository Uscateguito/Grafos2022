// Impresión en traversal
#include <bits/stdc++.h>
using namespace std;

// Clase grafo que representa un grafo dirigido
// Usando una lista para representar los vértices adyacentes
class Grafo
{
public:
    // Mapa que indica si el vértice ya fue visitado
    map<char, bool> visitado;

    // Mapa que representa los elementos adjuntos al vértice con peso
    map<char, map<char, int>> adyacente;

    // Función para agregar un arco al grafo
    void agregarArco(char v, char w, int peso);

    // DFS traversal empezando desde v
    void depthFirstSearch(char v);

    // Revisar Caminos
    bool hayCamino(char v, char w);

    // Costo Camino
    int costoCamino(char v, char w);
};

void Grafo::agregarArco(char v, char w, int peso)
{
    adyacente[v].insert({w, peso}); // Agrega w, a la lista de vértices adyacentes a V.
}

void Grafo::depthFirstSearch(char v)
{
    // Marca al nodo actual como visitado y lo imprime
    // Como es un mapa, simplemente al ponerle un elemento, lo agrega
    visitado[v] = true;
    cout << "Vertice actual: " << v << " ";

    /*
     * Hace un llamado recurrente a todos los vértices
     * adyacentes al vértice actual
     *
     */
    map<char, int>::iterator i;
    for (i = adyacente[v].begin(); i != adyacente[v].end(); i++)
        /* cout << i->first << " " << i->second << endl; */
        if (!visitado[i->first])
            depthFirstSearch(i->first);
}

bool Grafo::hayCamino(char v, char w)
{
    visitado[v] = true;
    cout << "Vertice actual: " << v << " ";
    
    map<char, int>::iterator i;
    for (i = adyacente[v].begin(); i != adyacente[v].end(); i++)
        /* cout << i->first << " " << i->second << endl; */
        if (!visitado[i->first])
            depthFirstSearch(i->first);
    
    return true;
}

// Driver's code
int main()
{
    // Create a Grafo given in the above diagram
    Grafo g;
    g.agregarArco('0', '1', 1);
    g.agregarArco('0', '2', 1);
    g.agregarArco('1', '2', 1);
    g.agregarArco('2', '0', 1);
    g.agregarArco('2', '3', 1);
    g.agregarArco('3', '3', 1);

    cout << "Depth Traversal \n";

    // Function call
    g.depthFirstSearch('2');

    return 0;
}

// improved by Vishnudev C