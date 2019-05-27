# 4-uzd

### 2) Analizė

#### ``` vector<int> ```

Sukuriami vektoriai ir užpildomi int reikšmėmis [0 ; dydis)

| KONTEINERIS\DYDIS |  1 000   |  10 000  |  100 000  | 1 000 000 | 10 000 000 |
| ----------------- | -------- | -------- | --------- | --------- | ---------- |
| STD::VECTOR       | 0.001002 | 0.000965 | 0.003989  | 0.027925  |  0.203256  |
| CUSTOM VECTOR     | 0.000276 | 0.000963 | 0.008976  | 7.590750  |   1233.72  |


### 3) Atminties perskirstymas
 
 std::vector<int> 21 karta
# 
 custom vector 1000 kartų
 
 
