#include <iostream>

using namespace std;

void pobieraniewyswietlanie(int n, int m,int tab[20][20]){

    cout << "Podaj liczby do macierzy: " << endl;
    for (int i=0;i<n;i++){
            for (int j=0;j<m;j++){
                while(!(cin>>tab[i][j]))
                {
                    cin.clear();
                    cin.sync();
                    cout << "Podaj liczbe calkowita\n";
                }
            }
    }

    for (int i=0;i<n;i++){
            for (int j=0;j<m;j++){
                cout << tab[i][j] << " ";
            }
            cout << endl;
    }
}

void dodawanieodejmowanie(int n1,int m1,int n2, int m2, int tab1[20][20], int tab2[20][20]){

    int x;
    float tab3[n1][m1];

    if(n1 != n2 || m1!=m2){
        cout << "ERR";
        return;
    }

    do{
        do{
            cin.clear();
            cin.sync();
            cout << "Wybierz 1. dodawanie lub 2. odejmowanie:" << endl;
        }while(!(cin>>x));
    }while (x!=1 && x!=2);

    switch (x)
    {
    case 1:
        cout << "Macierz wynikowa: \n" << "ilosc wierszy: " << n1 << "\nilosc kolumn: " << m1 << endl;
        cout << "Macierz:" << endl;
        for(int i=0;i<n1;i++){
            for(int j=0;j<m1;j++){
                tab3[i][j]=tab1[i][j]+tab2[i][j];
                cout << tab3[i][j] << " ";
        }
            cout << endl;
        }
        break;

    case 2:
        cout << "Macierz wynikowa: \n" << "ilosc wierszy: " << n1 << "\nilosc kolumn: " << m1 << endl;
        cout << "Macierz:" << endl;
        for(int i=0;i<n1;i++){
            for(int j=0;j<m1;j++){
                tab3[i][j]=tab1[i][j]-tab2[i][j];
                cout << tab3[i][j] << " ";
        }
            cout << endl;
        }
        break;


    }

}

void mnozenie(int n1,int m1,int n2, int m2, int tab1[20][20], int tab2[20][20]){

    float tab3[n1][m2];

    if(m1 != n2){
        cout << "ERR";
        return;
    }

    cout << "Macierz wynikowa: \n" << "ilosc wierszy: " << n1 << "\nilosc kolumn: " << m2 << endl;
    cout << "Macierz:" << endl;

    for(int i=0;i<n1;i++){
            for(int j=0;j<m2;j++){
                tab3[i][j] = 0;
                for(int k=0;k<n2;k++){
                    tab3[i][j] += tab1[i][k]*tab2[k][j];
                    }
                cout << tab3[i][j] << " ";
        }
            cout << endl;
        }

}

void transpozycja(int n1,int m1,int tab1[20][20]){

    float tab2[m1][n1];

    cout << "Macierz wynikowa: \n" << "ilosc wierszy: " << m1 << "\nilosc kolumn: " << n1 << endl;
    cout << "Macierz: " << endl;

    for(int i=0;i<m1;i++){
        for (int j=0;j<n1;j++){
            tab2[i][j] = tab1[j][i];
            cout << tab2[i][j] << " ";
        }
        cout << endl;
    }
}

int wyznacznik(int n1,int m1,int tab1[20][20]){

    int wyznacznik;
    if(n1==2 && m1==2){
        wyznacznik = tab1[0][0]*tab1[1][1]-tab1[0][1]*tab1[1][1];
        return wyznacznik;
    }

    else{
        cout << "ERR";
        return 0;
    }
    }

int main()
{
    int n1,n2,m1,m2;
    int B[20][20];
    int A[20][20];
    int x;

    do{
            do{
                cin.clear();
                cin.sync();

                system("CLS");
                cout << "Podaj liczbe od 1 do 4.\n";
                cout << "Jaka operacje chcesz wykonac?\n";
                cout << "1.Dodawanie i odejmowanie macierzy\n";
                cout << "2.Mnozenie macierzy\n";
                cout << "3.Transpozycja macierzy\n";
                cout << "4.Obliczanie wyznacznika macierzy 2 stopnia\n";
            }while(!(cin>>x));
    }while(x!=1 && x!=2 && x!=3 && x!=4);


    do{
            cin.clear();
            cin.sync();
            cout << "Podaj ilosc wierszy macierzy:";
    }while(!(cin>>n1));

    do{
            cin.clear();
            cin.sync();
            cout << "Podaj ilosc kolumn macierzy:";
    }while(!(cin>>m1));

    pobieraniewyswietlanie(n1,m1,A);

    switch(x){

    case 1:

        do{
                cin.clear();
                cin.sync();
                cout << "Podaj ilosc wierszy drugiej macierzy:";
        }while(!(cin>>n2));

        do{
                cin.clear();
                cin.sync();
                cout << "Podaj ilosc kolumn drugiej macierzy:";
        }while(!(cin>>m2));

        pobieraniewyswietlanie(n2,m2,B);
        dodawanieodejmowanie(n1,m1,n2,m2,A,B);
        break;

    case 2:

        do{
                cin.clear();
                cin.sync();
                cout << "Podaj ilosc wierszy drugiej macierzy:";
        }while(!(cin>>n2));

        do{
                cin.clear();
                cin.sync();
                cout << "Podaj ilosc kolumn drugiej macierzy:";
        }while(!(cin>>m2));

        pobieraniewyswietlanie(n2,m2,B);
        mnozenie(n1,m1,n2,m2,A,B);
        break;

    case 3:

        transpozycja(n1,m1,A);
        break;

    case 4:

        if(wyznacznik(n1,m1,A)!=0)
            cout << "Wyznacznik macierzy to: " << wyznacznik(n1,m1,A);

        break;

    }

    return 0;
}
