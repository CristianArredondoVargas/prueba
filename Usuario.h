#include<iostream>
using namespace std;
//  CLASE USUARIO

class Usuario{
    private:
    string nroIdentificacion;
    string nombres;
    string admin;
    public:
    Usuario();
    void asignarUsuario();
    void mostrarNombre();
    string retornarAdmin();
};
Usuario :: Usuario(){
  nroIdentificacion = " ";
  nombres = " ";
}
void Usuario :: asignarUsuario(){

           cout<<"INGRESO DE DATOS"<<endl;
           cout<<"Numero de identificacion: ";cin>>nroIdentificacion;
           cin.ignore();
           cout<<"Nombres y apellidos: ";getline(cin,nombres);

        system("pause");
   }

void Usuario :: mostrarNombre(){
  cout<<nombres<<"..."<<endl;
}
string Usuario :: retornarAdmin(){
 return admin;
}

