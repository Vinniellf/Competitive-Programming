#include <bits/stdc++.h>

using namespace std;

float hexToFloat(uint32_t hexValue) {
    float result;
    memcpy(&result, &hexValue, sizeof(result));
    return result;
}

uint32_t floatToHex(float floatValue) {
    uint32_t result;
    memcpy(&result, &floatValue, sizeof(result));
    return result;
}

uint32_t bitwiseNAND(uint32_t a, uint32_t b) {
    return ~(a & b);
}

float fusedMultiplyAdd(float a, float b, float c) {
    return fma(a, b, c); // En C++17 o superior
}

int main() {
    int T;
    cin >> T;

    while (T--) {
        string hexValue;
        cin >> hexValue;

        uint32_t C0_hex = stoul(hexValue, nullptr, 16);
        vector<float> C = { hexToFloat(C0_hex) }; 

        int L;
        cin >> L;
        vector<vector<float>> LUT(L);

        for (int i = 0; i < L; i++) {
            int size;
            cin >> size;
            LUT[i].resize(size);

            for (int j = 0; j < size; j++) {
                string lutHex;
                cin >> lutHex;
                LUT[i][j] = hexToFloat(stoul(lutHex, nullptr, 16));
            }
        }

        int Q;
        cin >> Q;

        for (int q = 0; q < Q; q++) {
            string command;
            cin >> command;

            if (command == "L") {
                int i, j, b;
                cin >> i >> j >> b;

                uint32_t mask = (C0_hex >> j) & ((1 << b) - 1); 
                C.push_back(LUT[i][mask]);

            } else if (command == "N") {
                int i, j;
                cin >> i >> j;

                uint32_t nandResult = bitwiseNAND(floatToHex(C[i]), floatToHex(C[j]));
                C.push_back(hexToFloat(nandResult));

            } else if (command == "F") {
                int i, j, k;
                cin >> i >> j >> k;

                float fmaResult = fusedMultiplyAdd(C[i], C[j], C[k]);
                C.push_back(fmaResult);

            } else if (command == "C") {
                string h;
                cin >> h;

                uint32_t constHex = stoul(h, nullptr, 16);
                C.push_back(hexToFloat(constHex));
            }
        }

        cout << hex  << floatToHex(C.back()) << endl;
    }

    return 0;
}
