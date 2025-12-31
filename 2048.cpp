#include<iostream>
#include<ctime>
#include<cstdlib>
using namespace std;

int b[4][4];

void add(){
    int r,c;
    do{
        r=rand()%4;
        c=rand()%4;
    }
    while(b[r][c]!=0);
    b[r][c]=(rand()%2+1)*2;
}

void show(){
    cout<<"W=Up  A=Left  S=Down  D=Left"<<endl;
    for(int i=0;i<4;i++){
        for(int j=0;j<4;j++)
        cout<<(b[i][j] ? to_string(b[i][j]) : ".")<<"\t";
        cout<<endl;
    }
}

bool moveleft(){ 
    bool moved=false;
    for(int i=0;i<4;i++){
        int t[4]={0};
        int k=0;

        for(int j=0;j<4;j++){ 
            if(b[i][j]!=0){
                t[k]=b[i][j];
                k++;
            }
        }
        for(int j=0;j<3;j++){ 
            if(t[j]!=0 && t[j]==t[j+1]){
                t[j]=t[j]*2;
                t[j+1]=0;
                moved=true;
            }
        }
        int f[4]={0};
        k=0;
        for(int j=0;j<4;j++){
            if(t[j]!=0){
                f[k]=t[j];
                k++;
            }
        }
        for(int j=0;j<4;j++){
            if(b[i][j]!=f[j]){
                moved=true;
            }
            b[i][j]=f[j];
        }
    }
    return moved;
}
void rotate(){
    int t[4][4];

    for(int i=0;i<4;i++){
        for(int j=0;j<4;j++){
            t[j][3-i]=b[i][j]; 
        }
    }
    for(int i=0;i<4;i++){ 
        for(int j=0;j<4;j++){
            b[i][j]=t[i][j];
        }
    }
}

bool move(char c){
    bool m=false;

    if(c=='a'){
        m=moveleft();
    }
    if(c=='w'){
        rotate(); rotate(); rotate();
        m=moveleft();
        rotate();
    }
    if(c=='d'){
        rotate(); rotate();
        m=moveleft();
        rotate(); rotate();
    }
    if(c=='s'){
        rotate();
        m=moveleft();
        rotate(); rotate(); rotate();
    }
    return m;
}

bool gameover(){
    for(int i=0;i<4;i++){
        for(int j=0;j<4;j++){
            if(b[i]==0){
                return false;
            }
        }
    }
    for(int i=0;i<4;i++){
        for(int j=0;i<3;j++){
            if(b[i][j]==b[i][j+1] || b[j][i]==b[j+1][i]){
                return false;
            }
        }
    }
    return true;
}

int main(){
    srand(time(0));
    add();
    add();
    char c;
    cout<<"\nLet's Play 2048\n\n ";
    while(true){
        show();
        if(gameover()){
            cout<<" GAME OVER ";
            break;
        }
        cout<<"\nEnter your choice: ";
        cin>>c;
        cout<<"\n";
        if(move(c)){
            add();
        }
    }
}