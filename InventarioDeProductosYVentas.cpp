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

void buscarProducto(const Producto productos[], int numProductos) {
    char nombre[MAX_NOMBRE];
    cout << "Ingrese el nombre del producto a buscar: ";
    cin.ignore();
    cin.getline(nombre, MAX_NOMBRE);
    bool encontrado = false;
    for (int i = 0; i < numProductos; i++) {
        if (strcmp(productos[i].nombre, nombre) == 0) {
            cout << "Producto encontrado: Nombre: " << productos[i].nombre << ", Precio: " << productos[i].precio << '\n';
            encontrado = true;
            break;
        }
    }
    if (!encontrado) {
        cout << "Producto no encontrado.\n";
    }
}

void actualizarProducto(Producto productos[], int numProductos) {
    char nombre[MAX_NOMBRE];
    cout << "Ingrese el nombre del producto a actualizar: ";
    cin.ignore();
    cin.getline(nombre, MAX_NOMBRE);
    bool encontrado = false;
    for (int i = 0; i < numProductos; i++) {
        if (strcmp(productos[i].nombre, nombre) == 0) {
            cout << "Ingrese el nuevo precio del producto: ";
            cin >> productos[i].precio;
            encontrado = true;
            cout << "Producto actualizado exitosamente.\n";
            break;
        }
    }
    if (!encontrado) {
        cout << "Producto no encontrado.\n";
    }
}

void eliminarProducto(Producto productos[], int &numProductos) {
    char nombre[MAX_NOMBRE];
    cout << "Ingrese el nombre del producto a eliminar: ";
    cin.ignore();
    cin.getline(nombre, MAX_NOMBRE);
    for (int i = 0; i < numProductos; i++) {
        if (strcmp(productos[i].nombre, nombre) == 0) {
            for (int j = i; j < numProductos - 1; j++) {
                productos[j] = productos[j + 1];
            }
            numProductos--;
            cout << "Producto eliminado exitosamente.\n";
            return;
        }
    }
    cout << "Producto no encontrado.\n";
}

void registrarVenta(Venta ventas[], const Producto productos[], int &contadorVentas, int numProductos) {
    Venta nueva;
    cout << "Ingrese el nombre del producto vendido: ";
    cin.ignore();
    cin.getline(nueva.producto, MAX_NOMBRE);
    cout << "Ingrese la cantidad vendida: ";
    cin >> nueva.cantidad;
    bool encontrado = false;
    for (int i = 0; i < numProductos; i++) {
        if (strcmp(productos[i].nombre, nueva.producto) == 0) {
            nueva.idVenta = ++contadorVentas;
            nueva.precioTotal = productos[i].precio * nueva.cantidad;
            ventas[contadorVentas - 1] = nueva;
            cout << "Venta registrada exitosamente.\n";
            encontrado = true;
            break;
        }
    }
    if (!encontrado) {
        cout << "Producto no encontrado. Venta no registrada.\n";
    }
}

void listarVentas(const Venta ventas[], int contadorVentas) {
    for (int i = 0; i < contadorVentas; i++) {
        cout << "ID Venta: " << ventas[i].idVenta << ", Producto: " << ventas[i].producto
             << ", Cantidad: " << ventas[i].cantidad << ", Precio Total: " << ventas[i].precioTotal << '\n';
    }
}

void calcularTotalVentas(const Venta ventas[], int contadorVentas) {
    float total = 0;
    for (int i = 0; i < contadorVentas; i++) {
        total += ventas[i].precioTotal;
    }
    cout << "Total de ventas realizadas: " << total << '\n';
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