// Hien thi do thi bang ma tran ke, danh sach ke
#include <iostream>
#include <fstream>
#define MAX 20
using namespace std;
int a [MAX][MAX];
int n;
int C[MAX];
int dfs[MAX]; // do thi co maxsize
int ndfs = 0; // chi so de moi lan them 1 dinh ma no duyet duoc
// cho vertext lam bien toan cuc, de khi di vao ham nao cung co the biet duoc ten cac dinh do thi
char vertext[MAX];
int bfs[MAX];
int nbfs = 0;

// ma tran ke
void inputMatrix (int a[][MAX],  int &n)
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
void inputMatrixFromFile(int a[][MAX], int &n)
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
struct Node {
    int info;
    Node *link;
};
Node *first[MAX];
int size; // so luong dinh do thi
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

// stack
Node *st; // dat ten Stack
void init_Stack()
{
st = NULL;
}
bool isEmpty()
{
    if(st == NULL)
    return true;
    return false;
}
void push(int s)
{
    Node *p = new Node ;
    if(p == NULL)
    return;
    p->info = s;
    p->link = st;
    st =p;
}
void pop (int &v) //lay ptu ra khoi ds
{
Node *p = st;
v = p->info;
st = st->link;
delete p;
}
void process_Stack()
{
    Node *p = st;
    while(p != NULL)
    {
        cout << p-> info << " ";
        p = p->link;
    }
    cout << endl;
}

// queue
Node *front, *rear; // dau va duoi
void init_Queue()
{
    front = rear = NULL;
}
bool isEmptyQ()
{
    if(front == NULL)
    return true;
    return false;
}
void pushQ (int x)
{
    Node *p = new Node ;
    p->info = x;
    p->link = NULL;
    if(rear == NULL)
        front = p;
    else 
        rear->link = p;
    rear = p;
}
void popQ(int &x)
{
if(front != NULL)
{
    Node *p = front; // cho front doi ra sau
    x = p->info;
    front = front ->link; // doi ra sau , va delete p
    if(front == NULL)
        rear == NULL;
    delete p;
}
}
void process_Queue()
{
    if(front != NULL)
    {
        cout <<"Hang doi dang luu tru: ";
        Node *p = front;
        while(p != NULL)
        {
            cout << p->info << " ";
             p=p->link;
        }
         cout << endl;
    }
}

//DFS
void initEdgesStatus()
{
    for( int i =0; i < n; i++)
        C[i] = 1;// tat ca dinh o trang thai chua xet
}
void DFS(int s) // s la dinh bat dau duyet dfs
{   
    initEdgesStatus();
    // khoi tao stack
    init_Stack();
    push(s); // push dinh bat dau
    // dsf[ndfs] = s;
    // ndfs++;
    dfs[ndfs++] = s; // toan tu tang hau to
    C[s] = 0;
    int v = -1, u =s ; // bat dau tu dinh ben ngoa, u la dinh xet tiep theo
    while(!isEmpty())
    {
        if(v == n)
            pop(u);
        for(v = 0; v < n; v++)
            if(a[u][v] != 0 && C[v] == 1)
            {
                push(u);
                push(v);
                dfs[ndfs++] = v;
                C[v] =0;
                u = v;
                break; // tim dung 1 nhanh va di nhanh do
            }
    }
}
void output_DFS()
{
    cout <<"ket qua duyet DFS: ";
    for( int i =0 ; i < ndfs; i++)
        cout << vertext[dfs[i]] << " ";
    cout << endl;
}

// BFS
void BFS(int v)
{
    initEdgesStatus();// khoi tao deu o trang thai 1
    init_Queue();
    int w, p; // dinh bat dau
    pushQ(v);
    C[v] = 0;
    while(front != NULL)
    {
        popQ(p);
        bfs[nbfs++] = p;
        for( w = 0; w < n; w++)
            if(C[w] == 1 && a[p][w] == 1)
            {
                pushQ(w);
                C[w] = 0;// cho biet dinh da duoc xet roi
            }
    }
}

void output_BFS()
{
    cout <<"Ket qua duyet BFS: ";
    for(int i =0; i < nbfs; i++)
        cout << vertext[bfs[i]] << " ";
    cout << endl;
}

int main(){
    // ma tran ke
    
     inputMatrixFromFile(a,n);
     cout << "Ma tran ke "<< endl;
     output(a,n);
    DFS(0);
    output_DFS();

    BFS(0);
    output_BFS();
    // danh sach ke
    // inputList();
    // outputList();
    // init_Stack();
    // push(5);
    // push (7);
    // push(12);
    // process_Stack();
    // int v;
    // pop(v);
    // cout << v << endl;
    // process_Stack();

    return 0;
}


