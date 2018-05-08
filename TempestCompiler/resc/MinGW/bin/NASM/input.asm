global _main 
extern _scanf 
extern _printf
segment .data 
scanIn: db "%s", 0 
msg: db "Hello World!", 0xA, 0xD, 0 
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

	print: 
push msg 
call _printf 
add esp, 4 
	ret 
	code: 
call print

call pause 
ret