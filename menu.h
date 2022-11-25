#include "tablero.h"



class menu{
    void six(){
        tablero t1(6,6); // Genera el tablero de tamanio 6
        t1.setCompletados(25);
        t1.logic();
    }
    void ten(){ //Genera el tablero de tamanio 10
        tablero t1(10,10);
        t1.setCompletados(81);
        t1.logic();
    }

public:
    menu(){}
    ~menu(){cout<<"Termino el juego"<<endl;} // Destructor


    void operator++(){ // Sobrecarga del operador ++
        cout<<"---- Dots & Boxes ----"<<endl;
        int input;
        cout<<"1.  Tablero 6 x 6"<<endl;
        cout<<"2.  Tablero 10 x 10"<<endl;
        cout<<"Salir"<<endl;
        cout<<"Seleccione la opcion: "<<endl;
        cin>>input;

        if(input==1){
            six();
        }
        if(input==2){
            ten();
        }
    }

};

