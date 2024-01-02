#include <iostream>
#include <cmath>
using namespace std;

void stat(const double[],int,double[]);

int main(){
    double A[] = {1.2,3.5,6.9,7.8,12.5,0.5};
    int N = sizeof(A)/sizeof(A[0]);
    double B[6];
    stat(A,N,B);
    cout << "Arithmetic Mean = " << B[0];
    cout << "\nStandard Deviation = " << B[1];
    cout << "\nGeometric Mean = " << B[2];
    cout << "\nHarmonic Mean = " << B[3];
    cout << "\nMax = " << B[4];
    cout << "\nMin = " << B[5];
    return 0;
}

void stat(const double A[], int N, double B[]){
    double max, min = A[0];
    double product = 1;
    double total, sum = 0;
    double arithMean, SD, geoMean, harmoMean;
    
    for (int i = 0; i < N; i++){
        total += A[i];
    }
    arithMean = total/N;

    for (int i = 0; i < N; i++){
        sum += pow(A[i] - arithMean, 2);
    }
    SD = sqrt(sum/(N));

    for (int i = 0; i < N; i++){
        product *= A[i];
    }
    geoMean = pow(product,1.0/N);

    sum = 0;
    for (int i = 0; i < N; i++){
        sum += 1/A[i];
    }
    harmoMean = N/sum;

    for (int i = 0; i < N; i++){
        if (A[i] < max){
            continue;
        }else{
            max = A[i];
        }
    }

    for (int i = 0; i < N; i++){
        if (A[i] > min){
            continue;
        }else{
            min = A[i];
        }
    }

    B[0] = arithMean;
    B[1] = SD;
    B[2] = geoMean;
    B[3] = harmoMean;
    B[4] = max;
    B[5] = min;
}
