#include <iostream>
#include <string>
using namespace std;

string xorMax(string A, string B){
    int n = A.size();

    string ans;

    int A1, A0, B1, B0;
    A1 = A0 = B1 = B0 = 0;
    // Count no of 1's and 0's
    for (int i = 0; i < n; i++) {
        if (A[i] == '1')
        {
            A1++;
        }
        else
        {
            A0++;
        }

        if (B[i] == '1')
        {
            B1++;
        }else
        {
            B0++;
        }
    }

    // make the string

    while (A1>0 && B0 > 0){
        ans.append("1");
        A1--;
        B0--;
    }
    while (A0>0 && B1 > 0){
        ans.append("1");
        A0--;
        B1--;
    }

    int ss = ans.size();
    if (ss < n)
    {
        for (int i = 0; i < n-ss; i++) {
            ans.append("0");
        }
    }


    return ans;

    
}

int main() {
    int T;
    cin >> T;
    while (T--){
        string A, B;
        cin >> A;
        cin >> B;
        cout << xorMax(A, B) << endl;
    }
	return 0;
}
