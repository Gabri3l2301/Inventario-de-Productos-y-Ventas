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