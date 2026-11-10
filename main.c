#include <stdio.h>
#include <stdlib.h>

void input_matrix(int rows, int cols, int matrix[rows][cols]) {
  for (int i = 0; i < rows; i++) {
    for (int j = 0; j < cols; j++) {
      printf("Masukkan nilai [%d][%d] : ", (i + 1), (j + 1));
      scanf("%d", &matrix[i][j]);
    }
  }
}

int get_padding_size(int rows, int cols, int matrix[rows][cols]) {
  int padding = 0;

  for (int i = 0; i < rows; i++) {
    for (int j = 0; j < cols; j++) {
      char buf[20];
      int k = snprintf(buf, sizeof(buf), "%d", matrix[i][j]);

      if (padding < k) {
        padding = k;
      }
    }
  }

  return padding;
}

void add(int layers, int rows, int cols, int result_matrix[rows][cols],
         int (*matrixs[layers])[cols]) {

  for (int i = 0; i < rows; i++) {
    for (int j = 0; j < cols; j++) {
      result_matrix[i][j] = 0;
    }
  }

  for (int i = 0; i < layers; i++) {
    for (int j = 0; j < rows; j++) {
      for (int k = 0; k < cols; k++) {
        result_matrix[j][k] = result_matrix[j][k] + matrixs[i][j][k];
      }
    }
  }
}

void subtract(int layers, int rows, int cols, int result_matrix[rows][cols],
              int (*matrixs[layers])[cols]) {
  for (int i = 0; i < rows; i++) {
    for (int j = 0; j < cols; j++) {
      result_matrix[i][j] = matrixs[0][i][j];
    }
  }

  for (int i = 1; i < layers; i++) {
    for (int j = 0; j < rows; j++) {
      for (int k = 0; k < cols; k++) {
        result_matrix[j][k] -= matrixs[i][j][k];
      }
    }
  }
}

void multiply(int layers, int rows, int cols, int result_matrix[rows][cols],
              int (*matrixs[layers])[cols]) {
  for (int i = 0; i < rows; i++) {
    for (int j = 0; j < cols; j++) {
      result_matrix[i][j] = matrixs[0][i][j];
    }
  }

  for (int i = 1; i < layers; i++) {
    for (int j = 0; j < rows; j++) {
      for (int k = 0; k < cols; k++) {
        result_matrix[j][k] *= matrixs[i][j][k];
      }
    }
  }
}

void divide(int layers, int rows, int cols, int result_matrix[rows][cols],
            int (*matrixs[layers])[cols]) {
  for (int i = 0; i < rows; i++) {
    for (int j = 0; j < cols; j++) {
      result_matrix[i][j] = matrixs[0][i][j];
    }
  }

  for (int i = 1; i < layers; i++) {
    for (int j = 0; j < rows; j++) {
      for (int k = 0; k < cols; k++) {
        if (matrixs[i][j][k] == 0) {
          fprintf(stderr, "Tidak bisa membagi dengan 0\n");
          exit(1);
        }
        result_matrix[j][k] /= matrixs[i][j][k];
      }
    }
  }
}

void print_result(int layers, int rows, int cols, int (*matrixs[layers])[cols],
                  int option) {
  for (int i = 0; i < rows; i++) {
    for (int j = 0; j < layers; j++) {
      printf("[ ");
      for (int k = 0; k < cols; k++) {
        printf("%*d ", get_padding_size(rows, cols, matrixs[j]),
               matrixs[j][i][k]);
      }
      printf("] ");

      int middle = 0;
      if (rows % 2 == 0) {
        middle = rows / 2;
      } else {
        middle = rows / 2 + 1;
      }

      if ((i + 1) == middle && j < (layers - 2)) {
        if (option == 1) {
          printf("+ ");
        } else if (option == 2) {
          printf("- ");
        } else if (option == 3) {
          printf("* ");
        } else if (option == 4) {
          printf("/ ");
        }
      } else if ((i + 1) == middle && j == (layers - 2)) {
        printf("= ");
      } else {
        printf("  ");
      }
    }
    printf("\n");
  }
}

int main() {
  int m, n, count, option;

  printf("Masukkan jumlah matriks : ");
  scanf("%d", &count);

  if (count <= 0) {
    printf("jumlah matriks harus minimal 1");
    return 1;
  }

  printf("Masukkan panjang baris matriks : ");
  scanf("%d", &m);

  printf("Masukkan panjang kolom matriks : ");
  scanf("%d", &n);

  if (m <= 0 || n <= 0) {
    printf("Dimensi matriks tidak masuk akal");
    return 1;
  }

  printf("\n");

  int result_matrix[m][n];
  int alloc_mem_matrix[count][m][n];
  int (*matrixs[count])[n];

  // storage for the matrixs pointer
  // should've used malloc but I haven't learn it yet
  // I hate c for this
  for (int i = 0; i < count; i++) {
    matrixs[i] = alloc_mem_matrix[i];
  }

  for (int i = 0; i < count; i++) {
    printf("Matriks %d\n", i + 1);
    printf("====================================\n");
    input_matrix(m, n, matrixs[i]);
    printf("\n");
  }

  printf("==== Pilih Operasi ====\n");
  printf("1. Tambah (+) \n");
  printf("2. Kurang (-) \n");
  printf("3. Kali (*) \n");
  printf("4. Bagi (/) \n");
  printf("Masukkan pilihan : ");
  scanf("%d", &option);

  switch (option) {
  case 1:
    add(count, m, n, result_matrix, matrixs);
    break;
  case 2:
    subtract(count, m, n, result_matrix, matrixs);
    break;
  case 3:
    multiply(count, m, n, result_matrix, matrixs);
    break;
  case 4:
    divide(count, m, n, result_matrix, matrixs);
    break;
  default:
    printf("Invalid Option");
    return 1;
    break;
  }

  printf("\n");

  printf("==========================================================\n");
  printf("                          Hasil\n");
  printf("==========================================================\n");
  int (*print_matrixs[count + 1])[n];

  for (int i = 0; i < count; i++) {
    print_matrixs[i] = matrixs[i];
  }
  print_matrixs[count] = result_matrix;

  print_result(count + 1, m, n, print_matrixs, option);

  return 0;
}
