#include <iostream>
#include <vector>
#include <string>
#include <fstream>
#include <iomanip>
#include <ctime>
#include <cstdlib>
#include <conio.h>
#define BLUE "\033[34m"
#define CYAN "\033[36m"
using namespace std;

const string CONTRASENA_CORRECTA = "vivero_unas2024"; // para poder acceder

struct Plantas
{
    string nombre_plantas;
    int cantidad_plantas;
    vector<float> precios;
};

struct Abono
{
    string nombre_abono;
    float precio_adono;
    char fecha_registro;
};
struct Cliente
{
    string nombre;
    string DNI;
};
bool verificarContrasena()
{
    string contrasenaIngresada;
    while (CONTRASENA_CORRECTA != contrasenaIngresada)
    {
        cout << "Ingrese su contraseña: ";
        getline(cin, contrasenaIngresada);
        system("cls");
    }
    system("cls"); // para limpiar el buffer
    return contrasenaIngresada == CONTRASENA_CORRECTA;
}

void Registro(vector<Plantas> &registro)
{
    cout << " ______________________" << endl;
    cout << "|                      |" << endl;
    cout << "|  REGISTRO DE PLANTAS |" << endl;
    cout << "|______________________|\n\n";

    int tamanio;
    cout << "Ingrese la cantidad de tipos de plantas del vivero: ";
    cin >> tamanio;
    cin.ignore();

    registro.resize(tamanio);

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

void mostrarRegistro(const vector<Plantas> &registro)
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
void CargarRegistro(vector<Plantas> &registro)
{
    ifstream archivo("registro.txt");
    if (archivo.is_open())
    {
        string linea;
        while (getline(archivo, linea))
        {
            cout << linea << endl;
        }
        archivo.close();
    }
    else
    {
        cout << "No se pudo abrir el archivo de registro.\n";
    }
    getch();
    system("cls");
}
void RegistroAbonoUnas(vector<Abono> &abonos)
{
    cout << " ____________________" << endl;
    cout << "|                    |" << endl;
    cout << "|  REGISTRO DE ABONO |" << endl;
    cout << "|____________________|\n\n";
    int cantidad;
    cout << "Ingrese los abonos comprados: ";
    cin >> cantidad;

    abonos.resize(cantidad);
    cin.ignore();
    for (int i = 0; i < cantidad; i++)
    {
        cout << "Ingrese el nombre del abono " << i + 1 << " : ";
        getline(cin, abonos[i].nombre_abono);
        cout << "Ingrese la fecha del registro " << i + 1 << " : ";
        cin.get(abonos[i].fecha_registro);
        cout << "Ingrese el monto del abono " << i + 1 << " : ";
        cin >> abonos[i].precio_adono;
        cout << "\n\nIngrese del abono " << i + 1 << "completado \n\n";
    }
    system("cls");
}
void GuardarAbono(vector<Abono> &abonos)
{
    ofstream archivo("abono.txt");
    if (archivo.is_open())
    {
        for (size_t i = 0; i < abonos.size(); i++)
        {
            archivo << "----BOLETA----";
            archivo << "Planta " << i + 1 << ":\n";
            archivo << "Nombre: " << abonos[i].nombre_abono << '\t';
            archivo << "Fecha: " << abonos[i].fecha_registro << '\t';
            archivo << "Precios: " << abonos[i].precio_adono << '\t';
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

void CargarAbono(vector<Abono> &abonos)
{
    ifstream archivo("abono.txt");
    if (archivo.is_open())
    {
        string linea;
        while (getline(archivo, linea))
        {
            cout << linea << endl;
        }
        archivo.close();
    }
    else
    {
        cout << "No se pudo abrir el archivo de abonos.\n";
    }
    getch();
    system("cls");
}
void RegistrarCliente(vector<Cliente> &clientes)
{
    int cantidad;
    cout << "Ingrese la cantidad de clientes : ";
    cin >> cantidad;
    clientes.resize(cantidad);
    for (int i = 0; i < cantidad; i++)
    {
        cout << "Ingrese el nombre del cliente: ";
        getline(cin, clientes[i].nombre);
        cout << "Ingrese el DNI del cliente: ";
        getline(cin, clientes[i].DNI);
    }
}
void salirdelSistema(vector<Plantas> &registro)
{
    ofstream archivo("registro.txt");

    if (archivo.is_open())
    {
        for (size_t i = 0; i < registro.size(); i++)
        {
            archivo << "--BOLETA--";
            archivo << "Planta " << i + 1 << '\n';
            archivo << "Nombre: " << registro[i].nombre_plantas << '\t';
            archivo << "Cantidad: " << registro[i].cantidad_plantas << '\t';
            archivo << "Precios: " << '\t';
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
        cout << "Contraseña incorrecta vuelve intentar.";
        return;
    }

    int opc;
    cout << " _____________________" << endl;
    cout << "|                     |" << endl;
    cout << "|   MENU DE OPCIONES  |" << endl;
    cout << "|_____________________|\n\n";

    do
    {
        cout << "[1] REGISTRAR PLANTAS: \n";
        cout << "[2] MOSTRAR EL REGISTRO: \n";
        cout << "[3] REGISTRAR ABONOS:\n";
        cout << "[4] CARGAR ABONOS: \n";
        cout << "[5] CARGAR REGISTRO: \n";
        cout << "[6] SALIR DEL SISTEMA: \n\n";

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
            CargarAbono(abonos);
            break;
        case 5:
            system("cls");
            CargarRegistro(registro);
            break;
        case 6:
            system("cls");
            salirdelSistema(registro);
            GuardarAbono(abonos);
            break;
        default:
            system("cls");
            cout << "Opcion no valida.\n";
            break;
        }
    } while (opc != 6);
}

int main()
{
    setlocale(LC_ALL, "es_ES.UTF-8");
    Menu();
    return 0;
}
