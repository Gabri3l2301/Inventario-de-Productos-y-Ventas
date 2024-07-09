#include <iostream>
#include <windows.h>
using namespace std;

const int MAX_PRODUCTOS = 100;
const int MAX_NOMBRE = 50;

struct Producto {
    char nombre[MAX_NOMBRE];
    float precio;
};

struct Venta {
    int idVenta;
    char producto[MAX_NOMBRE];
    int cantidad;
    float precioTotal;
};

void registrarProducto(Producto productos[], int &numProductos) {
    if (numProductos < MAX_PRODUCTOS) {
        Producto nuevo;
        cout << "Ingrese nombre del producto: ";
        cin.ignore();
        cin.getline(nuevo.nombre, MAX_NOMBRE);
        cout << "Ingrese precio del producto: ";
        cin >> nuevo.precio;
        productos[numProductos] = nuevo;
        numProductos++;
        cout << "Producto registrado exitosamente.\n";
    } else {
        cout << "La lista de productos está llena. No se pueden agregar más productos.\n";
    }
}

void listarProductos(const Producto productos[], int numProductos) {
    for (int i = 0; i < numProductos; i++) {
        cout << "Nombre: " << productos[i].nombre << ", Precio: " << productos[i].precio << '\n';
    }
}

int main() {
    SetConsoleOutputCP(CP_UTF8);
    Producto productos[MAX_PRODUCTOS];
    Venta ventas[MAX_PRODUCTOS];
    int numProductos = 0;
    int contadorVentas = 0;
    char opcion;

    do {
        cout << "a) Registrar producto\nb) Listar productos\nc) Buscar producto\nd) Actualizar producto\ne) Eliminar producto\nf) Registrar venta\ng) Listar ventas\nh) Calcular total de ventas\ns) Salir\n";
        cout << "Seleccione una opción: ";
        cin >> opcion;

        switch (opcion) {
            case 'a':
                registrarProducto(productos, numProductos);
                break;
			case 'b':
                listarProductos(productos, numProductos);
                break;
            case 'c':
                buscarProducto(productos, numProductos);
                break;
            case 'd':
                actualizarProducto(productos, numProductos);
                break;
            case 'e':
                eliminarProducto(productos, numProductos);
                break;
            case 'f':
                registrarVenta(ventas, productos, contadorVentas, numProductos);
                break;
            case 'g':
                listarVentas(ventas, contadorVentas);
                break;
            case 'h':
                calcularTotalVentas(ventas, contadorVentas);
                break;
            case 's':
                cout << "Saliendo del programa...\n";
                break;
            default:
                cout << "Opción no válida.\n";
        }
    } while (opcion != 's');

    return 0;
}