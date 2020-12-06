#include <bits/stdc++.h>

using namespace std;

void doSquare(int** A, int N) {
    int** temp = new int*[N];
    for (int i = 0; i < N; i++) {
        temp[i] = new int[N];
    }

    for (int r = 0; r < N; r++) {
        for (int c = 0; c < N; c++) {
            int tempValue = 0;
            for (int k = 0; k < N; k++) {
                tempValue += (A[r][k] * A[k][c]) % 1000;
            }
            tempValue = tempValue % 1000;
            temp[r][c] = tempValue;
        }
    }

    for (int r = 0; r < N; r++) {
        for (int c = 0; c < N; c++) {
            A[r][c] = temp[r][c];
        }
    }

    for (int i = 0; i < N; i++) {
        delete [] temp[i];
    }
    delete [] temp;
}

void matrixProduct(int** A, int N, int** initialA) {
    int** temp = new int*[N];
    for (int i = 0; i < N; i++) {
        temp[i] = new int[N];
    }

    for (int r = 0; r < N; r++) {
        for (int c = 0; c < N; c++) {
            int tempValue = 0;
            for (int k = 0; k < N; k++) {
                tempValue += (A[r][k] * initialA[k][c]) % 1000;
            }
            tempValue = tempValue % 1000;
            temp[r][c] = tempValue;
        }
    }

    for (int r = 0; r < N; r++) {
        for (int c = 0; c < N; c++) {
            A[r][c] = temp[r][c];
        }
    }

    for (int i = 0; i < N; i++) {
        delete [] temp[i];
    }
    delete [] temp;
}

void matrixSquare(int** A, int N, long long B, int** initialA) {
    if (B == 1) {
        return;
    }

    if (B % 2 == 1) {
        matrixSquare(A, N, B / 2, initialA);
        doSquare(A, N);
        matrixProduct(A, N, initialA);
    }
    else {
        matrixSquare(A, N, B / 2, initialA);
        doSquare(A, N);
    }
}

int main() {
    cin.tie(NULL);
	ios::sync_with_stdio(false);

    int N;
    long long B;
    cin >> N >> B;
    int** A = new int*[N];
    int** initialA = new int*[N];
    for (int i = 0; i < N; i++) {
        A[i] = new int[N];
        initialA[i] = new int[N];
        for (int j = 0; j < N; j++) {
            int num;
            cin >> num;
            A[i][j] = num;
            initialA[i][j] = num;
        }
    }
    
    if (B == 1) {
        for (int r = 0; r < N; r++) {
            for (int c = 0; c < N; c++) {
                cout << A[r][c] % 1000 << " ";
            }
        cout << '\n';
        }
    }
    else {
        matrixSquare(A, N, B, initialA);
        for (int r = 0; r < N; r++) {
            for (int c = 0; c < N; c++) {
                cout << A[r][c] << " ";
            }
            cout << '\n';
        }
    }
}