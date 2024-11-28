// Hien thi do thi bang ma tran ke, danh sach ke
#include <iostream>
#include <fstream>
#define MAX 20
using namespace std;
// cho vertext lam bien toan cuc, de khi di vao ham nao cung co the biet duoc ten cac dinh do thi
char vertext[MAX];

void input (int a[][MAX],  int &n);
void inputFromFile(int a[][MAX], int &n);
void output(int a[][MAX], int n);

// danh sach ke
struct Node {
    int info;
    Node *link;
};
Node *first[MAX];
int n; // so luong dinh do thi
void init();
Node *makeNode(int x);
void insertFirst(Node *&f,int x);
void inputList();
void inputListFromFile();
void output1(int x); // xuat cac dinh ke voi dinh x
void outputList(); // xuat het


int main(){
    // ma tran ke
    // int a [MAX][MAX], n;
    // inputFromFile(a,n);
    // output(a,n);

    // danh sach ke
    inputList();
    outputList();

    return 0;
}
// ma tran ke
void input (int a[][MAX],  int &n)
{
    // nhap so luong dinh cua do thi
    do {
        cout <<"Nhap so luong dinh cua do thi: ";
        cin >> n;
    }while(n <= 0 || n > MAX);
    // nhap ten cua tung dinh trong do thi
    cout <<"Nhap n ten cac dinh cua do thi theo thu tu: ";
    for(int i =0 ; i < n; i++)
    cin >> vertext[i];

    //nhap ma tran ke
    for( int i =0; i <n ;i++)
    {
        cout << "Nhap tinh chat ke (1/0) cua cac dinh voi dinh "<< vertext[i] << " ";
        for( int j =0; j < n; j++)
        cin >> a[i][j];
    }
}
void inputFromFile(int a[][MAX], int &n)
{
    ifstream inFile;
    inFile.open("D:\\DoThiG.txt");
    if(inFile.is_open())
    {
        inFile >> n;
        for( int i =0; i < n; i++)
        inFile >> vertext[i];
        for(int i =0; i < n ;i++)
            for(int j =0; j < n; j++)
                inFile >> a[i][j];
        inFile.close();
        cout <<"Doc ma tran ke thanh cong " << endl;
    }
    else 
    cout <<"Khong mo duoc file "<< endl;
}
void output(int a[][MAX], int n)
{
cout << "\t";
for( int i =0; i < n; i++)
cout << vertext[i] << "\t";
cout << endl;
for( int i =0; i < n; i++)
{
    cout << vertext[i] << "\t";
    for(int j =0; j < n ; j++)
    cout << a[i][j] << "\t";
    cout << endl;
}
}
// danh sach ke
void init()
{
    for(int i =0; i < n ; i++)
    first[i] == NULL;

}
Node *makeNode(int x)
{
    Node *p = new Node ;
    if(!p) return NULL;
    p ->info = x;
    p->link = NULL;
    return p;
}
void insertFirst(Node *&f,int x)
{
    Node *p = makeNode(x);
    if(!p) return;
    if(f == NULL) 
    f = p;
    else 
    {
        p->link =f;
        f =p;
    }
}
void inputList()
{
    do{
        cout << "Nhap so luong dinh do thi: ";
        cin >> n;
    }while (n <=0 || n > MAX);
    init();
    // Nhap ten cac dinh cua do thi vao ma tran vertext
    cout <<"Nhap ten cac dinh cua do thi: ";
    for( int i=0; i < n; i++)
        cin >> vertext[i];
    for(int i =0; i < n; i++)
    {
        // dua cac dinh dang xet vao ds ke dau tien
        insertFirst(first[i], i);
        
        //dua tung dinh ke vao ds ke
         int x; 
        cout <<"Nhap cac dinh ke voi dinh " << i << "(muon dung thi nhan -1): ";
        while(cin >> x)
        {
            if(x == -1)
            break;
        insertFirst(first[i], i);
        }
        
    }

}
void inputListFromFile();
void output1(int x); // xuat cac dinh ke voi dinh x
void outputList() // xuat het
{
    for( int i =0; i < n; i++)
    {
        cout << "Danh sach ke thu "<< i << ": ";
        Node *q = first[i];
        while(q != NULL)
        {
            cout << q->info << " ";
            q = q->link;
        }
        cout << endl;
    }
}

