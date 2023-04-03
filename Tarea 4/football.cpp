/* En esta solución tenemos una complejidad de O(n*m) donde n es la cantidad de equipos
y m es la cantidad de partidos jugados, esto se repite la cantidad de veces necesarias, pero
la complejidad de la solución es es la dicha anteriormente. Además, si se toma en cuenta la comple-
jidad del sort habría que añadirle a esa complejidad Una de nlogn por lo que en total la
complejidad del ejercicio es O(n*m + nlogn) 
*/

#include <iostream>
#include <stdio.h>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

string modificarNombre(string cad)
{
    string retorno;
    int n;
    for (int i = 0; i < cad.length(); i++)
    {
        n = cad[i];
        if (n >= 97 and n <= 122)
        {
            retorno += cad[i] - 32;
        }
        else
        {
            retorno += cad[i];
        }
    }
    return retorno;
}

class Estadisticas
{
public:
    string nombre;
    int puntos;
    int goles;
    int golesEnContra;
    int diferenciaGol;
    int partidos;
    double porcentaje;

    Estadisticas(string nombre)
    {
        this->nombre = nombre;
        puntos = 0;
        goles = 0;
        golesEnContra = 0;
        diferenciaGol = 0;
        partidos = 0;
        porcentaje = 0;
    }

    bool operator <(const Estadisticas &equipoComparar)
    {
        bool ans = false;
        if (puntos != equipoComparar.puntos)
        {
            ans = puntos > equipoComparar.puntos;
        }
        else if (diferenciaGol != equipoComparar.diferenciaGol)
        {
            ans = diferenciaGol > equipoComparar.diferenciaGol;
        }
        else if (goles != equipoComparar.goles)
        {
            ans = goles > equipoComparar.goles;
        }
        else
        {
            string nombreMayus1, nombreMayus2;
            nombreMayus1 = modificarNombre(nombre);
            nombreMayus2 = modificarNombre(equipoComparar.nombre);
            ans = nombreMayus1 < nombreMayus2;
        }

        return ans;
    }
};

int main()
{
    int partidos, equipos;
    cin >> equipos >> partidos;
    string nombreEquipo;
    vector<Estadisticas> vecEstadisticas;
    while (equipos != 0 and partidos != 0)
    {
        for (int i = 0; i < equipos; i++)
        {
            cin >> nombreEquipo;
            Estadisticas equipo(nombreEquipo);
            vecEstadisticas.push_back(equipo);
        }
        string equipo1, equipo2, rayita;
        int marcador1, marcador2;
        for (int i = 0; i < partidos; i++)
        {
            cin >> equipo1 >> marcador1 >> rayita >> marcador2 >> equipo2;
            for (vector<Estadisticas>::iterator it = vecEstadisticas.begin(); it != vecEstadisticas.end(); it++)
            {
                if ((*it).nombre == equipo1)
                {
                    (*it).goles += marcador1;
                    (*it).golesEnContra += marcador2;
                    if (marcador1 > marcador2)
                    {
                        (*it).puntos += 3;
                    }
                    else if (marcador1 == marcador2)
                    {
                        (*it).puntos += 1;
                    }
                    (*it).diferenciaGol = (*it).goles - (*it).golesEnContra;
                    (*it).partidos++;
                }
                if ((*it).nombre == equipo2)
                {
                    (*it).goles += marcador2;
                    (*it).golesEnContra += marcador1;
                    if (marcador2 > marcador1)
                    {
                        (*it).puntos += 3;
                    }
                    else if (marcador1 == marcador2)
                    {
                        (*it).puntos += 1;
                    }
                    (*it).diferenciaGol = (*it).goles - (*it).golesEnContra;
                    (*it).partidos++;
                }
            }
        }
        sort(vecEstadisticas.begin(), vecEstadisticas.end());
        int contador = 1;
        for (vector<Estadisticas>::iterator it = vecEstadisticas.begin(); it != vecEstadisticas.end(); it++)
        {
            const char *nombreEq = (*it).nombre.c_str();
            if (it == vecEstadisticas.begin() or ((*it).goles != (*(it - 1)).goles or (*it).puntos != (*(it - 1)).puntos or (*it).diferenciaGol != (*(it - 1)).diferenciaGol))
            {
                if ((*it).partidos == 0)
                {
                    char na[4] = "N/A";
                    printf("%2d.%16s%4d%4d%4d%4d%4d%7s\n", contador, nombreEq, (*it).puntos, (*it).partidos, (*it).goles, (*it).golesEnContra, (*it).diferenciaGol, na);
                }
                else
                {
                    (*it).porcentaje = ((*it).puntos * 100.0) / ((*it).partidos * 3);
                    printf("%2d.%16s%4d%4d%4d%4d%4d%7.2f\n", contador, nombreEq, (*it).puntos, (*it).partidos, (*it).goles, (*it).golesEnContra, (*it).diferenciaGol, (*it).porcentaje);
                }
                contador++;
            }
            else if ((*it).goles == (*(it - 1)).goles and (*it).puntos == (*(it - 1)).puntos and (*it).diferenciaGol == (*(it - 1)).diferenciaGol)
            {
                if ((*it).partidos == 0)
                {
                    char na[4] = "N/A";
                    printf("%19s%4d%4d%4d%4d%4d%7s\n", nombreEq, (*it).puntos, (*it).partidos, (*it).goles, (*it).golesEnContra, (*it).diferenciaGol, na);
                }
                else
                {
                    (*it).porcentaje = ((*it).puntos * 100.0) / ((*it).partidos * 3);
                    printf("%19s%4d%4d%4d%4d%4d%7.2f\n", nombreEq, (*it).puntos, (*it).partidos, (*it).goles, (*it).golesEnContra, (*it).diferenciaGol, (*it).porcentaje);
                }
                contador++;
            }
        }
        printf("\n");
        vecEstadisticas.clear();
        cin >> equipos >> partidos;
    }
    return 0;
}