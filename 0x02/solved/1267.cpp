#include <iostream>

using namespace std;

int youngsikCalculate(int phoneCallTime, int sum);
int minsikCalculate(int phoneCallTime, int sum);

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  int callCount = 0;
  int callTime = 0;

  int youngsikSum = 0;
  int minsikSum = 0;

  cin >> callCount;

  for (int i = 0; i < callCount; i++) {
    cin >> callTime;
    youngsikSum = youngsikCalculate(callTime, youngsikSum);
    minsikSum = minsikCalculate(callTime, minsikSum);
  }

  if (youngsikSum > minsikSum) {
    cout << "M " << minsikSum;
  } else if (minsikSum > youngsikSum) {
    cout << "Y " << youngsikSum;
  } else {
    cout << "Y M " << youngsikSum;
  }

  return 0;
}

int youngsikCalculate(int phoneCallTime, int sum) {

  while (phoneCallTime >= 0) {
    sum += 10;
    phoneCallTime -= 30;
  }

  return sum;
}

int minsikCalculate(int phoneCallTime, int sum) {

  while (phoneCallTime >= 0) {
    sum += 15;
    phoneCallTime -= 60;
  }

  return sum;
}