#include <iostream>
#include <ctime>
#include <cstdlib>
#include <iomanip>
using namespace std;

    const int rows = 10;
    const int cols = 10;
    int max_ships = 10;
   int ship_grid_player[cols][rows];
   int ship_grid_computer[cols][rows];


   int ships_player = 10;
   int ships_computer = 10;

void Clear() {
for(int i = 0; i < rows; i++) {
    for(int j = 0; j < cols; j++) {
        ship_grid_player[i][j] = 0;
        //n++;
    }
}

}

void Draw() {
    int m = 0;
       int n = 0;
    cout << "   ";
    for(int i = 0; i < cols; i++) {
        cout << setw(2);
        cout << setfill(' ') << m <<  " ";
        m++;
    }
    cout << endl;
for(int i = 0; i < rows; i++) {
        cout << n << "  ";
        n++;
    for(int j = 0; j < cols; j++) {


      cout <<  setfill('0') << setw(2) << ship_grid_player[i][j] << " ";

    }

    cout << endl;
}

}

void Draw_grid() {
    int m = 0;
       int n = 0;
    cout << "   ";
     for(int i = 0; i < cols; i++) {
        cout << setw(2);
        cout << setfill(' ') << m <<  " ";
        m++;
    }
    cout << endl;
for(int i = 0; i < rows; i++) {
        cout << n << "  ";
        n++;
    for(int j = 0; j < cols; j++) {
     if(ship_grid_player[i][j] != 0) {
        ship_grid_computer[i][j] = ship_grid_player[i][j];
     }
      cout << setfill('0') << setw(2) << ship_grid_computer[i][j] << " ";
    }
    cout << endl;
}

}



void SetShips_Player() {
int j = 0;
int z;
while(j < max_ships) {
        cout << "Place your ship: ";
        cin >> z;

if(z > 99 || z < 0) {
        while(z > 99 || z < 0) {
    cout << "Invalid number. Place your ship: ";
    cin >> z;
    }
    }

if(cin.fail()) {
   cout << "Error" << endl;
   break;
}
    int a = z/10;
   int b = z % 10;
    ship_grid_player[a][b] = 1;
    j++;

}

}

void SetShips_Computer() {
int j = 0;
int z;
while(j < max_ships) {
z = rand() % 100;
int a = z/10;
int b = z % 10;

if(ship_grid_player[a][b] != 1 && ship_grid_computer[a][b]!=2) {
    ship_grid_computer[a][b] = 2;

j++;
}
         }


}

void player_Attack() {
int z;
cout << "Choose position to attack!" << endl;
cin >> z;
if(z > 99 || z < 0) {
        while(z > 99 || z < 0) {
    cout << "Invalid number. Place your ship: ";
    cin >> z;
    }
    }
int a = z/10;
int b = z % 10;
if(ship_grid_computer[a][b] == 2) {
    cout << "Congratulations you hit enemy's ship!" << endl;
    ships_computer--;
    cout << "Now they have " << ships_computer << " ships left." << endl;
    ship_grid_computer[a][b] = -2;
    ship_grid_player[a][b] = -2;
}

else if(ship_grid_player[a][b] == 1) {
    cout << "If you do that you are going to destroy your own ship! Do you want to do that?" << endl;
    char y_n;
    cin >> y_n;
    if(y_n == 'y') {
        ship_grid_player[a][b] = -1;
        ship_grid_computer[a][b] = -1;
        cout << "Your ship was destroyed!" << endl;
    }

    else {
            player_Attack();
      /*& cin >> z;
if(z > 99 || z < 0) {
        while(ship_grid_player[a][b] = 1 || z > 99 || z < 0) {
    cout << "Invalid number. Place your ship: ";
    cin >> z;
    }
    } */
    }
}
else {cout << "Bad luck, you missed the target, next time aim better!" << endl;
ship_grid_computer[a][b] = 7;
ship_grid_player[a][b] = 7;
}

if(ships_computer == 0) {
    cout  << "Congratulations you won the game!" << endl;
}


}








void computer_Attack() {
int z;
z = rand() % 100;
int a = z/10;
int b = z % 10;


bool comp = true;
if(ship_grid_computer[a][b] == 3 ||  ship_grid_computer[a][b] == 2 || ship_grid_computer[a][b] == -2 || ship_grid_player[a][b] == 7 || ship_grid_player[a][b] == -1) {
    comp = true;
}
else {
        comp = false;
cout << "The enemy choose " << z << " position to attack.";

if(ship_grid_player[a][b] == 1) {
    cout << "Unfortunately your ship was hit!" << endl;
    ships_player--;
    cout << "Now you have " << ships_player << " ships left." << endl;
    ship_grid_player[a][b] = -1;
    ship_grid_computer[a][b] = -1;

}

else {
    cout << "They could not hit your ship!" << endl;
    ship_grid_player[a][b] = 3;
    ship_grid_computer[a][b] = 3;
}
cout << "Do you want to surrender(y/n)?" << endl;
char y_n;
cin >> y_n;
if(y_n == 'y') {
    ships_player = 0;
}

if(ships_player == 0) {
    cout << "Game Over!" << endl;
}

}
//while(ship_grid_computer[a][b] = 6 ||  ship_grid_computer[a][b] = 2 || ship_grid_computer[a][b] = -2 || ship_grid_player[a][b] = 9 || ship_grid_player[a][b] = -1) {
while(comp = true) {
z = rand() % 100;
int a = z/10;
int b = z % 10;

if(ship_grid_computer[a][b] == 3 ||  ship_grid_computer[a][b] == 2 || ship_grid_computer[a][b] == -2 || ship_grid_player[a][b] == 7 || ship_grid_player[a][b] == -1) {
    comp = true;
}
else {comp = false;
break;
cout << "The enemy choose " << z << " position to attack.";

if(ship_grid_player[a][b] == 1) {
    cout << "Unfortunately your ship was hit!" << endl;
    ships_player--;
    cout << "Now you have " << ships_player << " ships left." << endl;
    ship_grid_player[a][b] = -1;
    ship_grid_computer[a][b] = -1;

}

else {
    cout << "They could not hit your ship!" << endl;
    ship_grid_player[a][b] = 3;
    ship_grid_computer[a][b] = 3;
}
cout << "Do you want to surrender(y/n)?" << endl;
char y_n;
cin >> y_n;
if(y_n == 'y') {
    ships_player = 0;
}

if(ships_player == 0) {
    cout << "Game Over!" << endl;
}

}

cout << "The enemy choose " << z << " position to attack.";

if(ship_grid_player[a][b] == 1) {
    cout << "Unfortunately your ship was hit!" << endl;
    ships_player--;
    cout << "Now you have " << ships_player << " ships left." << endl;
    ship_grid_player[a][b] = -1;
    ship_grid_computer[a][b] = -1;

}

else {
    cout << "They could not hit your ship!" << endl;
    ship_grid_player[a][b] = 3;
    ship_grid_computer[a][b] = 3;
}
cout << "Do you want to surrender(y/n)?" << endl;
char y_n;
cin >> y_n;
if(y_n == 'y') {
    ships_player = 0;
}

if(ships_player == 0) {
    cout << "Game Over!" << endl;
}



}

}


int main()
{
srand(time(0));
   Clear();
   Draw();
   SetShips_Player();
   SetShips_Computer();
   while(ships_player > 0 && ships_computer > 0) {
   Draw();
   player_Attack();
   computer_Attack();
   }
   cout << "___________________" << endl;
   Draw_grid();
    return 0;
}
