#ifndef ALGORITHMMILLERRABIN_H
#define ALGORITHMMILLERRABIN_H
#include "cmath"
#include "vector"
#include "memory"
#include "ALG_CONSTANTS.h"
#include "gmpxx.h"
#include "fileinput.h"
#include "charconv"
#include "QString"

class AlgorithmMillerRabin
{
    std::vector<std::unique_ptr<long long[]>> hundredPVec;
    mpz_class n = 0;
    mpz_class nAlgor = 0;
    mpz_class s = 0;
    mpz_class m = 0;
    bool isPrime = 0;
    std::vector<mpz_class> keyVerefecation{2, 3, 4, 5, 6, 7, 9, 10, 11, 12, 13, 14, 15, 16, 17, 18, 19, 20, 21, 22, 35, 40, 51, 52, 122, 155, 134, 555, 1004, 1502, 2001, 3000, 4000, 6100, 7351, 10000, 20000, 30000, 100000 };
public:

    AlgorithmMillerRabin(const mpz_class n);

    void computeNumersPrime(const int count);
    bool computeIsPrime(AlgorithmMillerRabin& number);

    void setKeys(std::vector<mpz_class> newKeys);
    void setKeys(const std::string str);
    void setN(const mpz_class n);
    void setNAlg(const mpz_class n);
    void setM(const mpz_class m);
    void setS(const mpz_class s);

    std::vector<std::unique_ptr<long long[]>>& getHVec();
    void clearMassiv();

    std::vector<mpz_class> getKeys();
    std::string getStrKeys();

    const mpz_class getN();
    const long long getLLN();

    mpz_class getNAlgor();
    const long long getLLNAlgor();

    mpz_class getS();
    const long long getLLS();

    mpz_class getM();
    const long long getLLM();


    void restart(const mpz_class n);
};

#endif // ALGORITHMMILLERRABIN_H
