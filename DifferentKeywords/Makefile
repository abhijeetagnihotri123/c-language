compileAuto : AutoDemo.c
	gcc AutoDemo.c -o AutoDemo

compileRegister : Register.c
	gcc Register.c -o Register

convertToRiscVAssemblyRegister : Register.c
	riscv64-unknown-elf-gcc -S Register.c

compileExtern : Extern.c SomeOtherFile.c
	gcc Extern.c SomeOtherFile.c -o Extern


compileStatic : StaticDemo.c
	gcc StaticDemo.c -o Static


clean :  
	rm AutoDemo Register Extern Static *.s