#include <stdio.h>
#include <array>
#include <complex>

typedef std::array<std::complex<float>, 2> Qubit;
typedef std::array<std::complex<float>, 4> CmplxMatrix;
const float c_pi = 3.14159265359f;

static const Qubit qubit0 = {1.0f, 0.0f};
static const Qubit qubit1 = {0.0f, 1.0f};
static const Qubit qubit_plus = {1.0f/ std::sqrt(2.0), 1.0f/ std::sqrt(2.0)};
static const Qubit qubit_minus = {1.0f/ std::sqrt(2.0), -1.0f/ std::sqrt(2.0)};
static const Qubit qubit_iplus = {std::complex<float>(1.0f, 0.0f)/ std::complex<float>(std::sqrt(2.0), 0.0f), 
std::complex<float>(0.0f, 1.0f)/std::complex<float>(std::sqrt(2.0), 0.0f)};
static const Qubit qubit_iminus = {std::complex<float>(1.0f, 0.0f)/ std::complex<float>(std::sqrt(2.0), 0.0f), 
std::complex<float>(0.0f, -1.0f)/std::complex<float>(std::sqrt(2.0), 0.0f)};


static const CmplxMatrix xgate = {
    {
        0.0f, 1.0f,
        1.0f, 0.0f
    }
};

static const CmplxMatrix ygate = {
    {
        std::complex<float>(0.0f, 0.0f), std::complex<float>(0.0f, -1.0f),
        std::complex<float>(0.0f, 1.0f), std::complex<float>(0.0f, 0.0f)
    }
};

static const CmplxMatrix zgate = {
    {
        1.0f, 0.0f,
        0.0f, -1.0f
    }
};

static const CmplxMatrix hgate = {
    {
        1.0f/std::sqrt(2.0f), 1.0f/std::sqrt(2.0f),
        1.0f/std::sqrt(2.0f), -1.0f/std::sqrt(2.0f)
    }
};

void WaitForEnter (){
    printf("\nPress Enter to quit:");
    fflush(stdin);
    getchar();
}

Qubit ApplyGate (const Qubit& qubit, const CmplxMatrix& gate){
    return {
        gate[0] * qubit[0] + gate[1] * qubit[1],
        gate[2] * qubit[0] + gate[3] * qubit[1]
    };
};

int Prob (const Qubit& qubit){
    float prob = std::round((qubit[1] * std::conj(qubit[1])).real());
    return prob;
}

CmplxMatrix ChangePhase(float radians){
    return {
        {
            1.0f, 0.0f,
            0.0f, std::exp(std::complex<float>(0.0f, 1.0f) * radians)
        }
    };
}

void Print (const Qubit& qubit){
    printf("[(%0.2f, %0.2fi), (%0.2f, %0.2fi)] %i%% true", 
    qubit[0].real(), qubit[0].imag(), qubit[1].real(), qubit[1].imag(), Prob(qubit));
}


int main(int argc, char **argv){
    {
        printf("Not Gate: \n");
        Qubit v = qubit0;
        Print(v);
        printf("\n ! = ");
        v = ApplyGate(v, xgate);
        Print(v);
        printf("\n\n");
    }
    {
        printf("Not Gate: \n");
        Qubit v = qubit_iplus;
        Print(v);
        printf("\n ! = ");
        v = ApplyGate(v, xgate);
        Print(v);
        printf("\n\n");
    }
    WaitForEnter();
    return 0;
}