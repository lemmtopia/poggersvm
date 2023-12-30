/*
  What we need:
  - CPU with an ALU and registers
  - Program counter
  - Memory
  - I/O
*/

#include <stdio.h>
#include <stdint.h>

#define STACK_SIZE 1024

typedef struct
{
    uint32_t stack[STACK_SIZE]; 
    uint32_t sp;
} vm_t;

void print_vm(vm_t vm)
{
    for (int i = 0; i < vm.sp; i++)
    {
        printf("%2x ", vm.stack[i]);
    }
    
    printf("\n");
}

void vm_push(vm_t *vm, uint32_t value)
{
    vm->stack[vm->sp] = value;
    vm->sp++;
}

void vm_pop(vm_t *vm)
{
    if (vm->sp > 0)
    {
        vm->sp--;
    }
}

int main(void)
{
    vm_t vm;
    print_vm(vm);
    vm_push(&vm, 0x69);
    print_vm(vm);
    vm_push(&vm, 0x69);
    print_vm(vm);
    vm_pop(&vm);
    print_vm(vm);
    return 0;
}
