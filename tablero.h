#include "lib.h"

class tablero{

    int jugA=0,jugB=0; // Sirve para ver que jugador tiene mas cuadrados ganados
    int filas,col; // El tamaño del tablero
    bool turno = false; // Si es true es el turno de un jugador y si es false es el turno del otro jugador
    int completados;    // Si completados == 0 entonces significa que el juego termino
    vector<vector<char>> Matrix; // La matriz del juego

    bool addlinea(int of,int oc,int df,int dc){ // Logica para añadir una linea y tambien verifica si es un espacio vacio;
        int orF,orC,desF,desC;
        orF=(of-1)*2;
        orC=(oc-1)*2;
        desF=(df-1)*2; // 4
        desC=(dc-1)*2; // 2

        if(orF==desF){
            if(desC<orC){
                if(Matrix[desF][desC+1]=='-') {
                    return false;
                }

                Matrix[desF][desC+1]='-';
            }
            else{
                if(Matrix[desF][desC-1]=='-') {
                    return false;
                }
                Matrix[desF][desC-1]='-';
            }
        }
        else{
            if(desF<orF){
                if(Matrix[desF+1][desC]=='|') {
                    return false;
                }
                Matrix[desF+1][desC]='|';
            }
            else{
                if(Matrix[desF-1][desC]=='|') {
                    return false;
                }
                Matrix[desF-1][desC]='|';
            }
        }
        return true;
    }


    bool turnoextra(){
        bool completed = false;
        for (int i = 1; i < filas*2-1; i+=2) {
            for (int j = 1; j < col*2-1; j+=2) {
                if(Matrix[i][j]== ' ' and ((Matrix[i+1][j]=='-' or Matrix[i+1][j]=='|') and (Matrix[i-1][j]=='-' or Matrix[i-1][j]=='|') and (Matrix[i][j+1]=='-' or Matrix[i][j+1]=='|') and (Matrix[i][j-1]=='-' or Matrix[i][j-1]=='|'))){
                    if(turno){
                        Matrix[i][j]='A';
                        jugA++;
                    }
                    else{
                        Matrix[i][j]='B';
                        jugB++;
                    }
                    //cout<<completados<<endl;
                    completados--;
                    completed=true;
                }
            }
        }
        return completed;
    } // Logica para verificar si los alrededores de un cuadrado estan con lineas



public:
    tablero(int f,int c){
        filas = f;
        col = c;
        for (int i = 0; i < filas*2-1; ++i) {
            vector<char> temp(col*2-1);
            if(i%2==0){
                for (int j = 0; j < col*2-1; ++j) {
                    if(j%2==0){
                        temp[j]='+';
                    }
                    else temp[j]=' ';
                }
            }
            else{
                for (int j = 0; j < col*2-1; ++j) {
                    temp[j]=' ';
                }
            }

            Matrix.push_back(temp);
        }

    }; // Constructor para crear el tablero!!
    ~tablero(){cout<<"Se destruyo"<<endl;} // Destructor de tablero


    void printM(){
        cout<<"   ";
        for (int i = 1; i < col+1; ++i) {
            cout<<i<<"   ";
        }
        cout<<endl;

        int contador = 1;
        for (int i = 0; i < filas*2-1; ++i) {
            if(i%2==0) cout<<contador++<<"  ";
            else cout<<"   ";
            for (int j = 0; j < col*2-1; ++j) {
                cout<<Matrix[i][j]<<" ";
            }
            cout<<endl;
        }
    } //Imprime el tablero entero de una forma bonita
    void logic(){
        int orF=1,orC=1,desF=1,desC=1;
        cout<<"Empezo el juego, empieza el jugador A "<<endl;
        while(true){
            //cout<<completados<<endl;
            printM();
            if(completados==0) break;

            cout<<endl;

            cout<<"Turno del jugador ";

            turno? cout<<"B"<<endl : cout<<"A"<<endl;


            cout<<"Ingrese origen PRIMERO FILA Y DESPUES COLUMNA"<<endl;
            cin>>orF>>orC;

            while (!(1<=orF and orF<=filas) or !(1<=orC and orC<=col)){
                cout<<"Solo se permiten numeros entre 1 y "<<filas<<endl;
                cin>>orF>>orC;
            }

            cout<<"Ingrese destino PRIMERO FILA Y DESPUES COLUMNA"<<endl;
            cin>>desF>>desC;

            while(orC==desC and orF ==desF){
                cout<<"El origen y destino son iguales, coloque de nuevo el origen"<<endl;
                cin>>orF>>orC;
                while (!(1<=orF and orF<=filas) or !(1<=orC and orC<=col)){
                    cout<<"Solo se permiten numeros entre 1 y "<<filas<<endl;
                    cin>>orF>>orC;
                }
                cout<<"Vuelva a colocar el Destino"<<endl;
                cin>>desF>>desC;
            }

            while ((!(1<=orF and orF<=filas) or !(1<=orC and orC<=col)) or !(orC+1 == desC or orC-1 == desC or orC == desC) or !(orF+1 == desF or orF-1 == desF or orF == desF) ){
                cout<<"Solo se permiten numeros entre 1 y 6. Ademas tienen que estar conectados de una forma horizontal o vertical"<<endl;
                cin>>desF>>desC;
            }

            if(addlinea(orF,orC,desF,desC)){
                turno  = switchito(turno);
            }
            else{
                cout<<"La posicion elegida ya esta ocupada. Elije otro lugar"<<endl;
            }

            if(turnoextra()) turno = switchito(turno);
            //while (turnoextra());

        }
        cout<<"Gano el jugador: ";
        jugA>jugB? cout<<'A'<<endl : cout<<'B'<<endl;
    } // Logica del tablero: Restricciones, loop hasta terminar y llama a las demas funciones

    void setCompletados(int num){ // Setter usado en la clase menu para la logica del tablero
        completados=num;
    }

};

