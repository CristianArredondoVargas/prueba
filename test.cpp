#include<iostream>
using namespace std;
// Clases
class persona{
   private :  // Atributos
   int edad;
   string nombre;
   public :  // Funciones o metodos
   persona(int _edad, string _nombre);
   void leer();
   void correr();
};
// Constructor nos sirve para inicializar los atributos
persona :: persona(int _edad, string _nombre){
    edad = _edad;
    nombre = _nombre;
}

void persona :: leer(){
    cout<<"Soy "<<nombre<<" y estoy leyendo un libro"<<endl;
}

void persona :: correr(){
    cout<<"Soy "<<nombre<<" y estoy corriendo una maraton"<<endl;
}
int main(){
    persona p1 = persona(20, "Alejandro");
    persona p2(19, "Maria");

    p1.leer();
    p2.correr(); 

    return 0;
}