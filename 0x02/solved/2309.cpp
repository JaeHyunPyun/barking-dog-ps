#include <iostream>
#include <vector>

using namespace std;

vector<int> findSevenDwarf(int nineDwarf[]) {

  for (int i = 0; i < 9; i++) {
    for (int j = i + 1; j < 9; j++) {
      int sum = 0;
      vector<int> sevenDwarf;

      for (int k = 0; k < 9; k++) {
        if (k != i && k != j) {
          sevenDwarf.push_back(nineDwarf[k]);
          sum += nineDwarf[k];
        }
      }

      // if (sum == 100) {
      //   cout << "answer : " << "\n";
      //   for (int i = 0; i < 7; i++) {
      //     cout << sevenDwarf[i] << " ";
      //   }
      // }
      if (sum == 100) {
        return sevenDwarf;
      }
    }
  }

  vector<int> noDwarf;
  return noDwarf;
}

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  int nineDwarf[9] = {
      0,
  };

  for (int i = 0; i < 9; i++) {
    cin >> nineDwarf[i];
  };

  vector<int> result = findSevenDwarf(nineDwarf);

  if (result.size() != 0) {
    for (int i = 0; i < result.size(); i++) {
      for (int j = i + 1; j < result.size(); j++) {
        if (result[i] > result[j]) {
          int temp = result[i];
          result[i] = result[j];
          result[j] = temp;
        }
      }
    }
  }

  for (int i = 0; i < result.size(); i++) {
    cout << result[i] << "\n";
  }

  return 0;
}