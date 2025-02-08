// //Name:jay Shinde
// //Assignement 1

// #include <iostream>
// #include<string>
// using namespace std;
// class myset{
// public:
// 	int n;
// 	//int s[20];
// 	string s[20];
//  public:
// 	void readset();
// 	void display();
// 	void removedup();
// 	myset intersection(myset);
// 	myset unionn(myset);
// 	myset diff(myset);
	
// };
// void myset::removedup(){
	
// 	if (n <= 1) return;
//         int newSize = 1; 
        
//         for (int i = 1; i < n; i++) {
//             bool isDuplicate = false;
            
//             for (int j = 0; j < newSize; j++) {
//                 if (s[i] == s[j]) {
//                     isDuplicate = true;
//                     break;
//                 }
//             }

//             if (!isDuplicate) {
//                 s[newSize] = s[i];
//                 newSize++;
//             }
//         }
// 	n = newSize;
	
//         for (int i = 0; i < n; i++) {
//             cout << s[i] << " ";
//         }
//         cout << endl;   
        
        
// }
// void myset::readset(){
// 	cout<<"Enter Number of students:";
// 	cin>>n;
// 	cout<<"Enter Students Name:"<<endl;
// 	for(int i=0;i<n;i++){
// 		cin>>s[i];
// 	}
// }
// void myset::display(){
// 	cout<<"{";
// 	int temp=n-1;
	
// 	for(int i=0;i<n;i++){
// 		cout<<s[i];		
// 			if(i<n-1){
// 				cout<<",";
// 			}
// 	}
// 	cout<<"}"<<endl;
// 	cout<<endl;
// }



// myset myset::intersection(myset B){
//     myset C;  
//     int k = 0; 

//     for (int i = 0; i < n; i++) {  
//         for (int j = 0; j < B.n; j++) {  
//             if (s[i] == B.s[j]) {  
//                 C.s[k] = s[i];  
//                 k++;
//                 break;  
//             }
//         }
//     }
    
//     C.n = k;  
//    // C.display();
//     return C;  
    
// }

// myset myset::diff(myset B){
//     myset E;  
//     int k = 0; 
    
    
//      for (int i = 0; i < n; i++) {  
//      		 bool found = false;
//         for (int j = 0; j < B.n; j++) {  
//             if (s[i] == B.s[j]) {  
//                 found = true;
//                 break;  
//             }
//         }
//         if (!found) {
//             E.s[k] = s[i];
//             k++;
//         }
//     }
    
//     E.n = k;  
//     E.display();
//     return E;  
    
// }

// myset myset::unionn(myset B) {
//     myset D;
//     int k = 0;

//     for (int i = 0; i < n; i++) {
//         D.s[k] = s[i];
//         k++;
//     }
    
//     for (int i = 0; i < B.n; i++) {
//         bool f = false;
//         for (int j = 0; j < n; j++) {
//             if (s[j] == B.s[i]) {
//                 f = true;
//                 break;
//             }
//         }
//         if (!f) {
//             D.s[k] = B.s[i];
//             k++;
//         }
//     }

//     D.n = k;
//     //D.display();
//     return D;
// }

// int main()
// {
//     myset coding, project,master,paper;
    
//     cout << "coding contest:"<<endl;
//     coding.readset();
//     cout << "Students who participated  in coding contest:";
//     coding.display();
    
    
//     cout << "Project competition: "<<endl;
//     project.readset();
//     cout << "Students who participated in project competition: ";
//     project.display();
    
    
//     cout << "Master-mind competition: "<<endl;
//     master.readset();
//     cout << "Students who participated in Master-mind competition: ";
//     master.display();
    
//     cout << "Paper presentation competition: "<<endl;
//     paper.readset();
//     cout << "Students who participated in paper presentation competition: ";
//     paper.display();
    
//     cout<<endl;
//     cout<<endl;
    
    
//     cout << "Students who have participated in coding and project both are: ";
//     myset inter=coding.intersection(project);
//     inter.display(); 
    
//      cout << "Students who have participated in coding or project or both or Master-mind are: ";
//      myset res=coding.unionn(project);
//      myset res2= res.unionn(master);
//      res2.display();
    
//     cout<<"Students who have participated in coding but not in Master mind:";
//     coding.diff(master);
    
//     cout<<"Students who have participated in All:";
    
//      myset inter1=coding.intersection(project);
//      myset inter2=inter1.intersection(master);
//      myset inter3=inter2.intersection(paper); 
//      inter3.display();
    
     
// }

constexpr int divide(int a, int b) {
    return a / b;
}

int main() {
    constexpr int result = divide(10, 0); // Compile-time error!
    return 0;
}
