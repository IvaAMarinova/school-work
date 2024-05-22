 global ?lock@mutex@@QEAA_NXZ
    global ?unlock@mutex@@QEAAXXZ
    section .text

?lock@mutex@@QEAA_NXZ:
    lock bts word [rcx], 0
    mov al, 1
    sbb al, 0
    ret

?unlock@mutex@@QEAAXXZ:
    lock btr word [rcx], 0
    ret