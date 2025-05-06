#include <iostream>  
#include <cmath>  
using namespace std;  
#define max1 20  
class stud {  
public:  
int marks[max1], total;  
stud() {  
total = 0;  
for (int i = 0; i < max1; i++)  
marks[i] = 0;  
} 
void createHeap();  
void displayHeap();  
void showmax();  
void showmin();  
}; 
void stud::createHeap() {  
int i, j, par, temp, M;  
cout << "\nEnter how many students: ";  
cin >> total;  
for (i = 0; i < total; i++) {  
cout << "Enter Marks: ";  
cin >> marks[i];  
M = marks[i];  
j = i; 
par = floor((j - 1) / 2); 
while (j != 0 && marks[j] < marks[par]) {  
temp = marks[j];  
marks[j] = marks[par];  
marks[par] = temp;  
j = par; 
par = floor((j - 1) / 2); 
} 
cout << "\nCurrent Heap after inserting " << M << ":\n";  
displayHeap();  
} 
} 
void stud::displayHeap() {  
int i = 0, space = 6;  
cout << endl;  
while (i < total) {  
if (i == 0 || i == 1 || i == 3 || i == 7 || i == 15) {  
cout << endl << endl;  
for (int j = 0; j < space; j++)  
cout << " ";  
space -= 2;  
} 
cout << " " << marks[i];  
i++;  
} 
cout << endl << endl;  
} 
void stud::showmin() {  
cout << "Min Marks (Root of Min-Heap): " << marks[0] << endl;  
} 
void stud::showmax() {  
int max = marks[0];  
for (int i = 1; i < total; i++) {  
if (max < marks[i])  
max = marks[i];  
} 
cout << "Max Marks: " << max << endl;  
} 
int main() {  
stud s1;  
int ch, ans;  
do {  
cout << "\n1. Insert Marks";  
cout << "\n2. Display Heap";  
cout << "\n3. Show Max Marks";  
cout << "\n4. Show Min Marks";  
cout << "\n\nEnter your choice: ";  
cin >> ch;  
switch (ch) {  
case 1:  
s1.createHeap();  
break;  
case 2:  
s1.displayHeap();  
break;  
case 3:  
s1.showmax();  
break;  
case 4:  
s1.showmin();  
break;  
default:  
cout << "Invalid choice.\n";  
} 
cout << "\nDo you want to continue? (1 for Yes): ";  
cin >> ans;  
} while (ans == 1);  
return 0;  
} 
