#include<bits/stdc++.h>
#include <unistd.h>
#include<filesystem>
using namespace std;
//using std::filesystem::current_path;
char choice;
typedef int T;
vector<Stack<T>>v(64);
void mainMenu();
void readMenu();
void printMenu();
void pushMenu();
void popMenu();
void topMenu();
void splitMenu();
void concatMenu();
void helpMenu();
void menu() {
    mainMenu();
    switch(choice) {
    case '0':
        readMenu();
        break;
    case '1':
        printMenu();
        break;
    case '2':
        pushMenu();
        break;
    case '3':
        popMenu();
        break;
    case '4':
        topMenu();
        break;
    case '5':
        splitMenu();
        break;
    case '6':
        concatMenu();
        break;
    case '7':
        exit(0);
        break;
    case '?':
        helpMenu();
        break;
    default:
        exit(0);
    }
    sleep(1);
    system("CLS");

}
void mainMenu() {
    cout<<"Main Menu\n";
    cout << "0 - Read stack\n";
    cout << "1 - Print stack\n";
    cout << "2 - Push element\n";
    cout << "3 - Pop element\n";
    cout << "4 - Top function\n";
    cout << "5 - Split function\n";
    cout << "6 - Concatenate function\n";
    cout << "7 - Exit program\n";
    cout<<"? - Help\n";
    cout << "Please choose: ";

   /// cout<<filePath<<'>';
    cin >> choice;

}
void readMenu() {
    cout<<"Select an index: ";
    unsigned int index;
    cin>>index;
    cin>>v[index];

}
void printMenu() {
    cout<<"Select an index: ";
    int index;
    cin>>index;
    cout<<v[index];
}
void pushMenu() {
    cout<<"Select an index: ";
    int index;
    cin>>index;
    cout<<"Select value:";
    T x;
    cin>>x;
    v[index].push(x);
};
void popMenu() {
    cout<<"Select an index: ";
    int index;
    cin>>index;
    v[index].pop();
};
void topMenu() {
    cout<<"Select an index: ";
    int index;
    cin>>index;
    cout<<v[index].top()<<'\n';
    changeColor(7);
};
void helpMenu() {
    changeColor(3);
    //2
    cout<<"The index represents the id of the specific Stack. The values ranging from 0 to 1023\n";
    cout<<"---------------------------Program made by Crismariu Denis---------------------------\n";
    changeColor(7);
};
void splitMenu() {};
void concatMenu() {};
