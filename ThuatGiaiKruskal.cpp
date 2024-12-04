// cai dat tim cay khung toi thieu bang Kruskal. Kruskal cai tien.
#include<iostream>
#include<fstream>
using namespace std;
const int MAX = 50;
int a[MAX][MAX];
int n;
char vertex[MAX];
int E1[MAX];
int E2[MAX];
int wE[MAX];
int nE = 0;
int T1[MAX];
int T2[MAX];
int wT[MAX];
int nT = 0; // chi so
// hien thi do thi duoi dang ma tran trong so
void inputFromFile(){
    ifstream inFile;
    inFile.open("D:\\Kruskal.txt");
    if(inFile.is_open())
    {
        inFile >> n;
        for( int i = 0; i < n;i++)
        {
            inFile >> vertex[i];
        }
        for(int i =0; i <n ; i++){
            for(int j =0; j < n;j++)
                inFile>> a[i][j];
        }
        inFile.close();
        cout <<"Doc file thanh cong\n";
    }
    else
    {
        cout <<"Doc file khong thanh cong\n";
    }
}

void outPutMatrix(){
    cout <<"Ma tran trong so: \n";
    for( int i =0; i < n; i++)
    {
        for(int j =0; j < n;j++)
            cout << a[i][j] << "\t";
        cout << endl;
    }
}
// buoc tao E
void createE()
{
    for(int i = 0; i < n; i++)
        for(int j =0; j < n;j++)
            if(a[i][j] != 0)
            {
                E1[nE] = i;
                E2[nE]= j;
                wE[nE] = a[i][j]; // wE trong so
                a[i][j] = 0;
                a[j][i] = 0;
                nE++;
            }
}
void outPutE(){
    for(int i =0; i < nE; i++)
        cout <<"(" << vertex[E1[i]] << ","<<vertex[E2[i]]<< "," << wE[i] << ")\n";
}

void hoanDoi(int &x, int &y)
{
    int tmp = x;
    x = y;
    y = tmp;
}
// sap xep tang dan
void arrangeE(){
    for( int i =0; i < nE -1; i++)
        for(int j =i+1; j < nE;j++)
            if(wE[i] > wE[j])
            {
                hoanDoi(E1[i],E1[j]);
                hoanDoi(E2[i],E2[j]);
                hoanDoi(wE[i],wE[j]);
            }

}   

bool check(int a[],int size, int x){
    for(int i =0; i < size;i++)
        if(x == a[i])
            return true;
        return false;
}

// cai dat kruskal
void kruskal(){
    // duyet tu dau den het. tu trong so nho nhat
    for( int i =0; i < nE; i++){
       if(check(T1,nT,E1[i]) && check(T2, nT, E2[i]))
       continue;
       if(check(T1,nT,E2[i]) && check(T2, nT, E1[i]))
        continue; 
        T1[nT] = E1[i];
        T2[nT] = E2[i];
        wT[nT] = wE[i];
        nT++;
        if(nT == n -1)
        break;

    }
}

void xuatCKTT(){
    int sum =0;
    cout <<"Cay khung toi tieu \n";
    for( int i =0; i < nT; i++)
    {
        cout <<"(" << vertex[T1[i]] << ","<< vertex[T2[i]] << "," << wT[i] << ")\n";
        sum += wT[i];
    }
    cout <<"Tong trong so: " << sum << endl;
}

int main(){
    inputFromFile();
    outPutMatrix();
    createE();
    // outPutE();
    arrangeE();
    // cout << endl;
    // outPutE();
    kruskal();
    xuatCKTT();

    return 0;
}