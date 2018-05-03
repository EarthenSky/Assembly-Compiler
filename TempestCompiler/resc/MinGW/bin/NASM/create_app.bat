cd ../resc/MinGW/bin/NASM

set /p outFileName=Input name of file (do not include .exe): 

nasm -f win32 input.asm -o output.obj

MOVE output.obj ..\%outFileName%.obj 

cd ..

gcc %outFileName%.obj -o %outFileName%.exe

MOVE %outFileName%.obj ../../../output
MOVE %outFileName%.exe ../../../output

PAUSE