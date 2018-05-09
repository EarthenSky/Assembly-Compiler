global _main 
extern _scanf 
extern _printf
segment .data 
scanIn: db "%s", 0 
printMsg0: db "Hello World!", 0xA, 0xD, 0 
printMsg1: db "Hello World!  Again!", 0xA, 0xD, 0 
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
push printMsg0 
call _printf 
add esp, 4 
push printMsg1 
call _printf 
add esp, 4 

call pause 
ret