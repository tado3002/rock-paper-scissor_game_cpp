#include <cstdlib>
#include <iostream>
#include <vector>

using namespace std;

struct game{
  int round;
  int com;
  int user;
  int result;
};

string rspWord(int &input);
string resultString(int &result);
int rules(int user, int com);
vector<game> history;
void putaran(int &n);
int main () {
  int n;
  cout<<"\nSelamat datang di permainan batu, kertas, gunting!"<<endl; 
  cout<<"\nMasukan jumlah putaran : ";
  cin >>n;
  putaran(n);

  system("clear");
  cout << "\nHistory Pertandingan\n"<<endl;
  cout << "ronde\tkamu\tkomputer\thasil\t" << endl;

  for(game &RSP: history){
    cout << RSP.round << "\t";
    cout << rspWord(RSP.user) << "\t";
    cout << rspWord(RSP.com) << "\t";
    cout << resultString(RSP.result) << "\t";
    cout << endl;
  }

  cout<<endl;

  return 0;
}


void putaran(int &n){
  //init struct game
  game RSP;
  int user,com;
  for(int i=0; i<n;i++){
    int result;
    cout<<"Input 1 = batu, 2 = kertas, 3 = gunting\n > ";
    cin>>user;
    if(user>3||user<1){
      cout<<"Input yang kamu masukan salah cuy!"<<endl;
      i--;
      continue;
    }

    com = (rand()%3)+1;
    result = rules(user, com);

    //add prop to game
    RSP.round = i+1;
    RSP.user = user;
    RSP.com = com;
    RSP.result = result;

    history.push_back(RSP);

    string resultWord = resultString(result);

    switch (result) {
      case 0: cout << "Kamu "<< resultWord <<" :("<<endl;
              break;
      case 1: cout << "Kamu "<< resultWord <<" :)"<<endl;
              break;
      case 2: cout << "Hasil "<< resultWord<<" :|"<<endl;
              break;
    };
    cout<<"\n--------------------------------------"<<endl;
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

string rspWord(int &input){
  string word;
  switch (input) {
    case 1: word = "batu";
            break;
    case 2: word = "kertas";
            break;
    case 3: word = "gunting";
            break;
  }
  return word;
}

string resultString(int &result){
  string word;
  switch (result) {
    case 0: word = "kalah";
            break;
    case 1: word = "menang";
            break;
    case 2: word = "seri";
            break;
  }
  return word;
}
