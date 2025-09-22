// Llamamos las definiciones de las funciones
#include "./src/def.cc"

int main()
{
    // variable para manejar el do while
    int opcion;

    do
    {
        std::cout << "---------------------------------------------------------" << std::endl;
        std::cout << "Bienvenido a nuestra distribuidora, que deseas realizar?" << std::endl;
        std::cout << "---------------------------------------------------------" << std::endl;
        std::cout << "1. Agregar un producto" << std::endl;
        std::cout << "2. Mostrar productos existentes" << std::endl;
        std::cout << "3. Buscar producto" << std::endl;
        std::cout << "4. Eliminar producto" << std::endl;
        std::cout << "5. Salir de le programa" << std::endl;
        std::cout << "Que accion deseas realizar?" << std::endl;
        std::cin >> opcion;

        if (opcion == 1)
        {
            AgregarProductos();
        }
        else if (opcion == 2)
        {
            CargarInventario();
            MostrarProductos();
        }
        else if (opcion == 3)
        {
            CargarInventario();
            BuscarProductos();
        }
        else if (opcion == 4)
        {
            CargarInventario();
            EliminarProductos();
        }

    } while (opcion != 5);

    std::cout << "---------------------------------------------------------" << std::endl;
    std::cout << "Cerrando el programa......" << std::endl;

    return 0;
}