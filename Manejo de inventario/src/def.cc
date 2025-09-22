// Llamamos las librerias y funciones declaradas para definirlas
#include "header.h"

void AgregarProductos()
{
    std::system("cls"); // limpiamos la consola
    Producto p;         // llamamos el struct
    int n_producto;
    std::ofstream archivo("Inventario.txt", std::ios::app); // Abrimos los archivos

    std::cout << "Cuantos productos desea agregar?" << std::endl; // pedimos la cantidad de productos a agregar
    std::cin >> n_producto;
    // Ciclo for para guardar los datos
    for (int i = 0; i < n_producto; i++)
    {
        std::cout << "----------------------------------------------" << std::endl;
        std::cout << "Cual es el nombre de el producto?" << std::endl;
        std::cin >> p.nombre;
        std::cout << "----------------------------------------------" << std::endl;
        std::cout << "Cual es la cantidad del producto que entra?" << std::endl;
        std::cout << "----------------------------------------------" << std::endl;
        std::cin >> p.cantidad_producto;
        std::cout << "Cual es el precio de el producto?" << std::endl;
        std::cout << "----------------------------------------------" << std::endl;
        std::cin >> p.precio_producto;
        std::system("cls");

        inventario.push_back(p);

        // Escribe cada producto en el archivo
        if (archivo.is_open())
        {
            archivo << p.nombre << " " << p.cantidad_producto << " " << p.precio_producto << std::endl;
        }
    }
    if (archivo.is_open())
    {
        archivo.close();
    }
}

void CargarInventario()
// cargamos el inventario siempre
{
    inventario.clear();                      // limpiamos el vector
    std::ifstream archivo("Inventario.txt"); // creamos el archivo
    Producto p;                              // llamamos al struct
    if (archivo.is_open())
    {
        // Llenamos el vector con los archivos existentes en el txt
        while (archivo >> p.nombre >> p.cantidad_producto >> p.precio_producto)
        {
            inventario.push_back(p); // hacemos el
        }
        archivo.close(); // cerramos el archivo
    }
}

void MostrarProductos()
{
    system("cls"); // limpiamos la consola
    std::cout << "------Listado de productos------" << std::endl;
    // Ciclo For para mostrar el inventario
    for (const auto &p : inventario)
    {
        std::cout << "---------------------------" << std::endl;
        std::cout << "Nombre: " << p.nombre << std::endl;
        std::cout << "Cantidad en stock: " << p.cantidad_producto << std::endl;
        std::cout << "Precio por unidad: $" << p.precio_producto << std::endl;
        std::cout << "---------------------------" << std::endl;
    }
}

void EliminarProductos()
{
    system("cls"); // Limpiamos la consola
    // Variables de la funcion
    std::string nombre_eliminar;
    char confirmacion;
    // Mostramos los productos existentes
    MostrarProductos();
    // Preguntamos el producto que quiere eliminar
    std::cout << "Que producto quieres eliminar?" << std::endl;
    std::cin >> nombre_eliminar;

    /* recorremos el vector en busca del producto
    Primero determinamos la variable it automaticamente, luego usamos find_it que viene
    de la libreria de algorithm y busca el primer elemento el el rango que determinamos
    que respectivamente es "inventario.begin()", "inventario.end();" luego usamos una lambda
    o una funcion anonima, donde [&] significa la lambda puede usar variables externas en referencias
    y luego (const Producto &p) que refiere a la funcion Producto y todos sus elementos,
    cerramos con un return que retornara si el nombre del producto coincide con el nombre que
    el usuario ingreso */

    auto it = std::find_if(
        inventario.begin(), inventario.end(), [&](const Producto &p)
        { return p.nombre == nombre_eliminar; });

    // Verificacion de la existencia de el producto
    if (it != inventario.end()) // verificamos que sea diferente de el final de la funcion
    {
        // Mostramos el nombre del producto a eliminar con it-> nombre
        std::cout << "Producto encontrado: " << it->nombre << ". ¿Seguro que desea eliminarlo? (s/n): ";
        std::cin >> confirmacion; // guadamos la respuesta

        if (confirmacion == 's' || confirmacion == 'S') // verificamos la respuesta
        {
            inventario.erase(it); // Eliminamos del vector

            // Sobrescribe el archivo con el vector actualizado
            std::ofstream archivo("Inventario.txt", std::ios::trunc);
            for (const auto &p : inventario)
            {
                archivo << p.nombre << " " << p.cantidad_producto << " " << p.precio_producto << std::endl;
            }
            archivo.close();

            std::cout << "Producto eliminado correctamente." << std::endl;
            system("cls");
        }
        else
        {
            std::cout << "Eliminación cancelada." << std::endl;
            system("cls");
        }
    }
    else
    {
        std::cout << "Producto no encontrado." << std::endl;
        system("cls");
    }
}

void BuscarProductos()
{
    system("cls");
    std::string nombre_busca;
    std::cout << "Que producto deseas buscar?" << std::endl;
    std::cin >> nombre_busca;

    // Recorremos el vector en busqueda de el producto0
    auto it = std::find_if(
        inventario.begin(), inventario.end(), [&](const Producto &p)
        { return p.nombre == nombre_busca; });

    // Si este existe lo mostramos al usuario
    if (it != inventario.end())
    {
        // Mostramos el nombre del producto a eliminar con it-> nombre
        std::cout << "---------------------------" << std::endl;
        std::cout << "Producto encontrado: " << "\n"
                  << it->nombre << "\n"
                  << it->cantidad_producto << "\n"
                  << "$" << it->precio_producto << std::endl;
        std::cout << "---------------------------" << std::endl;
    }
    else
    { // si no existe le decimos que este no a sido encontrado
        std::cout << "Producto no encontrado" << std::endl;
    }
}

void EditarProductos()
{
    system ("cls");
    std::string nombre_editar;
    char confirmacion;
    std::cout << "Que producto deseas editar?" << std::endl;
    std::cin >> nombre_editar;
    // Recorremos el vector en busqueda de el producto
    auto it = std::find_if(
        inventario.begin(), inventario.end(), [&](const Producto &p)
        { return p.nombre == nombre_editar; });
    // Si este existe lo mostramos al usuario
    if (it != inventario.end())
    {
        std::cout << "Producto encontrado: " << it->nombre << ". ¿Seguro que desea editarlo? (s/n): ";
        std::cin >> confirmacion; // guadamos la respuesta

        if (confirmacion == 's' || confirmacion == 'S') // verificamos la respuesta
        {
            std::cout << "Nuevo nombre: ";
            std::cin >> it->nombre;
            std::cout << "Nueva cantidad: ";
            std::cin >> it->cantidad_producto;
            std::cout << "Nuevo precio: ";
            std::cin >> it->precio_producto;

            // Sobrescribe el archivo con el vector actualizado
            std::ofstream archivo("Inventario.txt", std::ios::trunc);
            for (const auto &p : inventario)
            {
                archivo << p.nombre << " " << p.cantidad_producto << " " << p.precio_producto << std::endl;
            }
            archivo.close();

            std::cout << "Producto editado correctamente." << std::endl;
            system("cls");
        }
        else
        {
            std::cout << "Edición cancelada." << std::endl;
            system("cls");
        }
    }
    else
    { // si no existe le decimos que este no a sido encontrado
        std::cout << "Producto no encontrado" << std::endl;
    }
}