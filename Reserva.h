#include<iostream>

using namespace std;

//CLASE RESERVA
class Reserva{
     private:
     string nomPelicula;
     double precioBoleto= 11; // El precio basico del boleto es 11 soles
     public:
     Reserva();
     void asignarNomPelicula(string);
     void mostrarDatos();

};
Reserva :: Reserva(){

}

void Reserva :: asignarNomPelicula(string nomP){
    nomPelicula = nomP;
}


void Reserva :: mostrarDatos(){
   cout<<"Pelicula: "<<nomPelicula<<endl;
   cout<<"Precio del boleto: "<<precioBoleto<<endl;
}


