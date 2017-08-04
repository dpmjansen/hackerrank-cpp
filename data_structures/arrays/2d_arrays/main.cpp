#include <map>
#include <set>
#include <list>
#include <cmath>
#include <ctime>
#include <deque>
#include <queue>
#include <stack>
#include <string>
#include <bitset>
#include <cstdio>
#include <limits>
#include <vector>
#include <climits>
#include <cstring>
#include <cstdlib>
#include <fstream>
#include <numeric>
#include <sstream>
#include <iostream>
#include <algorithm>
#include <unordered_map>

using namespace std;

int main(){
    vector< vector<int> > arr(6,vector<int>(6));
    for(int arr_i = 0;arr_i < 6;arr_i++){
       for(int arr_j = 0;arr_j < 6;arr_j++){
          cin >> arr[arr_i][arr_j];
       }
    }

  int maxValue = numeric_limits<int>::min();
  int columnStart = 0;
  const int COLUMN_START_MAX = 4;
  const int ROW_MAX = 4;
  //check all 18 hourglasses
  for(int i = 0; i < 16; i++)
    {
      for(int j = 0; j < COLUMN_START_MAX; j++)
      {
        for(int k = 0; k < ROW_MAX; k++)
        {
        int sum = 0;
        
        sum += arr[k][j];
        sum += arr[k][j+1];
        sum += arr[k][j+2];
        sum += arr[k+1][j+1];
        sum += arr[k+2][j];
        sum += arr[k+2][j+1];
        sum += arr[k+2][j+2];
           
        if(sum > maxValue)
        {
          maxValue = sum;
        }
           
        }
      }
    }
  cout << maxValue << endl;
  return 0;
}
