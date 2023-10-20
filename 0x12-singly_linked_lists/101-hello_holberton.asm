section .data
    hello db "Hello, Holberton", 10, 0 ; The string to be printed (including a newline character)

section .text
    global _start

_start:
    ; Call printf
    push rbp
    mov rdi, hello
    call printf
    pop rbp

    ; Exit the program
    mov rax, 60         ; syscall number for exit (60)
    xor rdi, rdi        ; status: 0
    syscall

