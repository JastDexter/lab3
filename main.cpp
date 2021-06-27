#include <iostream>
#include <vector>

using namespace std;
typedef long double ld;

vector<ld> solve_linear_simultaneous_equation(vector<vector<ld>> input_matrix, int matrix_size, ld eps) {
    vector<ld> last_results(matrix_size);
    while (true) {
        vector<long double> unknow_now(matrix_size);
        for (int i = 0; i < matrix_size; i++) {
            unknow_now[i] = input_matrix[i][matrix_size];
            for (int j = 0; j < matrix_size; j++) {
                if (j != i) unknow_now[i] -= last_results[j] * input_matrix[i][j];
            }
            unknow_now[i] /= input_matrix[i][i];
        }
        ld mistake = 0;
        for (int i = 0; i < matrix_size; i++) mistake += abs(unknow_now[i] - last_results[i]);
        if (mistake < eps) break;
        last_results = unknow_now;
    }
    return last_results;
}

int main() {
    vector<vector<long double> > matrix{
            {-0.76, -0.05, -0.24, 0.19},
            {-0.22, -0.91, -0.44, 0.97},
            {0.13,  -0.02, -0.58, -0.14}
    };
    vector<ld> answer = solve_linear_simultaneous_equation(matrix, 3, 1e-4);
    for (ld elem : answer) {
        cout << elem << " ";
    }
    cout << endl;
    return 0;
}
