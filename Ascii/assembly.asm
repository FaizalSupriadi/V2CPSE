.cpu cortex-m0
.text
.align 2
.global print_asciz

print_asciz:
   PUSH { r5, lr }
   MOV r5, r0 
loop:
   LDRB r0, [ r5 ]
   ADD r0, r0, #0
   BEQ done
   BL uart_put_char
   ADD r5,r5,#1
   b loop
done:
   pop { r5, pc }
