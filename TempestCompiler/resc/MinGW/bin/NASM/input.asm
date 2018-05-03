global _main 
extern _scanf 
segment .data 
scanIn: db "%s", 0 
segment .bss 
id: resb 10 
segment .text 
	_main: 

jmp code 

	pause: 
push id 
push scanIn 
call _scanf 
add esp, 8 
	ret 

	code: 
call pause 
call pause 

ret