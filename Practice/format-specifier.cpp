#include <iostream>
#include <iomanip>
using namespace std;

int main () {
  cout << setw(21) << left << "Test"    << 1 << endl;
  cout << setw(21) << left << "Test2"   << 2 << endl;
  cout << setw(21) << left << "Very Long Text is : "     << 2 << endl;
  cout << setw(21) << left << "Etc"     << 1 << endl;
  return 0;
}
