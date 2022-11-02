/* Programa desarrollado por Alejandro Uscategui-Torres */
// Si tengo un punto cualquiera, entonces

#include <bits/stdc++.h>

using namespace std;

void imprimirMatriz(int chess[][8])
{
    for (int i = 0; i < 8; i++)
    {
        for (int j = 0; j < 8; j++)
        {
            cout << chess[i][j] << " | ";
        }
        cout << "" << endl;
    }
}

bool seAtacan(int chess[][8], int fila, int columna)
{
    unsigned int b;

    chess[fila][columna] = 1;
    imprimirMatriz(chess);

    // Se atacan en vertical
    for (int i = 0; i < 8; i++)
    {
        if (chess[i][columna] == 1)
        {
            if (i != fila)
            {
                chess[i][columna] == 0;
                chess[fila][columna] = 0;
                cout << "Se atacan verticalmente la reina en: (" << fila << "," << columna << ")"
                     << "Y la reina ubicada en: (" << i << "," << columna << ")\n";
                return true;
            }
        }
    }

    // Se atacan horizontal
    for (int i = 0; i < 8; i++)
    {
        if (chess[fila][i] == 1)
        {
            if (i != columna)
            {
                chess[fila][columna] = 0;
                cout << "Se atacan horizontalmente la reina en: (" << fila << "," << columna << ")"
                     << "Y la reina ubicada en: (" << fila << "," << i << ")\n";
                return true;
            }
        }
    }

    // Se atacan diagonales
    // Reviso la diagonal hacia arriba: Con m = 1, la fórmula es: b = y - x
    // Si y > x, b me indica el punto P(0,b)
    // Si x > y, b me indica el punto P(b,0), así:
    // con la notación del problema columna = x & fila = y

    if (fila > columna)
    {
        // Evalúo la diagonal hacia abajo
        for (int i = fila - columna, j = 0; i < 8; i++, j++)
        {
            if (chess[i][j] == 1)
            {
                if (i != fila && j != columna)
                {
                    chess[fila][columna] = 0;
                    cout << "Se atacan en diagonal hacia abajo la reina en: (" << fila << "," << columna << ")"
                         << "Y la reina ubicada en: (" << i << "," << j << ")\n";
                    return true;
                }
            }
        }

        // Evalúo diagonal hacia arriba
        for (int i = fila + columna, j = 0; i >= 0; i--, j++)
        {
            if (chess[i][j] == 1)
            {
                if (i != fila && j != columna)
                {
                    chess[fila][columna] = 0;
                    cout << "Se atacan en diagonal hacia abajo la reina en: (" << fila << "," << columna << ")"
                         << "Y la reina ubicada en: (" << i << "," << j << ")\n";
                    return true;
                }
            }
        }
    }

    if (fila == columna)
    {
        for (int i = 0, j = 0; j < 8; i++, j++)
        {
            if (chess[i][j] == 1)
            {
                if (i != fila && j != columna)
                {
                    chess[fila][columna] = 0;
                    cout << "Se atacan en diagonal hacia abajo la reina en: (" << fila << "," << columna << ")"
                         << "Y la reina ubicada en: (" << i << "," << j << ")\n";
                    return true;
                }
            }
        }

        // Diagonal hacia arriba

        for (int i = 7, j = 0; i >= 0; i--, j++)
        {
            if (chess[i][j] == 1)
            {
                if (i != fila && j != columna)
                {
                    chess[fila][columna] = 0;
                    cout << "Se atacan en diagonal hacia arriba la reina en: (" << fila << "," << columna << ")"
                         << "Y la reina ubicada en: (" << i << "," << j << ")\n";
                    return true;
                }
            }
        }
    }

    if (fila < columna)
    {
        for (int i = 0, j = columna - fila; j < 8; i++, j++)
        {
            if (chess[i][j] == 1)
            {
                if (i != fila && j != columna)
                {
                    chess[fila][columna] = 0;
                    cout << "Se atacan en diagonal hacia abajo la reina en: (" << fila << "," << columna << ")"
                         << "Y la reina ubicada en: (" << i << "," << j << ")\n";
                    return true;
                }
            }
        }

        // Evalúo en diagonal hacia abajo
        for (int i = columna + fila, j = 0; i >= 0; i--, j++)
        {
            if (chess[i][j] == 1)
            {
                if (i != fila && j != columna)
                {
                    chess[fila][columna] = 0;
                    cout << "Se atacan en diagonal hacia arriba la reina en: (" << fila << "," << columna << ")"
                         << "Y la reina ubicada en: (" << i << "," << j << ")\n";
                    return true;
                }
            }
        }
    }

    cout << "No se atacan\n";
    return false;
}

void cambiarTablero(int chess[][8], int columna)
{

    // caso último
    if (columna == 8)
    {
        return;
    }

    // Validación
    for (int i = 0; i < 8; i++)
    {
        /* cout << "\n\nFila: " << i << "\tColumna: " << columna << endl; */
        if (seAtacan(chess, i, columna) == false)
        {
            chess[i][columna] = 1;
            cambiarTablero(chess, columna + 1);
        }
        
    }
}

int main(int argc, char *argv[])
{
    int chess[8][8] = {{0}};

    imprimirMatriz(chess);
    cout << "\n\n----------------------------\n";
    cambiarTablero(chess, 0);
    imprimirMatriz(chess);
}
