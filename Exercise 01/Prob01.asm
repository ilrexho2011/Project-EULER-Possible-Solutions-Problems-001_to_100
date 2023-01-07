; for each integer from 1 to 1000
	mov ecx, 3

	mov esi, 3
	mov edi, 5

	xor ebx, ebx	; sum

_0:	mov eax, ecx
	xor edx, edx
	div esi
	test edx, edx
	je _yes

	mov eax, ecx
	xor edx, edx
	div edi
	test edx, edx
	jne _no

_yes:	add ebx, ecx

_no:	inc ecx
	cmp ecx, 1000
	jne _0
