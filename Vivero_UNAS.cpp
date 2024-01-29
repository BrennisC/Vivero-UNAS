#include <iostream>
#include <vector>
#include <conio.h>
#include <stdlib.h>
#include <stdio.h>
#include <string>
#include <ctime>
#include <fstream>
#define BLUE "\033[34m"
#define CYAN "\033[36m"
using namespace std;
const string CONTRASENA_CORRECTA = "vivero_unas2024"; // para poder accerder

bool verificarContrasena()
{
    string contrasenaIngresada;
    while (CONTRASENA_CORRECTA != contrasenaIngresada)
    {
        printf("ingrese la contrase%ca: \n", 164);
        getline(cin, contrasenaIngresada);
        system("cls");
    }
    system("cls"); // para limpiar el buffer
    return contrasenaIngresada == CONTRASENA_CORRECTA;
}

struct Plantas //  estructura de plantas para el vivero
{
    string nombre_plantas;
    int cantidad_plantas;
    vector<float> precios;
};
struct Abono // estructura para ver el abono  realizado por un cliente a una planta
{
    string nombre_abono;
    float precio_adono;
    string fecha_registro;
};
void Registro(vector<Plantas> &registro) // registro de las plantas de vivero
{
    cout << " ______________________" << endl;
    cout << "|                      |" << endl;
    cout << "|  REGISTRO DE PLANTAS |" << endl;
    cout << "|______________________|\n\n";

    int tamanio;
    cout << "Ingrese la cantidad de tipos de plantas del vivero: ";
    cin >> tamanio;
    cin.ignore();

    registro.resize(tamanio); // llamas de nuevo al registro y te dice el tamaño edl vector struct

    for (int i = 0; i < tamanio; i++)
    {
        float pago;
        cout << "Ingrese el nombre de la planta " << i + 1 << ": " << endl;
        getline(cin, registro[i].nombre_plantas);

        cout << "Ingrese la cantidad de " << registro[i].nombre_plantas << " : " << endl;
        cin >> registro[i].cantidad_plantas;

        cout << "Ingrese el precio por unidad de las " << registro[i].nombre_plantas << " : " << endl;
        cin >> pago;
        registro[i].precios.push_back(pago);

        cin.ignore();

        cout << "\nRegistro de planta " << i + 1 << " completado.\n\n";
    }
    system("cls");
}

void mostrarRegistro(const vector<Plantas> &registro) // muestra los datos a ingresar al usuario
{
    cout << " ___________________" << endl;
    cout << "|                   |" << endl;
    cout << "|  MOSTRAR REGISTRO |" << endl;
    cout << "|___________________|\n\n";

    for (size_t i = 0; i < registro.size(); i++)
    {
        cout << "Planta " << i + 1 << ":\n";
        cout << "Nombre: " << registro[i].nombre_plantas << endl;
        cout << "Cantidad: " << registro[i].cantidad_plantas << endl;
        for (float precio : registro[i].precios)
        {
            cout << "Precio: S/. " << precio << endl;
        }
        cout << "\n";
    }
    getch();
    system("cls");
}
void RegistroAbonoUnas(vector<Abono> &abonos) // para registrar la cantidad de abonos que quieres sacar
{
    cout << " ____________________" << endl;
    cout << "|                    |" << endl;
    cout << "|  REGISTRO DE ABONO |" << endl;
    cout << "|____________________|\n\n";
    int cantidad;
    cout << "Ingrese la cantidad de abono que vas a sacar: ";
    cin >> cantidad;

    abonos.resize(cantidad);
    cin.ignore();
    for (int i = 0; i < cantidad; i++)
    {
        cout << "Ingrese el nombre del abono " << i + 1 << " : ";
        getline(cin, abonos[i].nombre_abono);
        cout << "Ingrese la fecha del registro " << i + 1 << " : ";
        getline(cin, abonos[i].fecha_registro);
        cout << "Ingrese el monto del abono " << i + 1 << " : ";
        cin >> abonos[i].precio_adono;
        cout << "\n\nIngrese del abono " << i + 1 << "completado \n\n";
    }
    system("cls");
}
void GuardarAbono(const vector<Abono> &abonos) // guardar el abono que ya has registrado
{
    ofstream archivo("abono.txt"); //

    if (archivo.is_open())
    {
        for (size_t i = 0; i < abonos.size(); i++)
        {
            archivo << "----BOLETA----";
            archivo << "Planta " << i + 1 << ":\n";
            archivo << "Nombre: " << abonos[i].nombre_abono << endl;
            archivo << "Fecha: " << abonos[i].fecha_registro << endl;
            archivo << "Precios: " << abonos[i].precio_adono << endl;
        }

        archivo.close();
    }
    else
    {
        cout << "Error al abrir el archivo para almacenar los datos.\n";
    }

    cout << "Se ha guardado correctamente.\n";
    system("cls");
}
void salirdelSistema(const vector<Plantas> &registro) // salir de sistema y a la vez guardar los datos de la plantas
{
    ofstream archivo("registro.txt");

    if (archivo.is_open())
    {
        for (size_t i = 0; i < registro.size(); i++)
        {
            archivo << "--BOLETA--";
            archivo << "Planta " << i + 1 << ":\n";
            archivo << "Nombre: " << registro[i].nombre_plantas << endl;
            archivo << "Cantidad: " << registro[i].cantidad_plantas << endl;
            archivo << "Precios: " << endl;
            for (float dato : registro[i].precios)
            {
                archivo << dato << endl;
                float pago;
                float total = static_cast<float>(dato) * registro[i].cantidad_plantas;
                archivo << "El pago total es : " << total;
            }
            archivo << "\n-----------------------------\n";
            archivo << "\n";
        }

        archivo.close();
    }
    else
    {
        cout << "Error al abrir el archivo para almacenar los datos.\n";
    }

    cout << "Has salido del sistema.\n";
    exit(0);
    system("cls");
}

void Menu()
{
    cout << BLUE;
    cout << " _______________" << endl;
    cout << "|               |" << endl;
    cout << "|  VIVERO UNAS  |" << endl;
    cout << "|_______________|\n\n";
    cout << CYAN;
    vector<Plantas> registro;
    vector<Abono> abonos;

    if (!verificarContrasena())
    {
        cout << "Contraseña incorrecta. Saliendo del sistema.\n";
        return;
    }

    int opc;
    cout << " _____________________" << endl;
    cout << "|                     |" << endl;
    cout << "|   MENU DE OPCIONES  |" << endl;
    cout << "|_____________________|\n\n";

    do
    {
        cout << "[1] SISTEMA DE REGISTRO: \n";
        cout << "[2] MOSTRAR EL REGISTRO: \n";
        cout << "[3] REGISTRO EL ABONO:\n";
        cout << "[4] GUARDAR EL ABONO:\n";
        cout << "[5] SALIR DEL SISTEMA: \n\n";

        cout << "Ingrese su opcion: ";
        cin >> opc;

        switch (opc)
        {
        case 1:
            system("cls");
            Registro(registro);
            break;
        case 2:
            system("cls");
            mostrarRegistro(registro);
            break;
        case 3:
            system("cls");
            RegistroAbonoUnas(abonos);
            break;
        case 4:
            system("cls");
            GuardarAbono(abonos);
            break;
        case 5:
            system("cls");
            salirdelSistema(registro);
        default:
            system("cls");
            cout << "Opcion no valida.\n";
            break;
        }
    } while (opc != 5);
}

int main()
{
    Menu();
    return 0;
}