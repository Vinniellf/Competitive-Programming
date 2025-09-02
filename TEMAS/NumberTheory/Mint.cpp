#include <iostream>

const int MOD = 1e9 + 7;

struct mint {
    long long val;

    // Constructor por defecto
    mint(long long v = 0) {
        val = v % MOD;
        if (val < 0) val += MOD;
    }

    // Operador += (suma modular)
    mint& operator+=(const mint& other) {
        val += other.val;
        if (val >= MOD) val -= MOD;
        return *this;
    }

    // Operador -= (resta modular)
    mint& operator-=(const mint& other) {
        val -= other.val;
        if (val < 0) val += MOD;
        return *this;
    }

    // Operador *= (multiplicación modular)
    mint& operator*=(const mint& other) {
        val = val * other.val % MOD;
        return *this;
    }

    // Operador /= (división modular, usando inverso modular)
    mint& operator/=(const mint& other) {
        return *this *= other.inv();
    }

    // Inverso modular usando exponenciación rápida
    mint inv() const {
        return pow(MOD - 2); // Fermat's Little Theorem
    }

    // Exponenciación rápida
    mint pow(long long p) const {
        mint res = 1, base = val;
        while (p) {
            if (p & 1) res *= base;
            base *= base;
            p >>= 1;
        }
        return res;
    }

    // Operador + (suma)
    friend mint operator+(mint a, const mint& b) {
        return a += b;
    }

    // Operador - (resta)
    friend mint operator-(mint a, const mint& b) {
        return a -= b;
    }

    // Operador * (multiplicación)
    friend mint operator*(mint a, const mint& b) {
        return a *= b;
    }

    // Operador / (división)
    friend mint operator/(mint a, const mint& b) {
        return a /= b;
    }

    // Para imprimir el valor
    friend std::ostream& operator<<(std::ostream& os, const mint& m) {
        return os << m.val;
    }
};
