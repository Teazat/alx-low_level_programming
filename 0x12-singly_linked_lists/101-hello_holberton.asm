section .data
    hello db "Hello, Holberton,", 0
    newline db 10, 0
    format db "%s", 0

section .text
    global main
    extern printf

main:
    mov edi, format
    xor eax, eax
    call printf

    mov edi, format
    mov rsi, hello
    call printf

    xor eax, eax
    ret
