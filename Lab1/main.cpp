#include <iostream>
#include <ctime>
#include <random>
#include <iomanip>
#include <cmath>

void perevod();

void transpoze();

void integral();

unsigned long long int dectobin(unsigned long long int num, std::string *s);

double integrate(int n, double a, double b);

double recurse(int n, double x);

int main() {
    unsigned int hit{};

    std::cout << "Select task: \n 1-Perevod chisel \n 2-Transponirovanye Matrici \n 3-Integral \n 4-Exit" << std::endl;
    std::cin >> hit;
    switch (hit) {
        case 1:
            perevod();
            break;
        case 2:
            transpoze();
            break;
        case 3:
            integral();
            break;
        case 4:
            return 0;
        default:
            std::cout << "Choose something" << std::endl;
            break;
    }
    system("pause");
}

void perevod() {
    std::cout << "Input N:" << std::endl;
    unsigned long long int n{};
    std::cin >> n;
    std::string s;
    s.resize(sizeof(n) * 8 + 1);
    dectobin(n, &s);
    std::cout << "Binary(" << n << ") = " << s << std::endl;
}

char digit(unsigned long long int num) {
    switch (num) {
        case 0:
            return '0';
        case 1:
            return '1';
    }
}

unsigned long long int dectobin(unsigned long long int num, std::string *s) {
    unsigned long long int rest = num % 2;
    num /= 2;
    if (num == 0) {
        (*s).at(0) = digit(rest);
        return 1;
    }
    unsigned long long int k = dectobin(num, s);
    (*s).at(k++) = digit(rest);
    return k;
}

void transpoze() {
    int n, m;
    std::mt19937 gen(time(nullptr));
    std::uniform_int_distribution<> uid(0, 100);

    std::cout << "Matrix A(N,M): " << std::endl;
    std::cout << "N = " << std::endl;
    std::cin >> n;
    std::cout << "M = " << std::endl;
    std::cin >> m;
    printf("\nFill random int from 0 to 100\n\n");

    int **A = new int *[n];
    for (int cnt = 0; cnt < n; cnt++)
        A[cnt] = new int[m];

    int **B = new int *[m];
    for (int cnt = 0; cnt < m; cnt++)
        B[cnt] = new int[n];

    std::cout << "Matrix A: " << std::endl;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            A[i][j] = uid(gen);
            std::cout << std::setw(6) << A[i][j];
        }
        std::cout << std::endl;
    }

    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            B[i][j] = A[j][i];
        }
    }
    std::cout << "Transpozed matrix A: " << std::endl;
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            std::cout << std::setw(6) << B[i][j];
        }
        std::cout << std::endl;
    }

}

void integral() {
    double a, b, res{};
    int n;
    std::cout << "Integrate dx/sin(x)^n from a to b: " << std::endl;
    std::cout << "n = " << std::endl;
    std::cin >> n;
    std::cout << "a = " << std::endl;
    std::cin >> a;
    std::cout << "b = " << std::endl;
    std::cin >> b;
    res = integrate(n, a, b);
    std::cout << "Value = " << res << std::endl;
}

double integrate(int n, double a, double b) {
    return (recurse(n, b) - recurse(n, a));
}

double recurse(int n, double x) {
    double res{};
    if (n == 0) res = x;
    else if (n == 1) res = log(tan(x / 2));
    else {
        res = (-cos(x) / ((n - 1) * pow(sin(x), n - 1)) +
               (static_cast<float>(n - 2) / static_cast<float >(n - 1)) * recurse(n - 2, x));
    }
    return res;
}