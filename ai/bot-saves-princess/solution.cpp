#include <iostream>
#include <vector>
#include <cmath>
using namespace std;
void displayPathtoPrincess(int n, vector <string> grid){

  int xPos = 0;
  int yPos = 0;

  vector<int> mPos;
  vector<int> pPos;

  bool foundM = false;
  bool foundP = false;

  //parse rows
  for(string s : grid)
  {
    //parse columns of row
    for(int x = 0; x < n; x++){
      if(s[x] != '-')
      {
        //found m, store position
        if(s[x] == 'm')
        {
          mPos.push_back(yPos);
          mPos.push_back(x);
          foundM = true;
        }
        //found p, store position
        if(s[x] == 'p')
        {
          pPos.push_back(yPos);
          pPos.push_back(x);
          foundP = true;
        }
      }
    }
    //no more parsing, we've found what we wanted
    if(foundM == true && foundP == true){
      break;
    }

    //already add an UP or DOWN to the moves?


    //increase rowcount
    yPos++;
  }

  //decide moves
  vector<string> moves;

  int y = mPos[0] - pPos[0];
  int x = mPos[1] - pPos[1];

  string up = "UP";
  string down = "DOWN";
  string left = "LEFT";
  string right = "RIGHT";

  //up or down?
  string direction;
  if(y != 0)
  {
    if(y > 0)
    {
      direction = up;
    } else {
      direction = down;
    }

    for(int vertical = abs(y); vertical > 0; vertical--){
      moves.push_back(direction);
    }
  }

  if(x != 0)
  {
    if(x < 0)
    {
      direction = right;
    } else {
      direction = left;
    }

    for(int horizontal = abs(x); horizontal > 0; horizontal--){
      moves.push_back(direction);
    }
  }


  //print moves
  for(auto i : moves)
  {
    cout << i << endl;
  }

}
int main(void) {

  int m;
  vector <string> grid;

  cin >> m;

  for(int i=0; i<m; i++) {
    string s; cin >> s;
    grid.push_back(s);
  }

  displayPathtoPrincess(m,grid);

  return 0;
}
