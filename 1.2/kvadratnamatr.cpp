#include <iostream>
#include <iomanip> 

class kvadratnamatr
{
    double** data;
    unsigned int rank;

    class Proxy {
    public:
        Proxy(double* pRow) : row(pRow) { }

        double& operator[](int index) {
            return row[index];
        }

    private:
        double* row;
    };

public:

    Proxy operator[](int index) {
        return Proxy(data[index]);
    }

    kvadratnamatr(unsigned int pRank = 0) : rank(pRank)
    {
        if (pRank == 0) {
            data = NULL;
            return;
        }

        data = new double* [pRank];
        for (int i = 0; i < pRank; ++i) {
            data[i] = new double[pRank];
            std::fill(data[i], data[i] + rank, 0);
        }
    }

    ~kvadratnamatr()
    {
        if (data != NULL) {

            for (int i = 0; i < rank; ++i) {
                delete[] data[i];
            }

            delete[] data;
        }
    }

    void print() {
        std::cout.precision(4);
        for (unsigned int i = 0; i < rank; i++) {
            std::cout << std::endl;
            for (unsigned int j = 0; j < rank; j++) {
                std::cout << std::setw(6) << (*this)[i][j] << ";";
            }
        }
        std::cout << std::endl;
        std::cout.precision(16);
    }

    double diagonal() {
        double result = 0;

        for (unsigned int i = 0; i < rank; i++) {
            result += (*this)[i][i];
        }

        return result;
    }

    double sumUp() {
        double result = 0;

        for (unsigned int i = 0; i < rank - 1; i++) {
            for (unsigned int j = i + 1; j < rank; j++) {
                result += (*this)[i][j];
            }
        }

        return result;
    }

    double sumDown() {
        double result = 0;

        for (unsigned int i = 0; i < rank - 1; i++) {
            for (unsigned int j = i + 1; j < rank; j++) {
                result += (*this)[j][i];
            }
        }

        return result;
    }
};
