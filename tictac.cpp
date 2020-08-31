#include <cstdlib>

#include <ctime>

#include <iostream>

using namespace std;
void print_matrix(int);
void print_com(int);
int check(int);
int win();
void random();
char a[3][3] = {
  ' ',
  ' ',
  ' ',
  ' ',
  ' ',
  ' ',
  ' ',
  ' ',
  ' '
};
int x, randomnum;

int main() {
  x = 0;
  print_matrix(x);
  cout << "\n\n";
  cin >> x;
  cout << endl << endl;
  print_matrix(x);
  for (int i = 0; i < 4; i++) {
    random();
    win();
    cin >> x;
    cout << endl << endl;
    print_matrix(x);
    win();
  }
}

void print_matrix(int x) {
  if (x == 0) {
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
  } else {
    switch (x) {
    case 7:
      a[0][0] = 'X';
      break;
    case 8:
      a[0][1] = 'X';
      break;
    case 9:
      a[0][2] = 'X';
      break;
    case 4:
      a[1][0] = 'X';
      break;
    case 5:
      a[1][1] = 'X';
      break;
    case 6:
      a[1][2] = 'X';
      break;
    case 1:
      a[2][0] = 'X';
      break;
    case 2:
      a[2][1] = 'X';
      break;
    case 3:
      a[2][2] = 'X';
      break;

    }
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
    cout << endl << endl << "-----------------------------" << endl << endl;
  }
}

void print_com(int x) {
  switch (x) {
  case 7:
    a[0][0] = 'O';
    break;
  case 8:
    a[0][1] = 'O';
    break;
  case 9:
    a[0][2] = 'O';
    break;
  case 4:
    a[1][0] = 'O';
    break;
  case 5:
    a[1][1] = 'O';
    break;
  case 6:
    a[1][2] = 'O';
    break;
  case 1:
    a[2][0] = 'O';
    break;
  case 2:
    a[2][1] = 'O';
    break;
  case 3:
    a[2][2] = 'O';
    break;

  }
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
  cout << endl << endl << "-----------------------------" << endl << endl;
}

int check(int x) {
  switch (x) {
  case 7:
    if ((a[0][0]) == ' ')
      return 0;
    else return 1;
    //  break;
  case 8:
    if ((a[0][1]) == ' ')
      return 0;
    else return 1;
    // break;
  case 9:
    if ((a[0][2]) == ' ')
      return 0;
    else return 1;
    // break;
  case 4:
    if ((a[1][0]) == ' ')
      return 0;
    else return 1;
    // break;
  case 5:
    if ((a[1][1]) == ' ')
      return 0;
    else return 1;
    // break;
  case 6:
    if ((a[1][2]) == ' ')
      return 0;
    else return 1;
    // break;
  case 1:
    if ((a[2][0]) == ' ')
      return 0;
    else return 1;
    //break;
  case 2:
    if ((a[2][1]) == ' ')
      return 0;
    else return 1;
    // break;
  case 3:
    if ((a[2][2]) == ' ')
      return 0;
    else return 1;
    // break;

  }
}

void random() {
  int c;
  srand((unsigned) time(0));
  do {
    randomnum = (1 + rand() % 9);
    c = check(randomnum);
  } while (c != 0);
  print_com(randomnum);
}

int win() {

  if ((a[0][2] == a[1][1]) && (a[1][1] == a[2][0]) && ((a[0][2] == 'X') || (a[0][2] == 'O'))) {
    cout << endl << endl;
    if ((a[0][2]) == 'X')
      cout << "CONGRATULATIONS!!! YOU WIN";
    else if ((a[0][2]) == 'O')
      cout << "SORRY!!! YOU LOST";
    exit(0);

  }

  if ((a[0][0] == a[1][1]) && (a[1][1] == a[2][2]) && ((a[0][0] == 'X') || (a[0][0] == 'O'))) {
    cout << endl << endl;
    if ((a[0][0]) == 'X')
      cout << "CONGRATULATIONS!!! YOU WIN";
    else if ((a[0][0]) == 'O')
      cout << "SORRY!!! YOU LOST";
    exit(0);
  }
  for (int i = 0; i < 4; i++) {
    int acountx = 0, acounty = 0, bcountx = 0, bcounty = 0;
    for (int j = 0; j < 4; j++) {

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
      cout << endl << endl;
      cout << "CONGRATULATIONS!!! YOU WIN";
      exit(0);
    }
    if (acounty == 3 || bcounty == 3) {
      cout << endl << endl;
      cout << "SORRY!!! YOU LOST";
      exit(0);
    }
  }

}
