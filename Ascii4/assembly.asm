.cpu cortex-m0
.text
.align 2
.global print_asciz, convert, application

print_asciz:
   PUSH { r5, lr }
   MOV r5, r0 
loop:
   LDRB r0, [ r5 ]
   ADD r0, r0, #0
   BEQ done
   BL convert
   BL uart_put_char
   ADD r5,r5,#1
   b loop
done:
   POP { r5, pc }
   
convert:
   PUSH { r5, lr }
   mov r5, R0
   CMP r5, #97
   BGE upper
   CMP r5, #65
   BGE lower
   B done2
lower:
   CMP r5, #90
   BGT done2
   ADD r5, #32
   B done2
upper:
   CMP r5, #122
   BGT done2
   SUB r5, #32
   b done2  
done2:
   MOV r0, r5
   POP { r5, pc }

application:
   PUSH { LR }
   LDR R0, = message
   BL print_asciz
   POP { PC }
message:
   .asciz "Hello world, the ANSWER is 42! @[]'()~\n"
   