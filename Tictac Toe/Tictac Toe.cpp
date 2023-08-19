#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

void show(vector<vector<char>>& arr) {
    cout << " " << arr[0][0] << " | " << arr[0][1] << " | " << arr[0][2] << "\n";
    cout << "---|---|---\n";
    cout << " " << arr[1][0] << " | " << arr[1][1] << " | " << arr[1][2] << "\n";
    cout << "---|---|---\n";
    cout << " " << arr[2][0] << " | " << arr[2][1] << " | " << arr[2][2] << "\n";
}

bool check1(vector<vector<char>>& arr, const string& p1, int c) {
    bool winp1 = false;
    for (int j = 0; j < 3; ++j) {
        if (arr[j][0] == 'O' && arr[j][1] == 'O' && arr[j][2] == 'O') {
            winp1 = true;
        }
    }
    for (int j = 0; j < 3; ++j) {
        if (arr[0][j] == 'O' && arr[1][j] == 'O' && arr[2][j] == 'O') {
            winp1 = true;
        }
    }
    if (arr[0][0] == 'O' && arr[1][1] == 'O' && arr[2][2] == 'O') {
        winp1 = true;
    }
    if (arr[0][2] == 'O' && arr[1][1] == 'O' && arr[2][0] == 'O') {
        winp1 = true;
    }
    if (winp1) {
        cout << p1 << " wins\n";
        show(arr);
        c = -56;
        return true;
    }
    return false;
}

bool check2(vector<vector<char>>& arr, const string& p2, int c) {
    bool winp2 = false;
    for (int j = 0; j < 3; ++j) {
        if (arr[j][0] == 'X' && arr[j][1] == 'X' && arr[j][2] == 'X') {
            winp2 = true;
        }
    }
    for (int j = 0; j < 3; ++j) {
        if (arr[0][j] == 'X' && arr[1][j] == 'X' && arr[2][j] == 'X') {
            winp2 = true;
        }
    }
    if (arr[0][0] == 'X' && arr[1][1] == 'X' && arr[2][2] == 'X') {
        winp2 = true;
    }
    if (arr[0][2] == 'X' && arr[1][1] == 'X' && arr[2][0] == 'X') {
        winp2 = true;
    }
    if (winp2) {
        cout << p2 << " wins\n";
        show(arr);
        c = -56;
        return true;
    }
    return false;
}

int main() {
    string p1, p2;
    cout << "Enter Player 1 Name: ";
    cin >> p1;
    cout << "Yours position will be denoted by O\n";
    cout << "Enter Player 2 Name: ";
    cin >> p2;
    cout << "Yours position will be denoted by X\n";
    
    
	bool play=true;
	while (play){
		int c = 1;
		vector<vector<char>> arr = {{'1', '2', '3'}, {'4', '5', '6'}, {'7', '8', '9'}};
    
	show(arr);
    vector<int> list;
    int count = 0;
    while (c > 0) {
        if (c % 2 != 0) {
            cout << p1 << " Chance, (O)\n";
            int num;
            cout << "Enter a number: ";
            cin >> num;
            while (find(list.begin(), list.end(), num) != list.end() || num < 1 || num > 9) {
                cout << "Invalid Input.\n";
                cout << "Enter a number: ";
                cin >> num;
            }
            arr[(num - 1) / 3][(num - 1) % 3] = 'O';
            if (check1(arr, p1, c)) {
                // c = -56;
                break;
            }
            c += 1;
            count += 1;
            show(arr);
            list.push_back(num);
            if (count > 8) {
                cout << "DRAW\n";
                break;
            }
        } else {
            cout << p2 << " Chance, (X)\n";
            int num;
            cout << "Enter a number: ";
            cin >> num;
            while (find(list.begin(), list.end(), num) != list.end() || num < 1 || num > 9) {
                cout << "Invalid Input.\n";
                cout << "Enter a number: ";
                cin >> num;
            }
            arr[(num - 1) / 3][(num - 1) % 3] = 'X';
            if (check2(arr, p2, c)) {
                // c = -56;
                break;
            }
            c += 1;
            count += 1;
            show(arr);
            list.push_back(num);
            if (count > 8) {
                cout << "Sorry Guys, Game is DRAW\n";
                break;
            }
        }
    }
	char check;
	cout<<"DO u want to play another game (press y for yes and n for no) :";
	cin>>check;
	while (check!='n' and check!='y'){
		cout<<"Invalid Input"<<endl;
		cin>>check;
	}
	if (check=='n'){
		play=false;
	}else{
		c=1;
	}
	}

    return 0;
}
