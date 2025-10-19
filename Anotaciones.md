# C++ Anotaciones

Aquí estaremos viendo algunas anotaciones sobre atajos y bugs comunes usando C++ para programación competitiva.

### Bitwise operations
Uno de los atajos más comunes en operaciones bitwise son estos:
```c++
__builtin_clz(x) // the number of zeros at the beginning of the number
__builtin_ctz(x) // the number of zeros at the end of the number
__builtin_popcount(x) // the number of ones in the number
__builtin_parity(x) // the parity (even or odd) of the number of ones

// Ejemplo:
int x = 5328; // 00000000000000000001010011010000
cout << __builtin_clz(x) << "\n"; // 19
cout << __builtin_ctz(x) << "\n"; // 4
cout << __builtin_popcount(x) << "\n"; // 5
cout << __builtin_parity(x) << "\n"; // 1
```
