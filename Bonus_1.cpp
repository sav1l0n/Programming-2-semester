#include <iostream>
#include <string>
#include <array>

using namespace std;

int main () {
    const int m = 6, n = 6;
    int m_del = 0, n_del = 0;
    int temp_i = 0;

    string figure[m][n] =
    {
        { ".", ".", ".", ".", ".", "."},
        { ".", ".", "*", "*", "*", "."},
        { ".", ".", "*", ".", ".", "."},
        { ".", ".", "*", "*", "*", "."},
        { ".", ".", "*", ".", ".", "."},
        { ".", ".", "*", "*", "*", "."}
    };
    
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++){
            cout << figure[i][j] << "\t";
        }
        cout << endl;
        cout << endl;
    }
    cout << endl << endl;
    
    //Вычисление количества пустых строк
    for (int i = 0; i < m; i++) {
        int temp = 0;
        for (int j = 0; j < n; j++) {
            if (figure[i][j] == ".") {
                temp++;
            }
        }
        if (temp == n) {
            m_del++;
        }
    }
    
    //Создание и заполнение двумерного массива m_figure, в котором удалены пустые строки
    string **m_figure = new string*[m - m_del];
    for (int i = 0; i < m; i++) {
        m_figure[i] = new string[n];
    }

    int t = 0;
    for (int i = 0; i < m; i++) {
        int temp = 0;
        for (int j = 0; j < n; j++) {
            if (figure[i][j] == ".") {
                temp++;
            }
            if (j != (n - 1)) {
            } else if (j == (n - 1) and temp != n){
                for (int j_t = 0; j_t < n; j_t++) {
                    m_figure[i - t][j_t] = figure [i][j_t];
                }
            } else if ((j == (n - 1)) and (temp == n)) {
                t++;
            }
        }
    }

    //Вычисление количества пустых столбцов в двумерном массиве m_figure
    for (int j = 0; j < n; j++) {
        int temp = 0;
        for (int i = 0; i < m - m_del; i++) {
            if (m_figure[i][j] == ".") {
                temp++;
            }
        }
        if (temp == (m - m_del)) {
            n_del++;
        }
        temp = 0;
    }
    
    //Создание и заполнение двумерного массива с учетом удаленных пустых столбцов
    string **n_figure = new string*[m - m_del];
    for (int i = 0; i < m - m_del; i++) {
        n_figure[i] = new string[n - n_del];
    }

    t = 0;
    for (int j = 0; j < n; j++) {
        int temp = 0;
        for (int i = 0; i < m - m_del; i++) {
            if (m_figure[i][j] == ".") {
                temp++;
            }
            if (i != (m - m_del - 1)) {
            } else if ((i == (m - m_del - 1)) and (temp != (m - m_del))){
                for (int i_t = 0; i_t < m - m_del; i_t++) {
                    n_figure[i_t][j - t] = m_figure [i_t][j];
                }
            } else if ((i == (m - m_del - 1)) and (temp == (m - m_del))) {
                t++;
            }
        }
        temp = 0;
    }
    
    for (int i = 0; i < m - m_del; i++) {
        for (int j = 0; j < n - n_del; j++){
            cout << n_figure[i][j] << "\t";
        }
        cout << endl;
        cout << endl;
    }
    cout << endl << endl;

    return 0;
}