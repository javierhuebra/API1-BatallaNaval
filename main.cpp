#include <iostream>
#include <conio.h>

using namespace std;

pintarMatrizVacia(char matriz[5][5]){
    int i, j;
    for(i=0;i<5;i++){
        for(j=0;j<5;j++){
            matriz[i][j]='~';
        }
    }

};
imprimirMatriz(char matriz[5][5]){
    int i, j;
    for(i=0;i<5;i++){
        for(j=0;j<5;j++){
            cout<<matriz[i][j];
            cout<<"\t";
        }
        cout<<"\n\n";
    }
};

imprimirMatrizRef(char matriz[5][5]){
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

posicionarFlota(int longBarco, char orientacion, int coord1, int coord2, char matriz[5][5]){
    if(orientacion=='h'){
        switch(longBarco){
            case 1:
                if(matriz[coord1][coord2] != 'O'){
                    matriz[coord1][coord2] = 'O';
                    return true;
                }else{
                    cout<<"La posicion ["<<coord1<<"]["<<coord2<<"] esta ocupada con otra flota o el valor de coordenada fuera de rango!";
                    return false;
                };break;

            case 2:
                if(matriz[coord1][coord2] != 'O' && matriz[coord1][coord2+1] != 'O' && coord2<4 ){
                    matriz[coord1][coord2]='O';
                    matriz[coord1][coord2+1]='O';
                    return true;
                }else{
                    cout<<"Si colocas el barco de "<<longBarco<<" lugares en la posicion ["<<coord1<<"]["<<coord2<<"] se chocan tus flotas o salen del mapa!";
                    return false;
                };break;

            case 3:
                if(matriz[coord1][coord2] != 'O' && matriz[coord1][coord2+1] != 'O' && matriz[coord1][coord2+2] != 'O' && coord2<3 ){
                    matriz[coord1][coord2]='O';
                    matriz[coord1][coord2+1]='O';
                    matriz[coord1][coord2+2]='O';
                    return true;
                }else{
                    cout<<"Si colocas el barco de "<<longBarco<<" lugares en la posicion ["<<coord1<<"]["<<coord2<<"] se chocan tus flotas o salen del mapa!";
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
                    cout<<"La posicion ["<<coord1<<"]["<<coord2<<"] esta ocupada con otra flota!";
                    return false;
                };break;

            case 2:
                if(matriz[coord1][coord2] != 'O' && matriz[coord1+1][coord2] != 'O' && coord1<4 ){
                    matriz[coord1][coord2]='O';
                    matriz[coord1+1][coord2]='O';
                    return true;
                }else{
                    cout<<"Si colocas el barco de "<<longBarco<<" lugares en la posicion ["<<coord1<<"]["<<coord2<<"] se chocan tus flotas o salen del mapa!";
                    return false;
                };break;

            case 3:
                if(matriz[coord1][coord2] != 'O' && matriz[coord1+1][coord2] != 'O' && matriz[coord1+2][coord2] != 'O' && coord1<3 ){
                    matriz[coord1][coord2]='O';
                    matriz[coord1+1][coord2]='O';
                    matriz[coord1+2][coord2]='O';
                    return true;
                }else{
                    cout<<"Si colocas el barco de "<<longBarco<<" lugares en la posicion ["<<coord1<<"]["<<coord2<<"] se chocan tus flotas o salen del mapa!";
                    return false;
                };break;
       }
    }
}

int main()
{
    system("color 3");
    char matA[5][5], matB[5][5];
    int longBarco,coord1,coord2;
    char orientacion;
    bool funcionResult=false;

    cout << "\t\t\t -- API 1 - BATALLA NAVAL C++ - LOGICA DE PRG. - TECLAB 2022 -- \n"<< endl;


    pintarMatrizVacia(matA);
    pintarMatrizVacia(matB);
    cout<<"EL JUGADOR 1 COLOCA SU FLOTA! :\n\n";
    imprimirMatrizRef(matA);


    do{
       cout<<"\nCOLOCA 1 FLOTA DE 3 ESPACIOS\n\n";
       cout<<"Se coloca HORIZONTAL(h) o VERTICAL(v): ";
       cin>>orientacion;
       cout<<"\n\n";

       do{
          cout<<"Coordenada horizontal: ";
          cin>>coord2;
          cout<<"\n\n";
          if(coord2<0 || coord2>4){
            cout<<"COORDENADA FUERA DE RANGO [0 - 4]\n";
          }
       }while(coord2<0 || coord2>4);


       do{
          cout<<"Coordenada vertical: ";
          cin>>coord1;
          cout<<"\n\n";
          if(coord1<0 || coord1>4){
            cout<<"COORDENADA FUERA DE RANGO [0 - 4]\n";
          }
       }while(coord1<0 || coord1>4);

       cout<<"\n\n";
       funcionResult=posicionarFlota(3,orientacion,coord1,coord2,matA);
       imprimirMatrizRef(matA);
    }while(funcionResult!=true);






    getch();
    return 0;
}
