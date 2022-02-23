#include<iostream>
#include<fstream>
using namespace std;

// CLASE PELICULA

class Pelicula{
    private:
    string titulo;
    string genero;
    string idioma;
    string duracion;
    string repertorioPeliculas;
    string texto;

    public:
    Pelicula();
    void asignarDatosPelicula(string ,string,string,string);
    void mostrarDatosPelicula();
    void registrarPeliculas();
};

Pelicula :: Pelicula(){

}
void Pelicula :: mostrarDatosPelicula(){

  cout<<"     DATOS DE LA PELICULA"<<endl;
  cout<<"\nTITULO: "<<titulo<<endl;
  cout<<"GENEOR: "<<genero<<endl;
  cout<<"IDIOMA: "<<idioma<<endl;
  cout<<"DURACION: "<<duracion<<endl;

}

void Pelicula :: asignarDatosPelicula(string ti, string ge, string id, string du){
  titulo = ti;
  genero = ge;
  idioma = id;
  duracion = du;

}
void Pelicula :: registrarPeliculas(){
    ifstream peliculas;
    peliculas.open("peliculas.dat",ios::in);
    if(peliculas.fail()){
        cout<<"No se pudo crear el registro de peliculas"<<endl;
    }else{
        while(getline(peliculas,repertorioPeliculas)){
            texto = texto + repertorioPeliculas + "\n";
        }
        peliculas.close();
        cout<<texto<<endl;
        system("pause");
    }
}
