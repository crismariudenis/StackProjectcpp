/**
 *
 *  Denis isn't to be hold responsive
 *  for this mess of a file
**/
#include<bits/stdc++.h>
#include <unistd.h>
#include<filesystem>
#include <chrono>
#include <iomanip>
#include <WinUser.h>
using namespace std;
const unsigned int stacksNumber=64;
char pth[256];
typedef int T;
vector<Stack<T>>v(stacksNumber);
string filePath;
int cmdIndex=-1;
bool ok=true;
bool emptyLine=true;
void mainCMD();
void cdFunc(auto cmd);
void helpFunc(auto cmd);
void printFunc();
void dirFunc();
void readFunc();
void pushFunc();
void popFunc();
void topFunc();
void grassFunc();
void concatFunc();
void loadFunc(auto cmd);
struct elem
{
    string command;
    string details;
};
elem split(const string& s, char delimiter);
void initial()
{
    filePath=pth;
    cout<<"Microsoft Windows [Version 6.9.14206.1234]\n";
    cout<<"(c) Microsoft Corporation. All rights reserved.\n\n";
}
void menuCMD()
{
    while(ok)
        mainCMD();
}
string toLower(string s)
{
    for(char &c:s)
        c=tolower(c);
    return s;
}
void mainCMD()
{
    cout<<filePath;
    if(cmdIndex!=-1 )
        cout<<'\\'<<cmdIndex;
    cout<<'>';
    string s;
    getline(cin, s);
    auto cmd=split(s,' ');
    map<string,int>m=
    {
        {"cls",1},{"cd",2}, {"help",3},{"print",4},{"",69},
        {"exit",100},{"dir",5},{"push",6},{"pop",7},{"top",8}
        ,{"concat",9},{"read",10},{"touchgrass",699669},{"load",75}
    };
    switch(m[toLower(cmd.command)])
    {
    case 75://load
        loadFunc(cmd);
        break;
    case 10://read
        readFunc();
        break;
    case 6://push
        pushFunc();
        break;
    case 7://pop
        popFunc();
        break;
    case 8://top
        topFunc();
    case 9://concat
        concatFunc();
        break;
    case 699669:
        grassFunc();
        break;
    case 1://cls
        system("CLS");
        break;
    case 2://cd
        cdFunc(cmd);
        break;
    case 3:
        helpFunc(cmd);
        break;
    case 4:
        printFunc();
        break;
    case 5:
        dirFunc();
        break;
    case 100:
        ShowWindow(GetConsoleWindow(), SW_HIDE);//close cmd
        break;
    case 69:
        break;
    default:
        cout<<"'"<<cmd.command<<"'"<<" is not recognized as an internal or external command,\n";
        cout<<"operable program or batch file.\n";
    }
    cout<<'\n';
}
void loadFunc(auto x)
{
    ifstream fin;
    fin.open(x.details);
    if (fin.fail())
    {
        cout<<"The system cannot find the path specified.\n";
    }
    unsigned int n;
    fin>>n;
    for(int i=1; i<=n; i++)
    {
        int nr,index;
        fin>>nr>>index;
        for(int j=1; j<=nr; j++)
        {
            T e;
            fin>>e;
            v[index].push(e);
        }
    }
    fin.close();
}
void grassFunc()
{
    changeColor(10);
    while(true)
        MessageBox(NULL, "Grass couldn't be found !",
                   "Grass is undefined", MB_OK | MB_ICONEXCLAMATION | MB_SYSTEMMODAL);
    exit(45893) ;
}
void topFunc()
{
    if(cmdIndex!=-1)
        cout<<v[cmdIndex].top();
    else
        cout<<"The system cannot find the path specified.\n";
    changeColor(7);
}

void pushFunc()
{
    if(cmdIndex!=-1)
    {
        T x;
        cin>>x;
        v[cmdIndex].push(x);
    }
    else
        cout<<"The system cannot find the path specified.\n";
}
void concatFunc()
{
    if(cmdIndex!=-1)
    {
        unsigned int x;
        cin>>x;
        if(x<stacksNumber)
            v[cmdIndex]+=v[x];
        else
            cout<<"The system cannot find the path specified.\n";
    }
    else
        cout<<"The system cannot find the path specified.\n";
}
void printFunc()
{
    if(cmdIndex!=-1)
        cout<<v[cmdIndex];
    else
        cout<<"The system cannot find the path specified.\n";
}
int string_to_int(const string s)
{
    int ans=0;
    for(auto c:s)
    {
        if(c<'0' or c>'9')
            return -1;
        ans=ans*10+c-'0';
    }
    return ans;
}
void popFunc()
{
    if(cmdIndex!=-1)
        v[cmdIndex].pop();
    else
        cout<<"The system cannot find the path specified.\n";
}
void helpFunc(auto x)
{
    if(x.details=="")
    {
        cout<<"For more information on a specific command, type HELP command-name\n";
        cout<<"CD             "<<"Displays the name of or changes the current stack directory.\n";
        cout<<"CLS            "<<"Clears the screen.\n";
        cout<<"EXIT           "<<"Quits the CMD.EXE program (command interpreter).\n";
        cout<<"HELP           "<<"Provides Help information for Windows commands.\n";
        cout<<"DIR            "<<"Displays a list of stacks and elements in a directory.\n";
        cout<<"PUSH           "<<"Reads the values in the stack.\n";
        cout<<"POP            "<<"Remove the last element in the current directory.\n";
        cout<<"CONCAT         "<<"Concatenates another directory to the current one.\n";
        cout<<"LOAD           "<<"Loads stack from give file.\n";
        cout<<"TOUCHGRASS     "<<"-_-\n";
    }
    else
    {
        if(x.details=="cd")
        {
            cout<<"Displays the name of or changes the current directory.\n";
            cout<<"\n";
            cout<<"Type CD [] to display the current directory in the specified drive.\n";
            cout<<"Type CD [..] or [../] to leave the current directory.\n";
            cout<<"Type CD [path] with path to go to the specific directory.\n";
            cout<<"\n";
        }
        else if(x.details=="help")
        {
            cout<<"Provides help information for Windows commands.\n";
            cout<<"\n";
            cout<<"HELP [command]\n";
            cout<<"\n";
            cout<<"    command - displays help information on that command.\n";
        }
        else if(x.details=="cls")
        {
            cout << "Clears the screen.\n";
            cout << "\n";
            cout << "    CLS\n";
        }
        else if(x.details=="exit")
        {
            cout<<"Quits the CMD.EXE program (command interpreter) or the current batch\n";
            cout<<"script.\n";
            cout<<"\n";
            cout<<"EXIT [/B] [exitCode]\n";
            cout<<"\n";
            cout<<"  /B          specifies to exit the current batch script instead of\n";
            cout<<"              CMD.EXE.  If executed from outside a batch script, it\n";
            cout<<"              will quit CMD.EXE\n";
            cout<<"\n";
            cout<<"  exitCode    specifies a numeric number.  if /B is specified, sets\n";
            cout<<"              ERRORLEVEL that number.  If quitting CMD.EXE, sets the process\n";
            cout<<"              exit code with that number.\n";
        }
        else if(x.details=="dir")
        {
            cout<<"Displays a list of files and subdirectories in a directory.\n";
            cout<<"\n";
            cout<<"DIR [drive:][path][filename] [/A[[:]attributes]] [/B] [/C] [/D] [/L] [/N]\n";
            cout<<"[/O[[:]sortorder]] [/P] [/Q] [/R] [/S] [/T[[:]timefield]] [/W] [/X] [/4]\n";
        }
        else if(x.details=="read")
        {
            cout<<"Reads the values in the stack.\n";
            cout<<"\n";
            cout<<"READ [ENTER/][size] ...values\n";
        }
        else if(x.details=="push")
        {
            cout<<"Pushes the element at the top of the current directory.\n";
            cout<<"\n";
            cout<<"PUSH \n";
            cout<<"\n";
            cout<<"[X]\n";
        }
        else if(x.details=="pop")
        {
            cout<<"Removes the last element in the current directory.\n\n";
            cout<<"POP\n";
        }
        else if(x.details=="concat")
        {
            cout<<"Concatenates another directory to the current one.\n";
            cout<<"\n";
            cout<<"CONCAT\n";
            cout<<"[path]\n";
        }
        else if(x.details=="touchgrass")
        {
            cout<<"-_-\n";
        }
        else if(x.details=="load")
        {
            cout<<"Loads stack from give file.\n";
            cout<<"\n";
            cout<<"LOAD [/D] [drive:][path]\n";
        }
    }
}
void readFunc()
{
    if(cmdIndex==-1)
        cout<<"The system cannot find the path specified.\n";
    else
        cin>>v[cmdIndex];
}
void cdFunc(auto x)
{
    if(x.details=="")
    {
        cout<<filePath<<'\n';
        return;
    }
    int nr=string_to_int(x.details);
    if(x.details=="../" or x.details=="..")
        cmdIndex=-1;
    else if(nr!=-1 and cmdIndex==-1)
        cmdIndex=nr;
    else
        cout<<"The system cannot find the path specified.\n";
}
int lght(int n)
{
    int ans=0;
    while(n)
    {
        ans++;
        n/=10;
    }
    return ans;
}
void dirFunc()
{
    if(cmdIndex==-1)
    {
        auto time = std::time(nullptr);
        for(int i=0; i<stacksNumber-1; i++)
        {
            cout << put_time(localtime(&time), "%c") <<"    <DIR>";
            int sz=lght(v[i].size());
            if(sz==0)sz=1;
            for(int j=0;j<=4-sz;j++)
                cout<<" ";
            cout<<v[i].size()<<" Stack("<<i<<")\n";
        }
    }
    else
        cout<<v[cmdIndex];
}

elem split(const string& s, char delimiter)
{
    elem ans= {"",""};
    string token;
    istringstream tokenStream(s);
    while (getline(tokenStream, token, delimiter))
    {
        if(ans.command!="")
        {
            if(ans.details=="")
                ans.details=token;
            else
                ans.details+=" "+token;
        }
        else
            ans.command=token;
    }
    return ans;
}
