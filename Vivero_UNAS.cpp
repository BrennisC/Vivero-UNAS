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

const string CORRECT_PASSWORD = "vivero_unas2024"; // para poder acceder

struct Plants
{
    string plant_name;
    int plant_quantity;
    vector<float> prices;
};

struct Fertilizer
{
    string fertilizer_name;
    float fertilizer_price;
    char registration_date;
};

struct Client
{
    string name;
    string ID;
};

bool verifyPassword()
{
    string enteredPassword;
    while (CORRECT_PASSWORD != enteredPassword)
    {
        cout << "Ingrese tu contraseña ";
        getline(cin, enteredPassword);
        system("cls");
    }
    system("cls"); // to clear the buffer
    return enteredPassword == CORRECT_PASSWORD;
}

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

        cin.ignore();

        cout << "\nRegistro de planta " << i + 1 << " completado.\n\n";
    }
    system("cls");
}

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
        cout << "No se pudo abrir el archivo de registro.\n";
    }
    getch();
    system("cls");
}

void RegisterFertilizer(vector<Fertilizer> &fertilizers)
{
    cout << " ____________________" << endl;
    cout << "|                    |" << endl;
    cout << "|  REGISTRO DE ABONO |" << endl;
    cout << "|____________________|\n\n";
    int quantity;
    cout << "Ingrese los abonos comprados: ";
    cin >> quantity;

    fertilizers.resize(quantity);
    cin.ignore();
    for (int i = 0; i < quantity; i++)
    {
        cout << "Ingrese el nombre del abono " << i + 1 << " : ";
        getline(cin, fertilizers[i].fertilizer_name);
        cout << "Ingrese la fecha del registro " << i + 1 << " : ";
        cin.get(fertilizers[i].registration_date);
        cout << "Ingrese el monto del abono " << i + 1 << " : ";
        cin >> fertilizers[i].fertilizer_price;
        cout << "\n\nIngrese del abono " << i + 1 << "completado \n\n";
    }
    system("cls");
}

void SaveFertilizer(vector<Fertilizer> &fertilizers)
{
    ofstream file("fertilizer.txt");
    if (file.is_open())
    {
        for (size_t i = 0; i < fertilizers.size(); i++)
        {
            file << "----BOLETA----";
            file << "Abono" << i + 1 << ":\n";
            file << "Nombre: " << fertilizers[i].fertilizer_name << '\t';
            file << "Fecha: " << fertilizers[i].registration_date << '\t';
            file << "Precio: " << fertilizers[i].fertilizer_price << '\t';
        }
        file.close();
    }
    else
    {
        cout << "Error al abrir el archivo para almacenar los datos.\n";
    }

    cout << "Se ha guardado correctamente.\n";
    system("cls");
}

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
        cout << "No se pudo abrir el archivo de abonos.\n";
    }
    getch();
    system("cls");
}

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
    for (int i = 0; i < quantity; i++)
    {
        cout << "Ingrese el nombre del cliente: ";
        getline(cin, clients[i].name);
        cout << "Ingrese el DNI del cliente: ";
        getline(cin, clients[i].ID);
    }
}

void SaveClient(vector<Client> &clients)
{
    ofstream file("client.txt");

    if (file.is_open())
    {
        for (size_t i = 0; i < clients.size(); i++)
        {
            file << clients[i].name << "\n"
                 << clients[i].ID << "\n\n";
        }

        file.close();
    }

    else
    {
        cout << "Error al abrir el archivo para almacenar los datos. ";
    }
    cout << "Has salido del sistema. ";
}

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
    getch();
    system("cls");
}

void ExitSystem(vector<Plants> &registry)
{
    ofstream file("registry.txt");

    if (file.is_open())
    {

        for (size_t i = 0; i < registry.size(); i++)
        {
            file << "--BOLETA--";
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
}

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
        cin >> choice;

        switch (choice)
        {
        case 1:
            system("cls");
            RegisterPlants(registry);
            break;
        case 2:
            system("cls");
            ShowRegistry(registry);
            break;
        case 3:
            system("cls");
            RegisterFertilizer(fertilizers);
            break;
        case 4:
            system("cls");
            LoadFertilizer(fertilizers);
            break;
        case 5:
            system("cls");
            LoadRegistry(registry);
            break;
        case 6:
            system("cls");
            ExitSystem(registry);
            SaveFertilizer(fertilizers);
            break;
        default:
            system("cls");
            cout << "Invalid option.\n";
            break;
        }
    } while (choice != 6);
}

int main()
{
    setlocale(LC_ALL, "en_US.UTF-8");
    Menu();
    return 0;
}
