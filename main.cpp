#include <cstdlib>
#include <iostream>

using namespace std;

int rules(int user, int com);
void putaran(int &n);
int main (int argc, char *argv[]) {
  int n;
  cout<<"\nSelamat datang di permainan batu, kertas, gunting!"<<endl; 
  cout<<"\nMasukan jumlah putaran : ";
  cin >>n;
  putaran(n);
  return 0;
}
void putaran(int &n){
  int user,com;
  for(int i=0; i<n;i++){
    cout<<"Input 1 = batu, 2 = kertas, 3 = gunting\n > ";
    cin>>user;
    if(user>3||user<1){
      cout<<"Input yang kamu masukan salah cuy!"<<endl;
      i--;
      continue;
    }
    com = (rand()%3)+1;
    
    switch (rules(user, com)) {
      case 0: cout << "Kamu kalah :("<<endl;
              break;
      case 1: cout << "Kamu menang :)"<<endl;
              break;
      case 2: cout << "Hasil seri :|"<<endl;
              break;
    };
    cout<<endl;
  }
}
int rules(int user, int com){
  int result;
  /* result
   * 0 = user lose
   * 1 = user win
   * 2 = draw
   */
  if(user==1){ //user choose rock
    cout<<"Kamu: batu vs ";
    switch (com) {
      case 1: cout<<"Komputer: batu"; result = 2;
              break;
      case 2: cout<<"Komputer: kertas"; result = 0;
              break;
      case 3: cout<<"Komputer: gunting"; result = 1;
              break;
    }
  }
  else if (user==2) { //user choose paper
     cout<<"Kamu: kertas vs ";
     switch (com) {        
       case 1: cout<<"Komputer: batu"; result = 1;
               break;
       case 2: cout<<"Komputer: kertas"; result = 2;
               break;
       case 3: cout<<"Komputer: gunting"; result = 0;
               break;
     }
  }
  else if (user==3) { //user choose scissor
    cout<<"Kamu: gunting vs ";
    switch (com) {           
      case 1: cout<<"Komputer: batu"; result = 0;
              break;
      case 2: cout<<"Komputer: kertas"; result = 1;
              break;
      case 3: cout<<"Komputer: gunting"; result = 2;
              break;
    }
  }
  cout<<endl;
  return result;
}
