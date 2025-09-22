#include "./src/def.cc"
int main()
{
    int opcion;
    Actor actor; // Variable para almacenar un actor

    do
    {
        std::cout << "\n------ Bienvenido a nuestro almacen de peliculas ------" << std::endl;
        std::cout << "1. Agregar un actor y sus peliculas" << std::endl;
        std::cout << "2. Mostrar actores y sus peliculas" << std::endl;
        std::cout << "3. Buscar pelicula" << std::endl;
        std::cout << "4. Verificar nominacion de premio" << std::endl;
        std::cout << "5. Salir del programa" << std::endl;
        std::cout << "Que desea realizar? ";
        std::cin >> opcion;
        std::cin.ignore();

        if (opcion == 1)
        {
            actor = SolicitarInformacion();
        }
        else if (opcion == 2)
        {
            Imprimir(actor);
        }
        else if (opcion == 3)
        {
            BuscarPelicula();
        }
        else if (opcion == 4)
        {
            for (int i = 0; i < peliculas_actor.size(); i++)
            {
                verificarNominacion(peliculas_actor[i]);
            }
        }
    } while (opcion != 5);

    std::cout << "Cerrando programa..." << std::endl;
    return 0;
}
