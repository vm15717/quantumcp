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


static const CmplxMatrix xgate = {
    {
        0.0f, 1.0f,
        1.0f, 0.0f
    }
};

static const CmplxMatrix ygate = {
    {
        {0.0f, 0.0f}, {0.0f, -1.0f},
        {0.0f, 1.0f}, {0.0f, 0.0f}
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