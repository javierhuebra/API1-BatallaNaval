#include <iostream>
#include <conio.h>
#include <windows.h>

using namespace std;

pintarMatrizVacia(char matriz[5][5]){ //LLENA UNA MATRIZ DE 5X5 DE SIMBOLOS ~
    int i, j;
    for(i=0;i<5;i++){
        for(j=0;j<5;j++){
            matriz[i][j]='~';
        }
    }

};
pintarMatrizLlena(char matriz[5][5]){ //LLENA
    int i, j;
    for(i=0;i<5;i++){
        for(j=0;j<5;j++){
            matriz[i][j]='O';
        }
    }

};
imprimirMatriz(char matriz[5][5]){ //esta funcion esta inutilizada por el momento
    int i, j;
    for(i=0;i<5;i++){
        for(j=0;j<5;j++){
            cout<<matriz[i][j];
            cout<<"\t";
        }
        cout<<"\n\n";
    }
};

imprimirMatrizRef(char matriz[5][5]){ //IMPRIME UNA MATRIZ DE 5X5 CON SUS REFERENCIAS EN COLUMNAS Y FILAS
    int i, j;
    char letras[5]={'0','1','2','3','4'};

    for(i=0;i<5;i++){
        cout<<"["<<letras[i]<<"]";
        cout<<"\t";
    }
    cout<<"\n\n";

    for(i=0;i<5;i++){
        for(j=0;j<5;j++){
            cout<<matriz[i][j];
            cout<<"\t";
        }
        cout<<"["<<i<<"]";
        cout<<"\n\n";
    }


}

posicionarFlota(int longBarco, char orientacion, int coord1, int coord2, char matriz[5][5]){ //FUNCION QUE POSICIONA LAS FLOTAS ESPECIFICADAS EN EL ENUNCIADO
    if(orientacion=='h'){
        switch(longBarco){
            case 1:
                if(matriz[coord1][coord2] != 'O'){
                    matriz[coord1][coord2] = 'O';
                    return true;
                }else{
                    cout<<"La posicion ["<<coord1<<"]["<<coord2<<"] esta ocupada con otra flota o el valor de coordenada fuera de rango!\n";
                    system("pause");
                    return false;
                };break;

            case 2:
                if(matriz[coord1][coord2] != 'O' && matriz[coord1][coord2+1] != 'O' && coord2<4 ){
                    matriz[coord1][coord2]='O';
                    matriz[coord1][coord2+1]='O';
                    return true;
                }else{
                    cout<<"Si colocas el barco de "<<longBarco<<" lugares en la posicion ["<<coord1<<"]["<<coord2<<"] se chocan tus flotas o salen del mapa!\n";
                    system("pause");
                    return false;
                };break;

            case 3:
                if(matriz[coord1][coord2] != 'O' && matriz[coord1][coord2+1] != 'O' && matriz[coord1][coord2+2] != 'O' && coord2<3 ){
                    matriz[coord1][coord2]='O';
                    matriz[coord1][coord2+1]='O';
                    matriz[coord1][coord2+2]='O';
                    return true;
                }else{
                    cout<<"Si colocas el barco de "<<longBarco<<" lugares en la posicion ["<<coord1<<"]["<<coord2<<"] se chocan tus flotas o salen del mapa!\n";
                    system("pause");
                    return false;
                };break;


        }
    }else{
       switch(longBarco){
            case 1:
                if(matriz[coord1][coord2] != 'O'){
                    matriz[coord1][coord2] = 'O';
                    return true;
                }else{
                    cout<<"La posicion ["<<coord1<<"]["<<coord2<<"] esta ocupada con otra flota o el valor de coordenada fuera de rango!\n";
                    system("pause");
                    return false;
                };break;

            case 2:
                if(matriz[coord1][coord2] != 'O' && matriz[coord1+1][coord2] != 'O' && coord1<4 ){
                    matriz[coord1][coord2]='O';
                    matriz[coord1+1][coord2]='O';
                    return true;
                }else{
                    cout<<"Si colocas el barco de "<<longBarco<<" lugares en la posicion ["<<coord1<<"]["<<coord2<<"] se chocan tus flotas o salen del mapa!\n";
                    system("pause");
                    return false;
                };break;

            case 3:
                if(matriz[coord1][coord2] != 'O' && matriz[coord1+1][coord2] != 'O' && matriz[coord1+2][coord2] != 'O' && coord1<3 ){
                    matriz[coord1][coord2]='O';
                    matriz[coord1+1][coord2]='O';
                    matriz[coord1+2][coord2]='O';
                    return true;
                }else{
                    cout<<"Si colocas el barco de "<<longBarco<<" lugares en la posicion ["<<coord1<<"]["<<coord2<<"] se chocan tus flotas o salen del mapa!\n";
                    system("pause");
                    return false;
                };break;
       }
    }
}
solicitarInteraccion(int nroJugador, char matriz[5][5]){ //FUNCION QUE GESTIONA LOS PROCESOS DE CADA JUGADOR ANTES DE EMPEZAR EL JUEGO
    HANDLE hConsole = GetStdHandle( STD_OUTPUT_HANDLE );
    int longBarco,coord1,coord2;
    bool funcionResult=false;
    char orientacion;
    char matrizBackup[5][5];
    do{
        SetConsoleTextAttribute(hConsole, 12);
        cout<<"\nJUGADOR "<<nroJugador<<" COLOCA 1 FLOTA DE 3 ESPACIOS [0 0 0]\n\n";
        SetConsoleTextAttribute(hConsole, 10);
        cout<<"Se coloca HORIZONTAL(h) o VERTICAL(v): ";
        cin>>orientacion;
        cout<<"\n";

        do{                                      //CON ESTA SENTENCIA HAGO QUE LA COORDENADA INGRESADA ESTE EN EL RANGO DE LA MATRIZ SINO SE VUELVE A PEDIR EL VALOR
          cout<<"Coordenada horizontal: ";
          cin>>coord2;
          if(coord2<0 || coord2>4){
            cout<<"COORDENADA FUERA DE RANGO [0 - 4]\n";
          }
        }while(coord2<0 || coord2>4);


        do{
          cout<<"Coordenada vertical: ";
          cin>>coord1;
          if(coord1<0 || coord1>4){
            cout<<"COORDENADA FUERA DE RANGO [0 - 4]\n";
          }
        }while(coord1<0 || coord1>4);

        cout<<"\n";
        funcionResult=posicionarFlota(3,orientacion,coord1,coord2,matriz);
        system("cls");
        SetConsoleTextAttribute(hConsole, 3);
        cout << "\t\t\t -- API 1 - BATALLA NAVAL C++ - LOGICA DE PRG. - TECLAB 2022 -- \n"<< endl;
        SetConsoleTextAttribute(hConsole, 12);
        cout<<"TURNO DEL JUGADOR "<<nroJugador<<"\n"<<endl;
        SetConsoleTextAttribute(hConsole, 10);
        imprimirMatrizRef(matriz);
        }while(funcionResult!=true);

        do{
            int repeticion=0;
            for(int i=0;i<5;i++){
                for(int j=0;j<5;j++){
                    matrizBackup[i][j]=matriz[i][j];
                }
            }
            while(repeticion<2){
            SetConsoleTextAttribute(hConsole, 12);
            cout<<"JUGADOR "<<nroJugador<<" COLOCA 2 FLOTAS DE 2 ESPACIOS [0 0] [0 0]\n\n";
            SetConsoleTextAttribute(hConsole, 10);
            cout<<"Flota "<<repeticion+1<<" de 2:\n";
            cout<<"Se coloca HORIZONTAL(h) o VERTICAL(v): ";
            cin>>orientacion;
            cout<<"\n";

            do{
                cout<<"Coordenada horizontal: ";
                cin>>coord2;
                if(coord2<0 || coord2>4){
                cout<<"COORDENADA FUERA DE RANGO [0 - 4]\n";
            }
            }while(coord2<0 || coord2>4);

            do{
                cout<<"Coordenada vertical: ";
                cin>>coord1;
                if(coord1<0 || coord1>4){
                cout<<"COORDENADA FUERA DE RANGO [0 - 4]\n";
            }
            }while(coord1<0 || coord1>4);

            cout<<"\n";



            funcionResult=posicionarFlota(2,orientacion,coord1,coord2,matriz);
            if(funcionResult!=true){
               for(int i=0;i<5;i++){
                for(int j=0;j<5;j++){
                    matriz[i][j]=matrizBackup[i][j];
                }
            }
            }
            system("cls");
            SetConsoleTextAttribute(hConsole, 3);
            cout << "\t\t\t -- API 1 - BATALLA NAVAL C++ - LOGICA DE PRG. - TECLAB 2022 -- \n"<< endl;
            SetConsoleTextAttribute(hConsole, 12);
            cout<<"TURNO DEL JUGADOR "<<nroJugador<<"\n"<<endl;
            SetConsoleTextAttribute(hConsole, 10);
            imprimirMatrizRef(matriz);
            repeticion++;
        }

    }while(funcionResult!=true);

    do{
        int repeticion=0;
        for(int i=0;i<5;i++){
                for(int j=0;j<5;j++){
                    matrizBackup[i][j]=matriz[i][j];
                }
            }
        while(repeticion<2){
            SetConsoleTextAttribute(hConsole, 12);
            cout<<"JUGADOR "<<nroJugador<<" COLOCA 2 FLOTAS DE 1 ESPACIOS [0] [0]\n\n"<<endl;
        SetConsoleTextAttribute(hConsole, 10);
            cout<<"Flota "<<repeticion+1<<" de 2:\n";
            //se le quita la parte de colocar orientacion ya que es una pieza de un solo espacio
            cout<<"\n";

            do{
                cout<<"Coordenada horizontal: ";
                cin>>coord2;
                if(coord2<0 || coord2>4){
                cout<<"COORDENADA FUERA DE RANGO [0 - 4]\n";
            }
            }while(coord2<0 || coord2>4);

            do{
                cout<<"Coordenada vertical: ";
                cin>>coord1;
                if(coord1<0 || coord1>4){
                cout<<"COORDENADA FUERA DE RANGO [0 - 4]\n";
            }
            }while(coord1<0 || coord1>4);

            cout<<"\n";



            funcionResult=posicionarFlota(1,'h',coord1,coord2,matriz);
            if(funcionResult!=true){
               for(int i=0;i<5;i++){
                for(int j=0;j<5;j++){
                    matriz[i][j]=matrizBackup[i][j];
                    }
                }
            }
            system("cls");
            SetConsoleTextAttribute(hConsole, 3);
            cout << "\t\t\t -- API 1 - BATALLA NAVAL C++ - LOGICA DE PRG. - TECLAB 2022 -- \n"<< endl;
            SetConsoleTextAttribute(hConsole, 12);
            cout<<"TURNO DEL JUGADOR "<<nroJugador<<"\n"<<endl;
            SetConsoleTextAttribute(hConsole, 10);
            imprimirMatrizRef(matriz);
            repeticion++;
        }
    }while(funcionResult!=true);
}

comprobarMatrizVacia(char matriz[5][5]){ //ESTA FUNCION HACE LA COMPROBACION SI TODAS LAS FLOTAS FUERON DESTRUIDAS (SI NO HAY CARACTERES 'O' EN LA MATRIZ)
    int puntos=0,i=0,j=0;
    for(i=0;i<5;i++){                       //NO SE ESTA USANDO PERO LA DEJO IGUAL JEJE
        for(j=0;j<5;j++){
            if(matriz[i][j]=='O')
                puntos++;
        }
    }
    return puntos; //retorna la cantidad de puntos sin destruir
}

ataquesAlternados(char mat1[5][5],char mat2[5][5]){
    int cantidadFlotas1, cantidadFlotas2, coord2, coord1,jugador,turno=1,i,j;
    int flotas1=9,flotas2=9;
    do{
        jugador=1;
        while(jugador<3){
            cout<<"JUGADOR "<<jugador<<" PREPARA EL MISILAZO! (TURNO "<<turno<<")\n"<<endl;
            do{
                cout<<"Coordenada horizontal: ";
                cin>>coord2;
                if(coord2<0 || coord2>4){
                cout<<"COORDENADA FUERA DE RANGO [0 - 4]\n";
            }
            }while(coord2<0 || coord2>4);

            do{
                cout<<"Coordenada vertical: ";
                cin>>coord1;
                if(coord1<0 || coord1>4){
                cout<<"COORDENADA FUERA DE RANGO [0 - 4]\n";
            }
            }while(coord1<0 || coord1>4);

            if(jugador==1){
                if(mat2[coord1][coord2]=='O'){
                    mat2[coord1][coord2]='H';

                    cout<<"SU DISPARO HA DADO EN EL BLANCO :D EN JUGADOR 2 ["<<coord1<<"]["<<coord2<<"]\n"<<endl;
                    imprimirMatrizRef(mat2);
                    flotas2--;

                }else{
                    if(mat2[coord1][coord2]=='H'){
                        mat2[coord1][coord2]=='H';
                        cout<<"SU DISPARO YA HABIA IMPACTADO EN ESTE BARCO ["<<coord1<<"]["<<coord2<<"]\n"<<endl;
                    }else{
                        mat2[coord1][coord2]='A';
                        cout<<"SU DISPARO HA HECHO AGUA :( EN JUGADOR 2 ["<<coord1<<"]["<<coord2<<"]\n"<<endl;
                        imprimirMatrizRef(mat2);
                    }

                }
            }else{
                if(mat1[coord1][coord2]=='O'){
                    mat1[coord1][coord2]='H';
                    cout<<"SU DISPARO HA DADO EN EL BLANCO :D EN JUGADOR 1 ["<<coord1<<"]["<<coord2<<"]\n"<<endl;
                    imprimirMatrizRef(mat1);
                    flotas1--;
                }else{
                    if(mat1[coord1][coord2]=='H'){
                        mat1[coord1][coord2]=='H';
                        cout<<"SU DISPARO YA HABIA IMPACTADO EN ESTE BARCO ["<<coord1<<"]["<<coord2<<"]\n"<<endl;
                    }else{
                        mat1[coord1][coord2]='A';
                        cout<<"SU DISPARO HA HECHO AGUA :( EN JUGADOR 1 ["<<coord1<<"]["<<coord2<<"]\n"<<endl;
                        imprimirMatrizRef(mat1);
                    }

                }
            }

            jugador++;
        }



    cout<<"Flotas 1:"<<flotas1<<""<<endl;

    cout<<"Flotas 2:"<<flotas2<<""<<endl;
    turno++;

    }while(flotas1!=0 && flotas2!=0);


    if(flotas1==0){
            system("cls");
            cout<<"JUGADOR 2 GANA! HA DESTRUIDO TODA LA FLOTA ENEMIGA!\n"<<endl;
            cout<<"Creditos: Javier Emanuel Huebra - TECLAB 2022- LOGICA DE PROGRAMACION"<<endl;
    }else{
            system("cls");
            cout<<"JUGADOR 1 GANA! HA DESTRUIDO TODA LA FLOTA ENEMIGA!\n"<<endl;
            cout<<"Creditos: Javier Emanuel Huebra - TECLAB 2022- LOGICA DE PROGRAMACION"<<endl;
    }


}
int main()
{
    HANDLE hConsole = GetStdHandle( STD_OUTPUT_HANDLE );


    char matA[5][5], matB[5][5];


    SetConsoleTextAttribute(hConsole, 3);
    cout << "\t\t\t -- API 1 - BATALLA NAVAL C++ - LOGICA DE PRG. - TECLAB 2022 -- \n"<< endl;


    pintarMatrizVacia(matA);
    pintarMatrizVacia(matB);

    SetConsoleTextAttribute(hConsole, 12);
    cout<<"TURNO DEL JUGADOR 1\n"<<endl;
    SetConsoleTextAttribute(hConsole, 10);
    cout<<"Debes posicionar tu flota en la siguiente matriz:\n"<<endl;
    imprimirMatrizRef(matA);

    solicitarInteraccion(1,matA); //SE CARGA LA FLOTA DEL JUGADOR 1

    system("cls");
    SetConsoleTextAttribute(hConsole, 3);
    cout << "\t\t\t -- API 1 - BATALLA NAVAL C++ - LOGICA DE PRG. - TECLAB 2022 -- \n"<< endl;
    SetConsoleTextAttribute(hConsole, 12);
    cout<<"TURNO DEL JUGADOR 2\n"<<endl;
    SetConsoleTextAttribute(hConsole, 10);
    cout<<"Debes posicionar tu flota en la siguiente matriz:\n"<<endl;
    imprimirMatrizRef(matB);

    solicitarInteraccion(2,matB); //SE CARGA LA FLOTA DEL JUGADOR 2

    system("cls");
    SetConsoleTextAttribute(hConsole, 3);
    cout << "\t\t\t -- API 1 - BATALLA NAVAL C++ - LOGICA DE PRG. - TECLAB 2022 -- \n"<< endl;

    cout<<"LAS FLOTAS ESTAN LISTAS PARA EL COMBATE!\n"<<endl;
    SetConsoleTextAttribute(hConsole, 4);
    cout<<"FLOTA DEL JUGADOR 1:"<<endl;
    SetConsoleTextAttribute(hConsole, 7);
    imprimirMatrizRef(matA);
    SetConsoleTextAttribute(hConsole, 6);
    cout<<"\n----------------------------------------------------------\n"<<endl;
    SetConsoleTextAttribute(hConsole, 4);
    cout<<"FLOTA DEL JUGADOR 2:"<<endl;
    SetConsoleTextAttribute(hConsole, 7);
    imprimirMatrizRef(matB);

    system("pause");
    system("cls");


    ataquesAlternados(matA,matB);




    getch();
    return 0;
}
