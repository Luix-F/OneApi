#include <iostream>
#include <CL/sycl.hpp>
#include <random>

using namespace sycl;
using namespace std;

void printMatrix(int **matrix, int rows, int cols) {
    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < cols; ++j) {
            std::cout << matrix[i][j] << " ";
        }
        std::cout << std::endl;
    }
}

int** CentrMK( int ncent, int atributos, int **centros){
    //cpu_selector sel;
    //gpu_selector sel;
    //queue qcmk(sel);

    for (int i = 0; i < ncent; i++)
    {
        /*
        qcmk.submit([&](handler& ker){
            ker.parallel_for(range<1>(atributos), [=](auto j) {
                centros[i][j] = rand()%100;
            });
        });
        qcmk.wait();*/
        
        for (int j = 0; j < atributos; j++)
        {
            centros[i][j] = rand()%100;
        }
        
    }
    return centros;
}


int main(){
    int nista;
    int ncent;
    int atributos;
    cout << "Quantidade de atributos: ";
    cin >> atributos;
    cout << "Quantas instacias serão criadas: ";
    cin >> nista;
    cout << "Quantas centroides serão usados: ";
    cin >> ncent;

    //int instancias[nista][atributos];
    int **instancias = new int*[nista];
    for (int i = 0; i < nista; ++i) {
        instancias[i] = new int[atributos];
    }

    //int centros[ncent][atributos];
    int **centros = new int*[ncent];
    for (int i = 0; i < ncent; ++i) {
        centros[i] = new int[atributos];
    }
    
    centros = CentrMK(ncent, atributos, centros);
    printMatrix(centros, ncent, atributos);
    return 0;
}