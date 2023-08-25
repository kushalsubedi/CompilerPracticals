;understanding Assembly codes
global _start
_start:
;using linux exit syscall 
    mov rax, 60 
    mov rdi, 69 ; rdi is just 8 byte
    syscall

; we are just moking HLL C code 
; int main(void) {return 0; }
 
; output
;❯ nasm -felf64 test.asm
;❯ ld test.o -o test
;❯ ls
;test  test.asm  test.o
;❯ ./test
;❯ echo $?
;69 (we get the syscall register)



