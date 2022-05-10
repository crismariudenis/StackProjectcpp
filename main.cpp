#include<bits/stdc++.h>
#include "Stack.h"
#include "CmdMenu.h"
#include <unistd.h> // for sleep()
using namespace std;

int main()
{
    getcwd(pth,256);
    initial();
    menuCMD();

    return 0;
}
void generateFileInfo()
{
    ofstream fout;
    fout.open("Stack.in");
    srand(time(NULL));
    int n=rand()%10+1;
    fout<<n<<'\n';
    for(int i=1;i<=n;i++)
    {
        int nr=rand()%10+1;
        int index=rand()%stacksNumber;
        fout<<nr<<" "<<index<<'\n';
        for(int j=1;j<=nr;j++){
            int x=rand()%1490324+1;
            if(rand()%6==1)
                x=-x;
            fout<<x<<" ";
        }
        fout<<'\n';
    }
}
