    default rel
    global hello

    section .text
hello:
    lea rax, [msg]
    ret


    section .rodata
msg:
    db "Hello, World!", 0
