global ??Eatomic@@QEAA_KXZ
	global ??Fatomic@@QEAA_KXZ
	global ??4atomic@@QEAAAEAU0@_K@Z
	global	??Yatomic@@QEAAAEAU0@AEAU0@@Z
	global ??Zatomic@@QEAAAEAU0@AEAU0@@Z
	global ??Xatomic@@QEAAAEAU0@AEAU0@@Z
	global ??_0atomic@@QEAAAEAU0@AEAU0@@Z
	section .text

; ++x
??Eatomic@@QEAA_KXZ: 
	lock inc qword [rcx]
	ret

; --x
??Fatomic@@QEAA_KXZ: 
	lock dec qword [rcx]
	ret

; x=
??4atomic@@QEAAAEAU0@_K@Z
	lock xchg qword [rcx], rdx
	ret

; x +=
??Yatomic@@QEAAAEAU0@AEAU0@@Z:
	lock xchg [rdx], rax
	lock add [rcx], rax
    lock xchg [rdx], rax
    ret

; x -=
??Zatomic@@QEAAAEAU0@AEAU0@@Z:
    lock xchg [rdx], rax
    neg rax
	lock add [rcx], rax
	neg rax
	lock xchg [rdx], rax
    ret

; x *=
??Xatomic@@QEAAAEAU0@AEAU0@@Z:
    lock xchg [rcx], rax
	lock xchg [rdx], r8
    imul rax, r8
	lock xchg [rdx], r8
    lock xchg [rcx], rax
    ret

; x /=
??_0atomic@@QEAAAEAU0@AEAU0@@Z:
    lock xchg [rcx], rax
    lock xchg [rdx], r10

    cmp r10, 0
    je return  

	mov r11, rdx
    xor rdx, rdx  
    idiv r10
	mov rdx, r11
	lock xchg [rcx], rax
    lock xchg [rdx], r10

return:
	ret