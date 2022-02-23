#include<iostream>
using namespace std;

//CLASE HORARIO
class Horario{
  private:
  string hora;
  string dia;
  public:
  Horario();
  void asignarHora(string);
  void asignarDia(string);
  void mostrarHorario();
};
Horario :: Horario(){

}
void Horario :: asignarHora(string h){
   hora = h;
}
void Horario :: asignarDia(string d){
  dia = d;
}
void Horario :: mostrarHorario(){
  cout<<"Dia seleccionado: "<<dia<<endl;
  cout<<"Hora elegida: "<<hora<<endl;
  system("pause");
}