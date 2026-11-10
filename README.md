# C implementation of my college matrix algorithm assignment

I wrote this because I was bored, should've used malloc but I have not learn it yet lol.

## Prerequisites

| Tool | Version |
| ---- | ------- |
| gcc  | c99     |

## Run Command

```bash
gcc main.c -o main && ./main
```

## Output Example

```bash

gcc main.c -o main && ./main
Masukkan jumlah matriks : 3
Masukkan panjang baris matriks : 3
Masukkan panjang kolom matriks : 3

Matriks 1
====================================
Masukkan nilai [1][1] : 32
Masukkan nilai [1][2] : 43
Masukkan nilai [1][3] : 21
Masukkan nilai [2][1] : 1
Masukkan nilai [2][2] : 43
Masukkan nilai [2][3] : 653
Masukkan nilai [3][1] : 54
Masukkan nilai [3][2] : 2
Masukkan nilai [3][3] : 4

Matriks 2
====================================
Masukkan nilai [1][1] : 34
Masukkan nilai [1][2] : 1
Masukkan nilai [1][3] : 43
Masukkan nilai [2][1] : 4
Masukkan nilai [2][2] : 54
Masukkan nilai [2][3] : 6
Masukkan nilai [3][1] : 4
Masukkan nilai [3][2] : 54
Masukkan nilai [3][3] : 2

Matriks 3
====================================
Masukkan nilai [1][1] : 4
Masukkan nilai [1][2] : 34
Masukkan nilai [1][3] : 1
Masukkan nilai [2][1] : 43
Masukkan nilai [2][2] : 87
Masukkan nilai [2][3] : 7
Masukkan nilai [3][1] : 65
Masukkan nilai [3][2] : 4
Masukkan nilai [3][3] : 3

==== Pilih Operasi ====
1. Tambah (+)
2. Kurang (-)
3. Kali (*)
4. Bagi (/)
Masukkan pilihan : 1

==========================================================
                          Hasil
==========================================================
[  32  43  21 ]   [ 34  1 43 ]   [  4 34  1 ]   [  70  78  65 ]
[   1  43 653 ] + [  4 54  6 ] + [ 43 87  7 ] = [  48 184 666 ]
[  54   2   4 ]   [  4 54  2 ]   [ 65  4  3 ]   [ 123  60   9 ]
```

## Future Improvement

1. add dynamic yes/no when adding a new matrix so you should not define it first
2. make matrix with different size possible (ex. [[3x2]] + [[2x3]])
3. use malloc

<p align="center">
  <img src="./NO_MALLOC_.png" alt="Description" width="300">
</p>
