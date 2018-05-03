global _main 
extern _scanf 
extern _printf 
segment .data 
formatin: db "%s", 0 
segment .bss 
id: resb 10 
segment .text 
	_main: 
push id 
push formatin 
call _scanf 
add esp, 8 
ret