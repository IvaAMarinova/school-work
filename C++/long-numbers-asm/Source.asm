 global add
    global sub
    global neg
    global mul
    section .text

add:
    mov r12, 0
    mov r13, 0

add_loop:
    mov rax, 0
    
    mov rax, [rdx] 
    add rax, r13 ; carry flag

    ;if add overflows because of r13 carry flag
    mov r12, 0
    adc r12, 0

    add rax, [r8]
    
    ;if add overflows because of r8 addition
    mov r11, 0
    adc r11, 0

    ;r13 - sum of carry flags that if necessary should be added
    mov r13, 0
    add r13, r12
    add r13, r11

    mov [rcx], rax

    add rdx, 8
    add r8, 8
    add rcx, 8

    dec r9
    cmp r9, 0
    je return
    jne add_loop

sub:
    mov rax, 0


sub_loop:
    mov rax, [rdx] 
    sub rax, r13 ; borrow flag

    ;if sub borrows because of r13 borrow flag
    mov r12, 0
    adc r12, 0

    sub rax, [r8]
    
    ;if sub borrows because of r8 subtraction
    mov r11, 0
    adc r11, 0

    ;r13 - sum of borrow flags that if necessary should be added
    mov r13, 0
    add r13, r12
    add r13, r11

    mov [rcx], rax

    add rdx, 8
    add r8, 8
    add rcx, 8

    dec r9
    cmp r9, 0
    je return
    jne sub_loop

neg:
    mov rax, [rdx]
    not rax
    inc rax
    mov [rcx], rax

    add rdx, 8
    add rcx, 8

    dec r8
    cmp r8, 0
    je return
    jne neg

mul:
    ;opitah se!
    ;no mai ne trqbvashe da pravq tova
    mov rax, [rdx]
    imul rax, [r8]
    mov [rcx], rax

    add rdx, 8
    add rcx, 8
    add r8, 8

    dec r9
    cmp r9, 0
    je return
    jne mul

return:
    ret