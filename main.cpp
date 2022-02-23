//APLICACIÓN DE CINE:
//Desarrollado por : Cristian Arredondo Vargas

#include<iostream>
#include<windows.h>
#include<cstdlib>
#include "Horario.h"
#include "Pelicula.h"
#include "Usuario.h"
#include "Reserva.h"
using namespace std;

void gotoxy(int x, int y) //Funcion gotoxy
{
    COORD coordinate;
    coordinate.X = x;
    coordinate.Y = y;
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coordinate);
}

void menuPeliculas();
void menuDias();
void menuHora();
void menuExtras();
void InterDirDer(int A[],int n);
void SecuencialOrd(int A[],int n, int dato);

//PROGRAMA PRINCIPAL
int main(){
  int nPeliculas,nDias,nHoras,nMenu,nCartelera,nExtras,n=0;
  int B[10];

//USUARIO
Usuario usuario1;
Usuario admin;

//HORARIO
Horario horario1[10];

//OBJETO PELICULA
  Pelicula pelicula1[10];
  Pelicula repertorio;
  Pelicula spiderman;
  spiderman.asignarDatosPelicula("SPIDERMAN SIN CAMINO A CASA","ACCION Y HEROES","CASTELLANO","2 H 30 M");

  Pelicula encanto;
  encanto.asignarDatosPelicula("ENCANTO","ANIMACION,FANTASIA,MUSICAL","CASTELLANO","1 H 49 M");

  Pelicula matrix;
  matrix.asignarDatosPelicula("MATRIX RESURRECCION","ACCION,CIENCIA FICCION","CASTELLANO","2 H 27 M");

  Pelicula scream;
  scream.asignarDatosPelicula("SCREAM","TERROR,SLASHER","CASTELLANO","1 H 54 M");

  Pelicula kingsman;
  kingsman.asignarDatosPelicula("KINGSMAN EL ORIGEN","ACCION,AVENTURAS,CINE DE ESPIONAJE","DOBLADA","2 H 11 M");

  Pelicula desastre;
  desastre.asignarDatosPelicula("DESASTRE EN EL VUELO US57","THRILLER","DOBLADA","1 H 30 M");

 usuario1.asignarUsuario();

//OBJETO RESERVA
  Reserva reserva[10];
  Reserva reserva1;
  do{
  system("cls");
  cout<<"Bienvenido ";usuario1.mostrarNombre();
  cout<<"\n          MENU DE CINE"<<endl;
  cout<<"COMPRAR BOLETOS           [1]"<<endl;
  cout<<"MOSTRAR BOLETOS COMPRADOS [2]"<<endl;
  cout<<"SELECCIONAR ASIENTOS      [3]"<<endl;
  cout<<"BUSCAR ASIENTO            [4]"<<endl;
  cout<<"VER CARTELERA             [5]"<<endl;
  cout<<"SALIR                     [6]"<<endl;
  cout<<"Ingrese la opcion:  ";cin>> nMenu;
  switch (nMenu)
  {
   case 1:
    system("cls");
     cout<<" Ingrese la cantidad de boletos para comprar: ";cin>>n;
     for(int i=0; i<n; i++){
       system("cls");
       cout<<"BOLETO #"<<i+1;
     menuPeliculas();
     cin>>nPeliculas;
       switch (nPeliculas)
        {//Asignacion de las peliculas
         case 1:
          reserva[i].asignarNomPelicula("SPIDERMAN SIN CAMINO A CASA");

          break;
         case 2:
          reserva[i].asignarNomPelicula("ENCANTO");

          break;
         case 3:
          reserva[i].asignarNomPelicula("MATRIX RESURRECCIONES");

         break;
         case 4:
          reserva[i].asignarNomPelicula("SCREAM");

         break;
         case 5:
          reserva[i].asignarNomPelicula("KINGSMAN EL ORIGEN");

         break;
         case 6:
          reserva[i].asignarNomPelicula("DESASTRE EN EL VUELO US57");

         break;
        }
        menuDias();
        cin>>nDias;
            switch (nDias)
            {
            case 1:
            horario1[i].asignarDia("Lunes");
            break;
            case 2:
            horario1[i].asignarDia("Martes");
            break;
            case 3:
            horario1[i].asignarDia("Miercoles");
            break;
            case 4:
            horario1[i].asignarDia("Jueves");
            break;
            case 5:
            horario1[i].asignarDia("Viernes");
            }
            menuHora();
            cin>>nHoras;
               switch (nHoras)
               {
               case 1:
                  horario1[i].asignarHora("9-11 AM");
                 break;
               case 2:
                  horario1[i].asignarHora("11-1PM");
                  break;
                case 3:
                  horario1[i].asignarHora("1-3PM");
                  break;
                case 4:
                  horario1[i].asignarHora("3- 5PM");
                  break;
               }
     }
    break;
   //MOSTRAR RESERVAS
   case 2:
   if(n==0){
     system("cls");
     cout<<"No hay boletos comprados"<<endl;
     system("PAUSE");
     break;
   }else{
   cout<<" DATOS ELEGIDOS"<<endl;
      for(int i=0; i<n; i++){
      system("cls");
      cout<<"BOLETO #"<<i+1<<endl;
      reserva[i].mostrarDatos();
      horario1[i].mostrarHorario();

      }
      break;
   }

   case 3:{
       if(n==0){
        system("cls");
        cout<<"No hay boletos comprados"<<endl;
        system("PAUSE");
       }else{
           system("cls");
           cout<<"   \nSELECCION DE ASIENTOS"<<endl;
           cout<<"-----------------------------"<<endl;
           for(int i=1; i <= 4; i++){
            for(int j=1; j <= 5 ; j++){
                gotoxy(j*4,i*3);
                cout<<i<<j<<endl;
            }
           }
           cout<<"\nNro. de boletos comprados: "<<n<<endl;
           for(int i=1; i<=n ; i++){
            cout<<"Ingrese el numero de asiento deseado: ";cin>>B[i];
           }
           InterDirDer(B,n);
           cout<<"\nASIENTOS SELECCIONADOS"<<endl;
           for(int i=1; i<=n; i++){

            cout<<B[i]<<"\t";
           }
           cout<<endl;
           system("pause");
       }
       break;
   }

   case 4:{//BUSQUEDA DE ASIENTO
       int dato2;
       if(n==0){
        system("cls");
        cout<<"No hay asientos comprados...."<<endl;
        system("PAUSE");
       }else{
           system("cls");
           cout<<"\n BUSQUEDA DE ASIENTO"<<endl;
           cout<<"Ingrese nro. de asiento para buscar: ";cin>>dato2;
           cout<<"Este asiento pertenece al boleto # ";SecuencialOrd(B,n,dato2);
           cout<<endl;
           system("PAUSE");

       }
     break;
   }
   case 5:{
     system("cls");
     cout<<"           CARTELERA"<<endl;
     cout<<"SPIDERMAN SIN CAMINO A CASA    [1]"<<endl;
     cout<<"ENCANTO                        [2]"<<endl;
     cout<<"MATRIX RESURRECION             [3]"<<endl;
     cout<<"SCREAM                         [4]"<<endl;
     cout<<"KINGSMAN EL ORIGEN             [5]"<<endl;
     cout<<"DESASTRE EN EL VUELO US57      [6]"<<endl;
     cout<<"REPERTORIO DE PELICULAS        [7]"<<endl;
     cout<<"Ingrese la opcion:";cin>>nCartelera;
        switch(nCartelera){
          case 1:{
            system("cls");
            spiderman.mostrarDatosPelicula();
            system("pause");
            break;
          }
          case 2:{
            system("cls");
            encanto.mostrarDatosPelicula();
            system("pause");
            break;
          }
          case 3:{
            system("cls");
            matrix.mostrarDatosPelicula();
            system("pause");
            break;
          }
          case 4:{
            system("cls");
            scream.mostrarDatosPelicula();
            system("pause");
            break;
          }
          case 5:{
            system("cls");
            kingsman.mostrarDatosPelicula();
            system("pause");
            break;
          }
          case 6:{
            system("cls");
            desastre.mostrarDatosPelicula();
            system("pause");
            break;
          }
          case 7:{
              system("cls");
              repertorio.registrarPeliculas();
              system("pause");
              break;
          }
        }
        break;
   }

   case 6:{
     system("cls");
    cout<<"Programa finalizado..."<<endl; break;
   }

  }

  }while(nMenu != 6);
  return 0;

}
//Menús
void menuPeliculas(){

  cout<<" SELECCIONAR PELICULAS"<<endl;
  cout<<"SPIDERMAN                  [1]"<<endl;
  cout<<"ENCANTO                    [2]"<<endl;
  cout<<"MATRIX RESURRECCION        [3]"<<endl;
  cout<<"SCREAM                     [4]"<<endl;
  cout<<"KINGSMAN EL ORIGEN         [5]"<<endl;
  cout<<"DESASTRE EN EL VUELO US57  [6]"<<endl;
  cout<<"Ingrese la opcion: ";
}
void menuDias(){
  system("cls");
    cout<<"   SELECCIONAR DIA"<<endl;
    cout<<"LUNES     [1]"<<endl;
    cout<<"MARTES    [2]"<<endl;
    cout<<"MIERCOLES [3]"<<endl;
    cout<<"JUEVES    [4]"<<endl;
    cout<<"VIERNES   [5]"<<endl;
    cout<<"Ingrese la opcion: ";
}
void menuHora(){
  system("cls");
   cout<<" SELECCIONAR HORA"<<endl;
   cout<<"9-11 AM  [1]"<<endl;
   cout<<"11-1PM   [2]"<<endl;
   cout<<"1PM-3PM  [3]"<<endl;
   cout<<"3PM-5PM  [4]"<<endl;
   cout<<"Ingrese la opciom: ";
}
void menuExtras(){

  system("cls");
  cout<<"SELECCIONA EL EXTRA"<<endl;
  cout<<"GASEOSAS S/2 [1]"<<endl;
  cout<<"POPCORN  S/4 [2]"<<endl;
  cout<<"HOTDOG   S/6 [3]"<<endl;
  cout<<"Ingrese la opcion: ";
}
//Método de Ordenacion
void InterDirDer(int A[],int n){
    for(int i=1; i<n; i++){
        for(int j=1; j<=n-i; j++){
            if(A[j] > A[j+1]){
                int aux;
                aux= A[j];
                A[j]= A[j+1];
                A[j+1] = aux;
            }
        }
    }
}
//Método de busqueda
void SecuencialOrd(int A[],int n, int dato){
    int pos=0;
    int i = 1;
    while((i <=n) &&(A[i]<dato)){
        i= i+1;

    }
    if(i > n || A[i] > dato){
        pos = -i;
    }else{
        pos = i;
    }
    cout<<pos<<endl;
}
