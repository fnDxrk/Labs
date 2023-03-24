#include <iostream>
#include <string>

using namespace std;

const int h = 6;
const int w = 6;

// #include <iostream>
// #include <string>
// #include <array>

// using namespace std;

// int main () {
//     const int m = 6, n = 6;
//     int m_del = 0, n_del = 0;
//     int temp_i = 0;

//     string figure[m][n] =
//     {
//         { ".", ".", ".", ".", ".", "."},
//         { ".", ".", "*", "*", "*", "."},
//         { ".", ".", "*", ".", ".", "."},
//         { ".", ".", "*", "*", "*", "."},
//         { ".", ".", "*", ".", ".", "."},
//         { ".", ".", "*", "*", "*", "."}
//     };
    
//     for (int i = 0; i < m; i++) {
//         for (int j = 0; j < n; j++){
//             cout << figure[i][j] << "\t";
//         }
//         cout << endl;
//         cout << endl;
//     }
//     cout << endl << endl;
    
//     //Вычисление количества пустых строк
//     for (int i = 0; i < m; i++) {
//         int temp = 0;
//         for (int j = 0; j < n; j++) {
//             if (figure[i][j] == ".") {
//                 temp++;
//             }
//         }
//         if (temp == n) {
//             m_del++;
//         }
//     }
    
//     //Создание и заполнение двумерного массива m_figure, в котором удалены пустые строки
//     string **m_figure = new string*[m - m_del];
//     for (int i = 0; i < m; i++) {
//         m_figure[i] = new string[n];
//     }

//     int t = 0;
//     for (int i = 0; i < m; i++) {
//         int temp = 0;
//         for (int j = 0; j < n; j++) {
//             if (figure[i][j] == ".") {
//                 temp++;
//             }
//             if (j != (n - 1)) {
//             } if (j == (n - 1) and temp != n){
//                 for (int j_t = 0; j_t < n; j_t++) {
//                     m_figure[i - t][j_t] = figure [i][j_t];
//                 }
//             } if ((j == (n - 1)) and (temp == n)) {
//                 t++;
//             }
//         }
//     }

//     //Вычисление количества пустых столбцов в двумерном массиве m_figure
//     for (int j = 0; j < n; j++) {
//         int temp = 0;
//         for (int i = 0; i < m - m_del; i++) {
//             if (m_figure[i][j] == ".") {
//                 temp++;
//             }
//         }
//         if (temp == (m - m_del)) {
//             n_del++;
//         }
//         temp = 0;
//     }
    
//     //Создание и заполнение двумерного массива с учетом удаленных пустых столбцов
//     string **n_figure = new string*[m - m_del];
//     for (int i = 0; i < m - m_del; i++) {
//         n_figure[i] = new string[n - n_del];
//     }

//     t = 0;
//     for (int j = 0; j < n; j++) {
//         int temp = 0;
//         for (int i = 0; i < m - m_del; i++) {
//             if (m_figure[i][j] == ".") {
//                 temp++;
//             }
//             if (i != (m - m_del - 1)) {
//             } if ((i == (m - m_del - 1)) and (temp != (m - m_del))){
//                 for (int i_t = 0; i_t < m - m_del; i_t++) {
//                     n_figure[i_t][j - t] = m_figure [i_t][j];
//                 }
//             } if ((i == (m - m_del - 1)) and (temp == (m - m_del))) {
//                 t++;
//             }
//         }
//         temp = 0;
//     }
    
//     for (int i = 0; i < m - m_del; i++) {
//         for (int j = 0; j < n - n_del; j++){
//             cout << n_figure[i][j] << "\t";
//         }
//         cout << endl;
//         cout << endl;
//     }
//     cout << endl << endl;

//     return 0;
// }


void printArray (string** figure) {
    for (int i = 0; i < h; i++) {
        for (int j = 0; j < w; j++){
            cout << figure[i][j] << "\t";
        }
        cout << endl;
        cout << endl;
    }
    cout << "\n\n";
}

int main() {

    string figure[h][w] =
    {
        { ".", ".", ".", ".", ".", "."},
        { ".", ".", "*", "*", "*", "."},
        { ".", ".", "*", ".", ".", "."},
        { ".", ".", "*", "*", "*", "."},
        { ".", ".", "*", ".", ".", "."},
        { ".", ".", "*", "*", "*", "."}
    };
    
    for (int i = 0; i < h; i++) {
        for (int j = 0; j < w; j++){
            cout << figure[i][j] << "\t";
        }
        cout << endl;
        cout << endl;
    }
    cout << "\n\n";


    int hN = 0;
    int wN = 0;

    //Счёт пустых строк
    for (int i = 0; i < h; i++) {
        int temp = 0;
        for (int j = 0; j < w; j++) {
            if (figure[i][j] == ".") {
                temp++;
            }
        }
        if (temp == w) {
            hN++;           //Кол-во пустых строк
        }
    }

    cout << "Кол-во пустых строк : " << hN << endl;

    hN = h - hN;

    
    cout << endl;

    string **h_figure = new string*[hN];
    
    for (int i = 0; i < hN; i++) {
        h_figure[i] = new string[w];
    }

    int x = 0;
    for (int i = 0; i < h; i++) {
        int temp = 0;
        for (int j = 0; j < w; j++) {
            if (figure[i][j] == ".") {
                temp++;
            }
            if (temp == w) {
                x++;
            }
            if (temp != w) {
                for (int j_t = 0; j_t < w; j_t++) {
                    h_figure[i - x][j_t] = figure [i][j_t];
                }
            }
        }
    }

    for (int i = 0; i < hN; i++) {
        for (int j = 0; j < w; j++){
            cout << h_figure[i][j] << "\t";
        }
        cout << endl;
        cout << endl;
    }
    cout << "\n\n";



    for (int j = 0; j < w; j++) {
        int temp = 0;
        for (int i = 0; i < hN; i++) {
            if (figure[i][j] == ".") {
                temp++;
            }
        }
        if (temp == hN) {
            wN++;           //Кол-во пустых строк
        }
    }

    cout << "Кол-во пустых столбцов : " << wN << endl;

    wN = w - wN;

    cout << endl;

    string **w_figure = new string*[hN];
    
    for (int i = 0; i < hN; i++) {
        w_figure[i] = new string[wN];
    }
    
    x = 0;
    for (int j = 0; j < w; j++) {
        int temp = 0;
        for (int i = 0; i < hN; i++) {
            if (figure[i][j] == ".") {
                temp++;
            }
            if (i == hN - 1 and temp == hN) {
                x++;
            }
            if (i == hN - 1 and temp != hN) {
                for (int i_t = 0; i_t < hN; i_t++) {
                    w_figure[i_t][j - x] = h_figure[i_t][j];
                }
            }
        }
        temp = 0;
    }

    for (int i = 0; i < hN; i++) {
        for (int j = 0; j < wN; j++){
            cout << w_figure[i][j] << "\t";
        }
        cout << endl;
        cout << endl;
    }
    cout << "\n\n";

    cout << endl << endl;

    return 0;
}
