#include <iostream>
#include <vector>
#include <string>

using namespace std;

struct Producto {
    string codigoProducto;
    string nombreProducto;
    int cantidadEnInventario;
    double precioProducto;
};

vector<Producto> inventarioGlobal;

void mostrarMenuPrincipal() {
    cout << "\n--- MENU GADGETXPRESS ---\n";
    cout << "1. Registrar Producto\n";
    cout << "2. Mostrar Reporte de Inventario\n";
    cout << "3. Simular Venta de Producto\n";
    cout << "4. Salir del Sistema\n";
}

void registrarNuevoProducto() {
    Producto nuevoProducto;
    cout << "\n--- REGISTRAR PRODUCTO ---\n";
    cout << "Ingrese el codigo: ";
    cin >> nuevoProducto.codigoProducto;
    
    cout << "Ingrese el nombre (sin espacios): ";
    cin >> nuevoProducto.nombreProducto;
    
    cout << "Ingrese la cantidad inicial: ";
    cin >> nuevoProducto.cantidadEnInventario;
    
    cout << "Ingrese el precio: ";
    cin >> nuevoProducto.precioProducto;

    inventarioGlobal.push_back(nuevoProducto);
    cout << "Producto guardado con exito.\n";
}

void mostrarReporteInventario() {
    cout << "\n--- REPORTE DE INVENTARIO ---\n";
    
    if (inventarioGlobal.size() == 0) {
        cout << "El inventario se encuentra vacio.\n";
    } else {
        for (int i = 0; i < inventarioGlobal.size(); i++) {
            cout << "Codigo: " << inventarioGlobal[i].codigoProducto 
                 << " | Nombre: " << inventarioGlobal[i].nombreProducto 
                 << " | Stock: " << inventarioGlobal[i].cantidadEnInventario 
                 << " | Precio: $" << inventarioGlobal[i].precioProducto << "\n";
        }
    }
}

void simularVenta() {
    string codigoBuscar;
    int cantidadAVender;
    bool productoEncontrado = false;

    cout << "\n--- SIMULACION DE VENTA ---\n";
    cout << "Ingrese el codigo del producto a vender: ";
    cin >> codigoBuscar;

    for (int i = 0; i < inventarioGlobal.size(); i++) {
        if (inventarioGlobal[i].codigoProducto == codigoBuscar) {
            productoEncontrado = true;
            
            cout << "Producto: " << inventarioGlobal[i].nombreProducto << "\n";
            cout << "Stock actual: " << inventarioGlobal[i].cantidadEnInventario << "\n";
            cout << "Ingrese la cantidad que desea vender: ";
            cin >> cantidadAVender;

            // Validacion: Verifica si el stock disponible cubre la venta solicitada
            if (cantidadAVender <= inventarioGlobal[i].cantidadEnInventario) {
                inventarioGlobal[i].cantidadEnInventario = inventarioGlobal[i].cantidadEnInventario - cantidadAVender;
                cout << "Venta realizada con exito.\n";
            } else {
                cout << "Error: No hay suficiente inventario disponible.\n";
            }
            break; 
        }
    }

    if (productoEncontrado == false) {
        cout << "Error: El producto con el codigo ingresado no existe.\n";
    }
}

int main() {
    int opcionSeleccionada;

    do {
        mostrarMenuPrincipal();
        cout << "Elija una opcion: ";
        cin >> opcionSeleccionada;

        if (opcionSeleccionada == 1) {
            registrarNuevoProducto();
        } else if (opcionSeleccionada == 2) {
            mostrarReporteInventario();
        } else if (opcionSeleccionada == 3) {
            simularVenta();
        } else if (opcionSeleccionada == 4) {
            cout << "Saliendo del programa...\n";
        } else {
            cout << "Opcion incorrecta. Intente de nuevo.\n";
        }
    } while (opcionSeleccionada != 4);

    return 0;
}