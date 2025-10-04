#include<iostream>
using namespace std;

class Empleado
{
    private: // Nacen de la relacion tiene
    char nombre[10];        //108
    int edad;               //48
    char Direccion[255];    //255B
    int telefono;            //48
public:
    int LeerEdad(){
        return edad;
    }
}; // -> 273B

int main(int argc, char const *argv[])
{
    //Tamaños de memoria estatica
    //Enteros
    cout << "Tamaño de int" << sizeof(int) << endl;
    cout << "Tamaño de long" << sizeof(long) << endl;
    // punto Flotante
    cout << "Tamaño de float" << sizeof(float) << endl;
    cout << "Tamaño de double" << sizeof(double) << endl;
    //Bytes
    cout << "Tamaño de char" << sizeof(char) << endl;
    cout << "Tamaño de byte" << sizeof(byte) << endl;
    cout << "Tamaño de bool" << sizeof(bool) << endl;

    cout << "Tamaño puntero" << sizeof(int) << endl;
    //Tamaño tipo no nativos
    Empleado empleado[10]; //<--- 2730B
    cout << "Tamaño Empleado" << sizeof(Empleado) << endl;
    cout << "Empleados" << empleados[0].LeerEdad()<< endl;

    int a=64;
    char b= (char)a;
    cout<< b << endl;
    retun 0;  
}




