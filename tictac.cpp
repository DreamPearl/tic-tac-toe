#include <cstdlib>

#include <ctime>

#include <iostream>

using namespace std;
void assign_matrix(int, char);
void print_matrix();
int check(int);
int win();
int random();
void start_singlematch();
int take_input();
void clear_matrix();
char a[3][3];

int main() {

  char con;
  do {
    start_singlematch();
    cout << "Do you want to continue? (Y/N)\n";
    cin >> con;
  } while (con == 'Y' || con == 'y');
  exit(0);
}

void start_singlematch()

{
  char y;
  int x = 0;
  int in ;
  clear_matrix();
  while (1) {
    cout << "Press 1 for single player and press 2 for multi player(2 player).\n";
    cin >> in ;
    if ( in == 1 || in == 2)
      break;
    cout << "Wrong input !!! Please select either 1 or 2.\n";
  }
  print_matrix();
  cout << "\n\n";
  int n;
  for (int i = 0; i < 9; i++) {
    int n = 2;
    if (i % 2 != 0) {
      if ( in == 1)
        x = random();
      else if ( in == 2) {
        x = take_input();
      }
      y = 'O';
    } else {
      x = take_input();
      y = 'X';
    }
    assign_matrix(x, y);
    print_matrix();
    n = win();
    cout << "\n" << "\n";
    if (n == 1) {
      cout << "CONGRATULATIONS!!! Player 1 (X) wins!!!";
      cout << "\n" << "\n";
      return;
    } else if (n == 0) {
      if ( in == 1) {

        cout << "SORRY!!! YOU LOST";
        cout << "\n" << "\n";
      } else {
        cout << "CONGRATULATIONS!!! Player 2 (O) wins!!!";
        cout << "\n" << "\n";
      }
      return;

    }

  }
  cout << "JAO GHAR MATCH DRAW!!\n\n";
}

int take_input() {
  int c1, x;
  do {
    cin >> x;
    c1 = check(x);
    if (c1 != 0)
      cout << "Please type a vacant place number!!!";
  } while (c1 != 0);
  return x;
}

void assign_matrix(int x, char m) {
  switch (x) {
  case 7:
    a[0][0] = m;
    break;
  case 8:
    a[0][1] = m;
    break;
  case 9:
    a[0][2] = m;
    break;
  case 4:
    a[1][0] = m;
    break;
  case 5:
    a[1][1] = m;
    break;
  case 6:
    a[1][2] = m;
    break;
  case 1:
    a[2][0] = m;
    break;
  case 2:
    a[2][1] = m;
    break;
  case 3:
    a[2][2] = m;
    break;
  }

}
void clear_matrix() {
  for (int i = 0; i < 3; i++) {
    for (int j = 0; j < 3; j++) {
      a[i][j] = ' ';
    }

  }
}

void print_matrix() {
  system("cls");
  for (int i = 0; i < 3; i++) {
    for (int j = 0; j < 3; j++) {
      {
        cout << a[i][j];
        if (j < 2)
          cout << "|";
      }
    }
    if (i < 2)
      cout << "\n-----\n";
  }

}

int check(int x) {
  switch (x) {
  case 7:
    if ((a[0][0]) == ' ')
      return 0;
    else return 1;

  case 8:
    if ((a[0][1]) == ' ')
      return 0;
    else return 1;

  case 9:
    if ((a[0][2]) == ' ')
      return 0;
    else return 1;

  case 4:
    if ((a[1][0]) == ' ')
      return 0;
    else return 1;

  case 5:
    if ((a[1][1]) == ' ')
      return 0;
    else return 1;

  case 6:
    if ((a[1][2]) == ' ')
      return 0;
    else return 1;

  case 1:
    if ((a[2][0]) == ' ')
      return 0;
    else return 1;

  case 2:
    if ((a[2][1]) == ' ')
      return 0;
    else return 1;

  case 3:
    if ((a[2][2]) == ' ')
      return 0;
    else return 1;

  }
}

int random() {
  int c, randomnum;
  srand((unsigned) time(0));
  do {
    randomnum = (1 + rand() % 9);
    c = check(randomnum);
  } while (c != 0);
  return randomnum;
}

int win() {

  if ((a[0][2] == a[1][1]) && (a[1][1] == a[2][0]) && ((a[0][2] == 'X') || (a[0][2] == 'O'))) {
    if ((a[0][2]) == 'X')
      return 1;
    else if ((a[0][2]) == 'O')
      return 0;
  }

  if ((a[0][0] == a[1][1]) && (a[1][1] == a[2][2]) && ((a[0][0] == 'X') || (a[0][0] == 'O'))) {
    if ((a[0][0]) == 'X')
      return 1;
    else if ((a[0][0]) == 'O')
      return 0;

  }
  for (int i = 0; i < 3; i++) {
    int acountx = 0, acounty = 0, bcountx = 0, bcounty = 0;
    for (int j = 0; j < 3; j++) {

      if ((a[i][j]) == 'X')
        acountx++;
      if ((a[i][j]) == 'O')
        acounty++;

      if ((a[j][i]) == 'X')
        bcountx++;
      if ((a[j][i]) == 'O')
        bcounty++;

    }
    if (acountx == 3 || bcountx == 3)

    {
      return 1;

    }
    if (acounty == 3 || bcounty == 3) {
      return 0;

    }

  }
  return 2;

}
