; array_sum_asm function							(ArraySumAsm.asm)

.586
.model flat, C
array_sum_asm Proto, arrayPtr:Ptr DWord, count:DWord

.code
;------------------------------------------------------------------------------
; Calculates the sum of an array of 32-bit integers.
; Receives: arrayPtr - pointer to the array, count - number of the array
;			elements.
; Returns: eax - sum of the array elements.
;------------------------------------------------------------------------------
array_sum_asm Proc Uses ecx esi, arrayPtr:Ptr DWord, count:DWord
	xor eax,eax
	mov esi,arrayPtr
	mov ecx,count

	L1:
		add eax,[esi]
		add esi,Type DWord
	Loop L1

	ret
array_sum_asm EndP
End
