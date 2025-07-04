#include "testmillerrabin.h"



AlgorithmMillerRabin::AlgorithmMillerRabin(const mpz_class n) : n(n), nAlgor(n - 1), m(n - 1) {
    while (true) {
        m >>= 1;
        s++;
        if((m & 1) != 0 || n == 0){ break;}
    }
}


void AlgorithmMillerRabin::computeNumersPrime(const int count){
    clearMassiv();
    hundredPVec.push_back(std::make_unique<long long[]>(MAX_COUNT_PTR));

    int indxVec = 0;
    int indxPtr = 0;
    int cap = 0;
    int capClone = 0;
    AlgorithmMillerRabin number{0};


    for(int i = 1; cap < count; i += 2){
        if(indxPtr == MAX_COUNT_PTR)
        {
            hundredPVec.push_back(std::make_unique<long long[]>(MAX_COUNT_PTR));
            ++indxVec;
            indxPtr = 0;
        }


        number.restart(i);
        if(computeIsPrime(number))
        {

            std::string str = number.getN().get_str();
            std::from_chars(str.data(), str.data() + str.size(), hundredPVec[indxVec][indxPtr]);
            ++indxPtr;
            ++cap;
        }


    }
}

bool AlgorithmMillerRabin::computeIsPrime(AlgorithmMillerRabin& number){
    mpz_class x = 0;
    for(int i = 0; i < keyVerefecation.size(); ++i)
    {
        if(keyVerefecation[i] > number.getN()){ break; }

        mpz_powm(x.get_mpz_t(),
                 keyVerefecation[i].get_mpz_t(),
                 number.getM().get_mpz_t(),
                 number.getN().get_mpz_t());

        if(x == 1 || x == number.getNAlgor()){ return true;}

        if(x != 1 && x != number.getNAlgor())
        {
            for(int i = 0; i < number.getS() - 1; ++i){

                mpz_powm(x.get_mpz_t(),
                         x.get_mpz_t(),
                         mpz_class{2}.get_mpz_t(),
                         number.getN().get_mpz_t());
            }
            if(x == - 1 || x == number.getNAlgor()){ return true; }
            else { return false;}
        }
    }
    return false;
}


void AlgorithmMillerRabin::setKeys(std::vector<mpz_class> newKeys){
    keyVerefecation = newKeys;
}

void AlgorithmMillerRabin::setKeys(const std::string str){
    keyVerefecation.clear();

    std::string subStr = "";
    for(int i = 0; i < str.size(); ++i){
        if(str[i] >= '0' && str[i] <= '9'){
            subStr += str[i];
        }
        if(str[i] == ' ' || i == str.size() - 1){
            keyVerefecation.push_back(mpz_class{subStr});
            subStr = "";
        }
    }
}

void AlgorithmMillerRabin::setN(const mpz_class n){
    this->n = n;
}
void AlgorithmMillerRabin::setNAlg(const mpz_class n){
    this->nAlgor = n;
    this->nAlgor = this->nAlgor - 1;
}
void AlgorithmMillerRabin::setM(const mpz_class m){
    this->m = m;
    this->m = this->m - 1;
}
void AlgorithmMillerRabin::setS(const mpz_class s){
    this->s = s;
}


std::vector<std::unique_ptr<long long[]>>& AlgorithmMillerRabin::getHVec(){
    return hundredPVec;
}

void AlgorithmMillerRabin::clearMassiv(){
    hundredPVec.clear();
}

std::vector<mpz_class> AlgorithmMillerRabin::getKeys(){
    return keyVerefecation;
}

std::string AlgorithmMillerRabin::getStrKeys(){
    std::string str = "";
    for(int i = 0; i < keyVerefecation.size(); ++i){
        str += keyVerefecation[i].get_str() + ' ';
    }
    return str;
}

const long long AlgorithmMillerRabin::getLLN(){
    long long result = 0;
    std::string str = n.get_str();
    std::from_chars(str.data(), str.data() + str.size(), result);
    return result;
}

const mpz_class AlgorithmMillerRabin::getN(){
    return n;
}

mpz_class AlgorithmMillerRabin::getNAlgor(){
    return nAlgor;
}

const long long AlgorithmMillerRabin::getLLNAlgor(){
    long long result = 0;
    std::string str = nAlgor.get_str();
    std::from_chars(str.data(), str.data() + str.size(), result);
    return result;
}

mpz_class AlgorithmMillerRabin::getS(){
    return s;
}

const long long AlgorithmMillerRabin::getLLS(){
    long long result = 0;
    std::string str = s.get_str();
    std::from_chars(str.data(), str.data() + str.size(), result);
    return result;
}

mpz_class AlgorithmMillerRabin::getM(){
    return m;
}

const long long AlgorithmMillerRabin::getLLM(){
    long long result = 0;
    std::string str = m.get_str();
    std::from_chars(str.data(), str.data() + str.size(), result);
    return result;
}

void AlgorithmMillerRabin::restart(const mpz_class n){
    setN(n);
    setNAlg(n);
    setM(n);
    setS(0);
    while (true) {
        m >>= 1;
        s++;
        if((m & 1) != 0 || n == 0 || n == 1){ break;}
    }

}

