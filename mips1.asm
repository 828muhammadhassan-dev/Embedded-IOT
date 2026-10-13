# Hello World Program in MIPS Assembly

.data
msg: .asciiz "Hello, MIPS!"

.text
.globl main

main:
    li   $v0, 4          # Syscall 4: print_string
    la   $a0, msg        # Load address of msg into $a0
    syscall

    li   $v0, 10         # Syscall 10: exit program
    syscall