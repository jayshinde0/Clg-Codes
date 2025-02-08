#include<iostream>
using namespace std;

class sorting{
    public:
    int a[100];
    int n;
    
    public:
    void read();
    void display();
    void bubble();
    void quick(int low, int high);
    int partition(int low, int high);
    void selection();
};

void sorting::read(){
    cout << "Enter Number of elements: ";
    cin >> n;
    for(int i = 0; i < n; i++){
        a[i] = rand() % 100;
    }
}

void sorting::display(){
    cout << "Array elements: " << endl;
    for(int i = 0; i < n; i++){
        cout << a[i] << "\t";
    }
    cout << endl;
}

void sorting::bubble(){
    for(int i = 0; i < n-1; i++){
        for(int j = 0; j < n-i-1; j++){
            if(a[j] > a[j+1]){
                int temp = a[j];
                a[j] = a[j+1];
                a[j+1] = temp;
            }
        }
        cout << "Pass " << i+1 << endl;
        display();
    }
}
int sorting::partition(int low, int high){
    int pivot = a[low];  
    int i = low;         
    
  
    for(int j = low + 1; j <= high; j++){
        if(a[j] <= pivot){ 
            i++;  
            int temp = a[i];
            a[i] = a[j];
            a[j] = temp;
        }
    }

    
    int temp = a[low];  
    a[low] = a[i];
    a[i] = temp;

    
    return i;
}

void sorting::quick(int low, int high){
    if(low < high){
        int pi = partition(low, high);  
        quick(low, pi - 1);
        quick(pi + 1, high);
    }
}


void sorting::selection(){
    for(int i = 0; i < n-1; i++){
        int min = i;
        for(int j = i + 1; j < n; j++){
            if(a[j] < a[min]){
                min = j;  
            }
        }
      
        int temp = a[min];
        a[min] = a[i];
        a[i] = temp;

        cout << "Pass " << i+1 << endl;
        display();
    }
}

int main(){
    sorting s;
    s.read();
    s.display();
    
    cout << "Performing Quick Sort:" << endl;
    s.quick(0, s.n-1);
    
    //cout << "Performing Selection Sort:" << endl;
    //s.selection();
    s.display();
    
    return 0;
}
