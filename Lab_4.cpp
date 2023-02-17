#include <iostream>
using namespace std;
/*
const int n = 5;
typedef int rown[n];
typedef int rown_2[n-1];


int main () {
    int m, n = 5;
    int max_i, max_j, temp;
    rown *B;
    rown_2 *C;
    cout << "Input m: ";
    cin >> m;
    B = new rown[m];
    C = new rown_2[m-1];

    if (B == NULL) {
        cout << "Failed to allocate memory" << endl;
        return 1;
    }
    if (C == NULL) {
        cout << "Failed to allocate memory" << endl;
        return 1;
    }
    cout << endl << "Matrix B" << endl;
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            B[i][j] = rand()%100;
            cout << B[i][j] << "\t";
            if ((i == 0) and (j == 0)) {
                max_i = 0;
                max_j = 0;
                temp = B[i][j];
            }
            if (B[i][j] > temp) {
                max_i = i;
                max_j = j;
                temp = B[i][j];
            }
        }
        cout << endl;
    }
    cout << endl << "Matrix C" << endl;
    for (int i = 0; i < (m - 1); i++) {
        for (int j = 0; j < (n - 1); j++) {
            if (i < max_i) {
                if (j < max_j) {
                    C[i][j] = B[i][j];
                } else {
                    C[i][j] = B[i][j + 1];
                }
            } else {
                if (j < max_j) {
                    C[i][j] = B[i + 1][j];
                } else {
                    C[i][j] = B[i + 1][j + 1];
                }
            }
            cout << C[i][j] << "\t";
        }
        cout << endl;
    }
    delete B;
    delete C;

    return 0;
}
*/

int main () {
    int m, n, all_sum;
    cout << "Input m and n: ";
    cin >> m >> n;
    int m_new = m + 1;
    int n_new = n + 1;
    int **A = new int*[m];
    int **M = new int*[m_new];
    int *temp_i = new int[m];
    int *temp_j = new int[n];

    for (int i = 0; i < m; i++) {
        A[i] = new int[n];
        M[i] = new int[n_new];
    }
    M[m] = new int[n_new];

    if ((A == NULL) or (M == NULL) or (temp_i == NULL) or (temp_j == NULL)) {
        cout << "Failed to allocate memory" << endl;
        return 1;
    }

    cout << endl << "Matrix A" << endl;
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            A[i][j] = rand()%100;
            cout << A[i][j] << "\t";
            temp_i[i] += A[i][j];
            temp_j[j] += A[i][j];
            all_sum += A[i][j];
        }
        cout << endl;
    }

    int sum_i = 0;
    for (int i = 0; i < m; i++) {
        sum_i += temp_i[i];
    }
    int sum_j = 0;
    for (int i = 0; i < n; i++) {
        sum_j += temp_j[i];
    }

    for (int i = 0; i < m + 1; i++) {
        for (int j = 0; j < n + 1; j++) {
            if(!(i == m) or !(j == n)) {
                if ((i == m) or (j == n)) {
                    if (j == n) {
                        M[i][j] = temp_i[i];
                    } else if (i == m) {
                        M[i][j] = temp_j[j];
                    }
                } else {
                    M[i][j] = A[i][j];
                }

            } else {
                M[i][j] = sum_i + sum_j;
            }
        }
    }

    cout << endl << "Matrix M" << endl;
    for (int i = 0; i < m_new; i++) {
        for (int j = 0; j < n_new; j++) {
            cout << M[i][j] << "\t";
        }
        cout << endl;
    }

    return 0;
}