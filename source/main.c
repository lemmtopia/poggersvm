/*
  What we need:
  - CPU with an ALU and registers
  - Program counter
  - Memory
  - I/O
*/

#include <stdio.h>

#define OPCODE_ADD 69
#define OPCODE_SUB 420

typedef struct
{
     int a, b, y;
     int opcode;
     unsigned char carry, zero, negative;
} alu_t;

alu_t alu;

void alu_execute()
{
     switch (alu.opcode)
     {
     case OPCODE_ADD:
	  alu.y = alu.a + alu.b;
	  alu.zero = alu.y == 0;
	  alu.negative = alu.y < 0;
	  break;
     case OPCODE_SUB:
	  alu.y = alu.a - alu.b;
	  alu.zero = alu.y == 0;
	  alu.negative = alu.y < 0;
	  break;
     }
}

void print_alu()
{
     printf("a=%d b=%d y=%d\n", alu.a, alu.b, alu.y);
     printf("zero=%d\tnegative=%d\n", alu.zero, alu.negative);
}

int main(void)
{
     scanf("%d", &alu.opcode);
     scanf("%d", &alu.a);
     scanf("%d", &alu.b);
     
     alu_execute();
     print_alu();
     
     return 0;
}
