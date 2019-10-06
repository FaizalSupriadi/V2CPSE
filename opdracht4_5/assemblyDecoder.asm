.cpu cortex-m0
.bss
	Array: .fill 0x28 
.text
.align 2
.global decompress

decompress:
	PUSH { r4, r5, r6, r7, lr }		//Push all registers onto the stack

	LDR r3,	=Array		//Load bufferArray into R3
 	LDR r4, =message			//Load message into R4
	MOV r5, #0					//R5 is the index pointer
decompressionLoop:
	LDRB r0, [ r4, r5 ]			//A character is message data with the index pointer
	
	ADD r5, #1					
		
	CMP r0, #0
	BEQ done					//If r0 is zero, go to done

	CMP r0, #'@'
	BEQ decode 				//If r0 is @, go to decode

	BL buffer					//If r0 is not @ got to buffer
	BL print					//Print the character
	b decompressionLoop		//Continue with loop


buffer:
	PUSH { lr }
	MOV r1, #0x27				//bufferlength is 39
bufferLoop:
	SUB r1,  #1				//R1 = i-1
	LDRB r2, [ r3, r1 ]			//R2 contains the the newly loaded character

	ADD r1,  #1				//Revert the subtraction
	STRB r2, [ r3, r1 ]			//Store the loaded char from R2 in R3

	SUB r1, #1				

	CMP r1, #0
	BGT bufferLoop			//If r1 is still greater, go again.

	STRB r0, [ r3, #0 ]			//Store r0 in r3 at index 0
	POP { pc }					//Go back


decode:
	LDRB r6, [ r4, r5 ]			//Load r4 at index r5 into r6
	ADD r5,  #1				

 	LDRB r7, [ r4, r5 ]			//Load r4 at index r5 into r7
 	ADD r5,  #1				

 	SUB r6, #'0'				//Subtract 0
 	SUB r7,  #'0'
decodeLoop:
	LDRB r0, [ r3, r6 ]			//Load r3 at index r6 in r0
	BL buffer
	BL print					//Print the character
	SUB r7, #1				
	BLE decompressionLoop	//Check if we're done
	B decodeLoop				//If not we go again
done:
	POP { r4, r5, r6, r7, pc }