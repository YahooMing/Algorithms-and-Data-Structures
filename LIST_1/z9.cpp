#include <iostream>
#include <vector>

typedef std::vector<std::vector<int>> matrix;

matrix iloczyn(const matrix& A, const matrix& B) {
    int n = A.size();
    matrix C(n, std::vector<int>(n, 0));
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            for (int k = 0; k < n; ++k) {
                C[i][j] += A[i][k] * B[k][j];
            }
        }
    }
    return C;
}

matrix potega(const matrix& A, int n) {
    if (n == 1) return A;
    if (n % 2 == 0) {
        matrix half_matrix = potega(A, n / 2);
        return iloczyn(half_matrix, half_matrix);
    } else {
        matrix half_matrix = potega(A, n / 2);
        return iloczyn(iloczyn(half_matrix, half_matrix), A);
    }
}

void wyswietl(const matrix& A) {
    for (const auto& row : A) {
        for (int el : row) {
            std::cout << el << " ";
        }
        std::cout << std::endl;
    }
}

int main() {
    matrix A = { {1, 2}, {3, 4} };
    int n = 3;
    matrix output = potega(A, n);
    std::cout << "A^" << n << ":\n";
    wyswietl(output);

    return 0;
}