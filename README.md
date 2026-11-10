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
Masukkan nilai [1][1] : 54
Masukkan nilai [1][2] : 2
Masukkan nilai [1][3] : 3
Masukkan nilai [2][1] : 6
Masukkan nilai [2][2] : 4
Masukkan nilai [2][3] : 3
Masukkan nilai [3][1] : 12
Masukkan nilai [3][2] : 4
Masukkan nilai [3][3] : 6

Matriks 2
====================================
Masukkan nilai [1][1] : 4
Masukkan nilai [1][2] : 7
Masukkan nilai [1][3] : 87
Masukkan nilai [2][1] : 12
Masukkan nilai [2][2] : 4
Masukkan nilai [2][3] : 4
Masukkan nilai [3][1] : 5
Masukkan nilai [3][2] : 6
Masukkan nilai [3][3] : 8

Matriks 3
====================================
Masukkan nilai [1][1] : 4
Masukkan nilai [1][2] : 5
Masukkan nilai [1][3] : 34
Masukkan nilai [2][1] : 7
Masukkan nilai [2][2] : 6
Masukkan nilai [2][3] : 32
Masukkan nilai [3][1] : 5
Masukkan nilai [3][2] : 4
Masukkan nilai [3][3] : 1

==== Pilih Operasi ====
1. Tambah (+)
2. Kurang (-)
3. Kali (*)
4. Bagi (/)
Masukkan pilihan : 1

==========================================================
                          Hasil
==========================================================
[ 54  2  3 ]   [  4  7 87 ]   [  4  5 34 ]   [  62  14 124 ]
[  6  4  3 ] + [ 12  4  4 ] + [  7  6 32 ] = [  25  14  39 ]
[ 12  4  6 ]   [  5  6  8 ]   [  5  4  1 ]   [  22  14  15 ]
```

## Future Improvement

1. add dynamic yes/no when adding a new matrix so you should not define it first
2. make matrix with different multiplication size possible (ex. [3x2] + [2x3])
3. fix matrix division with float and not int
4. use malloc

<p align="center">
  <img src="./NO_MALLOC_.png" alt="Description" width="300">
</p>
