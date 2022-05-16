// This program has an error
#include <iostream>
#include <vector>
#include <string>
using namespace std;





void read_input(int n,int m,vector <string > ar,vector <int> inp ) {
    cin >> n >> m;
    for (int i = 0; i < n; ++i) {
        string a;
        cin >> a;
        ar.push_back(a);
    }

    for (int i = 0; i < n; i++) {
        int b;
        cin >> b;
        inp.push_back(b);
    }
}

int process(int n,int m,vector <string > ar,vector <int> inp) {

    bool err = false;

    for (int j = 0; j < m; j++)
        for (int i = 0; i < n - 1; i++)
            if (ar[i][j] != '-') {
                if (ar[i][j] < 'a' || ar[i][j] > 'z') {
                    cout << "Invalid Network\n";
                    err = true;
                }
                if (!err)
                    for (int k = i + 1; k < n; k++) {
                        int cnt = 1;
                        if (ar[i][j] == ar[k][j]) {
                            cnt++;
                            if (inp[i] > inp[k]) {
                                char temp = inp[i];
                                inp[i] = inp[k];
                                inp[k] = temp;
                            }
                        }
                        if (cnt != 2) {
                            cout << "Invalid Network\n";
                            err = true;
                        }
                    }
            }
return err ;
}

void generate_output(int n,vector <int> inp, int result) {

    bool flag = false;

    if (result==0) {
        for (int i = 0; i < n - 1; i++)
            if (inp[i] > inp[i+1]) {
                cout << "Not sorted\n";
                flag = true;
            }
        if (!flag)
            cout << "Sorted\n";
    }
}

int main() {

    int x,y;
    vector<string> ar;
    vector<int> inp;

    read_input(x,y,ar,inp);
    int result = process(x,y,ar,inp);
    generate_output(x,inp,result);
}
