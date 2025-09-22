#include <iostream>
#include <string>
#include <vector>

// struct de actor
struct Actor
{
    std::string nombre;
    std::string nacionalidad;
};

// struct de pelicula
struct Pelicula
{
    std::string nombre_pelicula;
    int anio;
    bool subtitulada;
};

// vector para las peliculas
std::vector<Pelicula> peliculas_actor;

// declaramos las funciones
Actor SolicitarInformacion();
void Imprimir(Actor a);
bool verificarNominacion(Pelicula p);
void BuscarPelicula();
