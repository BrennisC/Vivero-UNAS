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
/*
 *@autores
 *BRENNIS BENJAMINN CASTRO CANO
 *PAUL MARCO TARAZONA BENANCIO
 *LUIS ARHIAN VEGA GUILLEN
 */
const string CORRECT_PASSWORD = "vivero_unas2024"; // Código de verificación de contraseña

// Estructura para representar las plantas en el vivero
struct Plants
{
    string plant_name;
    int plant_quantity;
    vector<float> prices;
};
// Estructura para representar los abonos
struct Fertilizer
{
    string fertilizer_name;
    vector<float> fertilizer_price;
    string registration_date;
};
// Estructura para representar a los clientes
struct Client
{
    string name;
    string ID;
};
// Función para verificar la contraseña ingresada por el usuario
bool verifyPassword()
{
    string enteredPassword;
    while (CORRECT_PASSWORD != enteredPassword)
    {
        cout << "Ingrese tu contraseña : ";
        getline(cin, enteredPassword);
        system("cls");
    }
    system("cls");
    return enteredPassword == CORRECT_PASSWORD;
}
// Función para registrar plantas en el vivero
void RegisterPlants(vector<Plants> &registry)
{
    cout << " ______________________" << endl;
    cout << "|                      |" << endl;
    cout << "|  REGISTRO DE PLANTAS |" << endl;
    cout << "|______________________|\n\n";

    int size;
    cout << "Ingrese la cantidad de tipos de plantas del vivero: ";
    cin >> size;
    cin.ignore();

    registry.resize(size);

    for (int i = 0; i < size; i++)
    {
        float payment;
        cout << "Ingrese el nombre de la planta" << i + 1 << ": " << endl;
        getline(cin, registry[i].plant_name);

        cout << "Ingrese la cantidad de plantas " << registry[i].plant_name << " : " << endl;
        cin >> registry[i].plant_quantity;

        cout << "Ingrese el precio por unidad de las " << registry[i].plant_name << " : " << endl;
        cin >> payment;
        registry[i].prices.push_back(payment);
        system("cls");
        cin.ignore();

        cout << "\nRegistro de planta " << i + 1 << " completado.\n\n";
    }
    system("cls");
}
// Funcion para mostrar el registro de plantas
void ShowRegistry(vector<Plants> &registry)
{
    cout << " ___________________" << endl;
    cout << "|                   |" << endl;
    cout << "|  MOSTRAR REGISTRO |" << endl;
    cout << "|___________________|\n\n";

    for (size_t i = 0; i < registry.size(); i++)
    {
        cout << "Planta" << i + 1 << ":\n";
        cout << "Nombre: " << registry[i].plant_name << endl;
        cout << "Cantidad: " << registry[i].plant_quantity << endl;
        for (float price : registry[i].prices)
        {
            cout << "Precio: " << price << endl;
        }
        cout << "\n";
    }
    getch();
    system("cls");
}
// Funcion para modificar el registro de plantas
void UpdatePlantQuantity(vector<Plants> &registry)
{
    cout << " ________________________________" << endl;
    cout << "|                                |" << endl;
    cout << "|  ACTUALIZAR CANTIDAD DE PLANTA |" << endl;
    cout << "|________________________________|\n\n";

    string plantName;
    int newQuantity;
    cout << "Ingrese el nombre de la planta para actualizar la cantidad: ";
    cin.ignore();
    getline(cin, plantName);

    // Buscar la planta en el registro
    bool found = false;
    for (size_t i = 0; i < registry.size(); i++)
    {
        if (registry[i].plant_name == plantName)
        {
            found = true;
            cout << "Ingrese la nueva cantidad para la planta " << plantName << ": ";
            cin >> newQuantity;
            registry[i].plant_quantity = newQuantity;
            cout << "Cantidad actualizada exitosamente.\n";
            break;
        }
    }

    if (!found)
    {
        cout << "La planta no se encontró en el registro.\n";
    }

    cout << "Presione cualquier tecla para continuar...";
    getch();       // Espera a que el usuario presione una tecla antes de continuar
    system("cls"); // Limpia la pantalla
}

// Función para guardar el registro de plantas en un archivo de texto
void SavePlants(vector<Plants> &registry)
{
    ofstream file("registry.txt");

    if (file.is_open())
    {

        for (size_t i = 0; i < registry.size(); i++)
        {
            file << "--REGISTRO--";
            file << "Planta " << i + 1 << '\n';
            file << "Nombre: " << registry[i].plant_name << '\t';
            file << "Cantidad: " << registry[i].plant_quantity << '\t';
            file << "Precio: " << '\t';
            for (float data : registry[i].prices)
            {
                file << data << endl;
                float payment;
                float total = static_cast<float>(data) * registry[i].plant_quantity;
                file << "El pago total es : " << total;
            }
            file << "\n-----------------------------\n";
            file << "\n";
        }
        file.close();
    }
    else
    {
        cout << "Error al abrir el archivo para almacenar los datos.\n";
    }

    cout << "Has salido del sistema.\n";
    system("cls");
}
// Función para cargar el registro de plantas desde un archivo de texto
void LoadRegistry(vector<Plants> &registry)
{
    ifstream file("registry.txt");
    if (file.is_open())
    {
        string line;
        while (getline(file, line))
        {
            cout << line << endl;
        }
        file.close();
    }
    else
    {
        cout << "No se pudo abrir el archivo de cliente.\n";
    }
    system("pause");
    system("cls");
}
// Función para registrar abonos
void RegisterFertilizer(vector<Fertilizer> &fertilizers)
{
    cout << " ____________________" << endl;
    cout << "|                    |" << endl;
    cout << "|  REGISTRO DE ABONO |" << endl;
    cout << "|____________________|\n\n";

    int quantity;
    cout << "Ingrese la cantidad de abonos comprados: ";
    cin >> quantity;

    fertilizers.resize(quantity);
    cin.ignore();

    for (int i = 0; i < quantity; i++)
    {
        int numPrices;
        cout << "Ingrese el nombre del abono " << i + 1 << " : ";
        getline(cin, fertilizers[i].fertilizer_name);

        cout << "Ingrese la fecha del registro " << i + 1 << " : ";
        getline(cin, fertilizers[i].registration_date);
        cout << "Ingrese el precio del abono " << fertilizers[i].fertilizer_name << " : ";
        cin >> numPrices;
        fertilizers[i].fertilizer_price.push_back(numPrices);

        cout << "\nRegistro del abono " << i + 1 << " completado.\n\n";
    }

    getch();
    system("cls");
}

// Función para guardar el registro de abonos en un archivo de texto
void SaveFertilizer(vector<Fertilizer> &fertilizers)
{
    ofstream file("fertilizer.txt");
    if (file.is_open())
    {
        for (size_t i = 0; i < fertilizers.size(); i++)
        {
            file << "--------Registro----------" << '\n';
            file << "Abono " << i + 1 << ":\n";
            file << "Nombre: " << fertilizers[i].fertilizer_name << '\t';
            file << "Fecha: " << fertilizers[i].registration_date << '\t';
            file << "Precio: " << '\n';
            for (auto data : fertilizers[i].fertilizer_price)
            {
                file << data << " S/.\n";
            }
            file << "-----------------------" << '\n';
        }
        file.close();
        cout << "Abonos guardados correctamente.\n";
    }
    else
    {
        cout << "Error al abrir el archivo para guardar los abonos.\n";
    }
    system("pause");
    system("cls");
}
// Función para cargar el registro de abonos desde un archivo de texto
void LoadFertilizer(vector<Fertilizer> &fertilizers)
{
    ifstream file("fertilizer.txt");
    if (file.is_open())
    {
        string line;
        while (getline(file, line))
        {
            cout << line << endl;
        }
        file.close();
    }
    else
    {
        cout << "No se pudo abrir el archivo de cliente.\n";
    }
    system("pause");
    system("cls");
}
// Función para registrar clientes
void RegisterClient(vector<Client> &clients)
{
    cout << " ______________________" << endl;
    cout << "|                      |" << endl;
    cout << "|  REGISTRO DE CLIENTE |" << endl;
    cout << "|______________________|\n\n";
    int quantity;
    cout << "Ingrese la cantidad de clientes : ";
    cin >> quantity;
    clients.resize(quantity);
    cin.ignore();
    for (int i = 0; i < quantity; i++)
    {
        cout << "Ingrese el nombre del cliente: " << i + 1 << endl;
        getline(cin, clients[i].name);
        cout << "Ingrese el DNI del cliente: " << i + 1 << endl;
        getline(cin, clients[i].ID);
    }
    getchar();
    system("cls");
}
// Función para guardar el registro de clientes en un archivo de texto
void SaveClient(vector<Client> &clients)
{
    ofstream file("client.txt");
    if (file.is_open())
    {
        for (size_t i = 0; i < clients.size(); i++)
        {
            file << "------BOLETA------" << endl;
            file << "Cliente " << i + 1 << ":\n";
            file << "Nombre: " << clients[i].name << "\n";
            file << "ID: " << clients[i].ID << "\n";
            file << "-------------------\n\n";
        }
        file.close();
        cout << "Datos de clientes guardados correctamente.\n";
    }
    else
    {
        cout << "Error al abrir el archivo para guardar los datos de clientes.\n";
    }
    system("pause");
    system("cls");
}
// Función para cargar el registro de clientes desde un archivo de texto
void LoadClient(vector<Client> &clients)
{
    ifstream file("client.txt");
    if (file.is_open())
    {
        string line;
        while (getline(file, line))
        {
            cout << line << endl;
        }
        file.close();
    }
    else
    {
        cout << "No se pudo abrir el archivo de cliente.\n";
    }
    system("pause");
    system("cls");
}
// Función para mostrar las opciones de carga desde archivos de texto
void ShowTxt();
// Funcion para poder salir de sistema
void ExitSystem()
{
    cout << "Saliendo del sistema...........";
    exit(0);
}
// Funcion para la busqueda enlazadas
void Menu()
{
    cout << BLUE;
    cout << " _______________" << endl;
    cout << "|               |" << endl;
    cout << "|  VIVERO UNAS  |" << endl;
    cout << "|_______________|\n\n";
    cout << CYAN;
    vector<Plants> registry;
    vector<Fertilizer> fertilizers;
    vector<Client> clients;

    if (!verifyPassword())
    {
        cout << "Contraseña incorrecta vuelve intentar.";
        return;
    }

    int choice;

    do
    {
        cout << " _____________________" << endl;
        cout << "|                     |" << endl;
        cout << "|   MENU DE OPCIONES  |" << endl;
        cout << "|_____________________|\n\n";
        cout << "[1] REGISTRAR PLANTAS: \n";
        cout << "[2] MOSTRAR REGISTRO DE PLANTAS\n";
        cout << "[3] ACTUALIZAR REGISTRO DE PLANTAS: \n";
        cout << "[4] REGISTRAR ABONOS:\n";
        cout << "[5] REGISTRAR CLIENTE\n";
        cout << "[6] CARGAR TXT: \n";
        cout << "[7] SALIR DEL SISTEMA: \n\n";

        cout << "Ingrese su opcion: ";
        cin >> choice;

        switch (choice)
        {
        case 1:
            system("cls");
            RegisterPlants(registry);
            SavePlants(registry);
            break;
        case 2:
            system("cls");
            ShowRegistry(registry);
            break;
        case 3:
            system("cls");
            UpdatePlantQuantity(registry);
            SavePlants(registry);
            break;
        case 4:
            system("cls");
            RegisterFertilizer(fertilizers);
            SaveFertilizer(fertilizers);
            break;
        case 5:
            system("cls");
            RegisterClient(clients);
            SaveClient(clients);
            break;
        case 6:
            system("cls");
            ShowTxt();
            break;
        case 7:
            system("cls");
            ExitSystem();
            break;
        default:
            system("cls");
            cout << "Opcion no valida\n";
            break;
        }
    } while (choice != 7);
}

int main()
{
    setlocale(LC_ALL, "en_US.UTF-8");
    Menu();
    return 0;
}
void ShowTxt()
{
    BLUE;
    vector<Plants> registry;
    vector<Fertilizer> fertilizers;
    vector<Client> clients;

    int choice;
    do
    {
        cout << "[1]Cargar el TXT de  plantas\n";
        cout << "[2]Cargar el TXT de abonos \n";
        cout << "[3]Cargar el TXT de clientes\n";
        cout << "[4]Salir\n\n";
        cout << "Ingrese una  opcion: ";
        cin >> choice;
        switch (choice)
        {
        case 1:
            system("cls");
            LoadRegistry(registry);
            break;
        case 2:
            system("cls");
            LoadFertilizer(fertilizers);
            break;
        case 3:
            system("cls");
            LoadClient(clients);
            break;
        case 4:
            Menu();
            cout << "Volviendo al menu de opciones ";
            break;
        default:
            cout << "Opcion no valida ";
            break;
        }
    } while (choice != 5);
}