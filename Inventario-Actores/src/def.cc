#include "header.h"

// Solicitar información del actor
Actor SolicitarInformacion()
{
    Actor a;
    std::cout << "Ingrese el nombre del actor: ";
    std::getline(std::cin, a.nombre);
    std::cout << "Ingrese la nacionalidad del actor: ";
    std::getline(std::cin, a.nacionalidad);

    for (int i = 0; i < 3; i++)
    {
        Pelicula p;
        std::cout << "\nIngrese el nombre de la pelicula " << i + 1 << ": ";
        std::getline(std::cin, p.nombre_pelicula);
        std::cout << "Ingrese el anio de estreno de la pelicula " << i + 1 << ": ";
        std::cin >> p.anio;
        std::cout << "La pelicula " << i + 1 << " esta subtitulada? (1=si / 0=no): ";
        std::cin >> p.subtitulada;
        std::cin.ignore();

        peliculas_actor.push_back(p);
    }
    return a;
}

// Imprimir datos del actor y sus películas
void Imprimir(Actor a)
{
    std::cout << "\n--- Datos del actor ---" << std::endl;
    std::cout << "Nombre: " << a.nombre << std::endl;
    std::cout << "Nacionalidad: " << a.nacionalidad << std::endl;

    std::cout << "\n--- Peliculas del actor ---" << std::endl;
    for (int i = 0; i < peliculas_actor.size(); i++)
    {
        Pelicula p = peliculas_actor[i];
        std::cout << "Nombre: " << p.nombre_pelicula << std::endl;
        std::cout << "Anio de estreno: " << p.anio << std::endl;
        std::cout << "Subtitulada: " << (p.subtitulada ? "Si" : "No") << std::endl;
        std::cout << "------------------------" << std::endl;
    }
}

// Verificar si una película aplica para nominación
bool verificarNominacion(Pelicula p)
{
    int anio_actual = 2025;
    if ((anio_actual - p.anio) > 10 && p.subtitulada)
    {
        std::cout << "La pelicula " << p.nombre_pelicula << " aplica a la nominacion de premios." << std::endl;
        return true;
    }
    else
    {
        std::cout << "La pelicula " << p.nombre_pelicula << " no aplica a la nominacion de premios." << std::endl;
        return false;
    }
}

// Buscar una película en el vector
void BuscarPelicula()
{
    std::string nombre_buscar;
    std::cout << "Ingrese el nombre de la pelicula a buscar: " << std::endl;
    std::getline(std::cin, nombre_buscar);

    bool encontrada = false;
    for (int i = 0; i < peliculas_actor.size(); i++)
    {
        Pelicula p = peliculas_actor[i];
        if (p.nombre_pelicula == nombre_buscar)
        {
            std::cout << "\n--- Pelicula encontrada ---" << std::endl;
            std::cout << "Nombre: " << p.nombre_pelicula << std::endl;
            std::cout << "Anio de estreno: " << p.anio << std::endl;
            std::cout << "Subtitulada: " << (p.subtitulada ? "Si" : "No") << std::endl;
            encontrada = true;
            break;
        }
    }

    if (!encontrada)
    {
        std::cout << "Pelicula no encontrada." << std::endl;
    }
}