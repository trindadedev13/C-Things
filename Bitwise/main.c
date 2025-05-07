#include <stdio.h>
#include <stdint.h>

typedef uint8_t byte;
typedef char* string;

#define YELLOW "\033[0;33m"
#define RESET "\033[0m"

static void printbits(byte num) {
  //printf("Bits: ");
  size_t size = sizeof(byte);
  byte maxPow = 1 << (size * 8 - 1);
  printf("%s", YELLOW);
  for(int i = 0; i < size * 8; ++i) {
    printf("%u",num & maxPow ? 1 : 0);
    if ((i + 1) % 4 == 0) {
      printf(" ");
    }
    num = num << 1;
  }
  printf("%s\n", RESET);
}

int main() {
  byte bits = 5;  // 0000 0101
  
  printf("\n");
  printf("Bits:\n");
  printbits(bits);
  printf("Valor inicial: %u\n", bits);
  
  // Operador << (Shift Left)
  // Desloca os bits de 'a' para a esquerda 'b' posição/posições 
  // exemplo:
  // a      => 0000 0101  (5 em decimal)
  // a << 1 => 0000 1010  (10 em decimal)
  // Equivale a multiplicar por 2 a cada deslocamento
  printf("\n");
  printf("Operador Shift Left (<<)\n");
  bits = (bits << 1);
  printf("Bits:\n");
  printbits(bits);
  printf("Decimal: %u\n", bits);
  
  // Operador >> (Shift right)
  // Desloca os bits de 'a' para a direita 'b' posição/posições
  // exemplo:
  // a      => 0000 1010 (10 em decimal)
  // a >> 1 => 0000 0101 (5 em decimal)
  // Equivale a dividir por 1 a cada deslocamento
  printf("\n");
  printf("Operador Shift Right (>>)\n");
  bits = (bits >> 1);
  printf("Bits:\n");
  printbits(bits);
  printf("Decimal: %u\n", bits);
  
  // Operador | (OR)
  // mescla os bits da variavel bits (0000 0001)
  // exemplo:
  // primeiro => 0000 0101
  // segundo  => 0010 0000
  // final    => 0010 0101
  printf("\n");
  printf("Operador OR (|)\n");
  bits |= (1 << 5);
  printf("Bits:\n");
  printbits(bits);
  printf("Decimal: %u\n", bits);
  
  // Operador & (AND)
  // verifica bit por bit
  // se o bit do primeiro for igual o bit do segundo então 1 caso contrario 0
  // exemplo:
  // primeiro =>  0010 0101
  // segundo  =>  0010 0000
  // final    =>  0010 0000
  printf("\n");
  printf("Operador AND (&)\n");
  bits &= (1 << 5);
  printf("Bits:\n");
  printbits(bits);
  printf("Decimal: %u\n", bits);
  
  // Operador ~ NOT
  // basicamente inverte tudo
  // exemplo:
  // primeiro => 0010 0000
  // segundo  => 0010 0000
  // final    => 1101 1111
  printf("\n");
  printf("Operador NOT (~)\n");
  bits = ~(1 << 5);
  printf("Bits:\n");
  printbits(bits);
  printf("Decimal: %u\n", bits);
  
  // Operador ^ (XOR)
  // verifica bit por bit
  // se os bits forem diferentes, resultado é 1
  // se forem iguais, resultado é 0
  // exemplo:
  // primeiro  => 1101 1111
  // segundo   => 1111 1111
  // final     => 0010 0000
  printf("\n");
  printf("Operador XOR (^)\n");
  bits = bits ^ (1 << 5);
  printf("Bits:\n");
  printbits(bits);
  printf("Decimal: %u\n", bits);
  
  printf("\n");
  string str = "Programador";
  printf("String %s\n", str);
  printf("Bits:\n");
  for (int i = 0; str[i] != '\0'; i++) {
    printbits((byte) str[i]);
  }
  
  return 0;
}
