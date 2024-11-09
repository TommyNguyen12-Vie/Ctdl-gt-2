#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;


int fibonacciCount = 0;
int insertionSortCount = 0;
int heapSortCount = 0;
int quickSortCount = 0;
void printArray(int arr[], int size) {
	for (int i = 0; i < size; i++) {
		cout << arr[i] << " ";
	}
	cout << endl;
}


void insertionSort(int arr[], int n)
{
	int i, key, j;
	for (i = 1; i < n; i++)
	{
		key = arr[i];
		j = i - 1;

		
		while (j >= 0 && arr[j] > key)
		{
			insertionSortCount++;
			arr[j + 1] = arr[j];
			j = j - 1;
		}
		arr[j + 1] = key;
		printArray(arr,n);
	}
}




void quickSort(int arr[], int low, int high) {
	if (low < high) {
		int pivot = arr[high];
		int i = low - 1;

		for (int j = low; j < high; j++) {
			quickSortCount++;
			if (arr[j] < pivot) {
				i++;
				swap(arr[i], arr[j]);
				printArray(arr, high + 1); // print sao moi lan hoan doi
			}
		}
		swap(arr[i + 1], arr[high]);
		printArray(arr, high + 1); // in mang sau khi hoan doi voi phan tu chot (pivot)
		quickSort(arr, low, i);
		quickSort(arr, i + 2, high);
	}
}

void heapify(int arr[], int n, int i) {
	int largest = i;
	int left = 2 * i + 1;
	int right = 2 * i + 2;

	if (left < n && arr[left] > arr[largest]) {
		largest = left;
	}
	if (right < n && arr[right] > arr[largest]) {
		largest = right;
	}

	if (largest != i) {
		swap(arr[i], arr[largest]);
		heapSortCount++;
		printArray(arr,n); // in mang sau moi lan hoan doi 
		heapify(arr, n, largest);
	}
}

void heapSort(int arr[], int n) {
	for (int i = n / 2 - 1; i >= 0; i--) {
		heapify(arr, n, i);
	}

	for (int i = n - 1; i > 0; i--) {
		swap(arr[0], arr[i]);
		heapSortCount++;
		printArray(arr,n); // in mang sau moi lan hoan doi 
		heapify(arr, i, 0);
	}
}

int fibonacci(int n) {
    // TH dac biet
    if (n == 0) return 0;
    if (n == 1) return 1;
    
    int a = 0, b = 1, c;
    
    for (int i = 2; i <= n; i++) {
        c = a + b;  //Fibonacci tiep theo
        a = b;  // Di chuyen a thanh b
        b = c;  // Di chuyen b thanh c
    }
    
    return b;  // Tra ve fibonacci (n)
}




int main() {
	int choice, inputChoice;
	int n;
	int arr[100];

	cout << "Nhap so phan tu cua mang: ";
	cin >> n;

	// them lua chon nhap mang bang manual
	cout <<"Ban muon nhap Manual (1) hay Automatic (2) " << endl;
	cin >> inputChoice;

	if(inputChoice == 1){
		cout <<"Nhap cac phan tu cua mang: "<< endl;
		for(int i =0; i < n; i++){
			cin >> arr[i];
		}
	}
	
	else if(inputChoice == 2){
		srand(time(0));
	for (int i = 0; i < n; i++) {
		arr[i] = rand() % 100 + 1;
	}


	cout << "Mang ngau nhien: tu 1 -> 100 ";
	printArray(arr, n);

	}
	else {
		cout <<"Lua chon cua ban khong hop le!!!! "<< endl;
	}
	
	do {
		
		cout <<"=======MeNu=======" << endl
			<< "1.InsertionSort" << endl
			<< "2.QuickSort" << endl
			<< "3.HeapSort" << endl
			<< "4.Fibonacci"<< endl
			<< "0. Thoat chuong trinh" << endl;
		cout << "Nhap lua chon: " << endl;
		cin >> choice;

		switch (choice) {
		case 1: {
			int arrCopy1[100];
			for (int i = 0; i < n; i++) {
				arrCopy1[i] = arr[i];
			}
			insertionSortCount = 0;
			insertionSort(arrCopy1, n);
			cout << "Mang sau khi da sap xep " << endl;
			printArray(arrCopy1, n);
			cout << "Tong so lan thuc hien trong insertionSort: " << insertionSortCount << endl;
			break;
		}


		case 2: {
			cout << "Lua chon quickSort" << endl;
	
			int arrCopy2[100];
			for (int i = 0; i < n; i++) {
				arrCopy2[i] = arr[i];
			}
			quickSortCount = 0;
			quickSort(arrCopy2, 0, n - 1);
			cout << "Mang sau khi sap xep: " << endl;
			printArray(arrCopy2, n);
			cout << "Tong so lan thuc hien trong QuickSort: " << quickSortCount << endl;
			break;
		}
		case 3: {
			cout << "Lua chon heapsort" << endl;
			
			int arrCopy3[100];
			for (int i = 0; i < n; i++) {
				arrCopy3[i] = arr[i];
			}
			heapSortCount = 0;
			heapSort(arrCopy3, n);
			cout << "Mang sau khi sap xep: " << endl;
			printArray(arrCopy3, n);
			cout << "Tong so lan thuc hien trong HeapSort: " << heapSortCount << endl;
			break;
		}
		case 4: {
			int n;
    		cout << "Nhap so phan tu cua day Fibonacci: ";
    		cin >> n;

    		cout << "Day Fibonacci: ";
    		for (int i = 0; i < n; i++) {
        	cout << fibonacci(i) << " ";
   				 }
    		cout << endl;
			break;
			
		}
		case 0:
			cout << "Cam on ban da su dung chuong trinh" << endl;
			break;
		default:
			cout << "Lua chon khong hop le. Vui long chon lai." << endl;
			break;
		}
	} while (choice != 0);

	return 0;
}