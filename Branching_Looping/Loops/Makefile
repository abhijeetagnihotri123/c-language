convertLabelForLoop: For_Loop.c sampleAssembly.s
	riscv64-unknown-elf-gcc -O0 -ggdb -nostdlib -march=rv32i -mabi=ilp32 -Wl,-TsampleAssembly.ld sampleAssembly.s For_Loop.c -o main.elf  
	riscv64-unknown-elf-objcopy -O binary main.elf main.bin

convertLabelWhileLoop: While_Loop.c sampleAssembly.s
	riscv64-unknown-elf-gcc -O0 -ggdb -nostdlib -march=rv32i -mabi=ilp32 -Wl,-TsampleAssembly.ld sampleAssembly.s While_Loop.c -o main.elf  
	riscv64-unknown-elf-objcopy -O binary main.elf main.bin


convertLabelDoWhileLoop: Do_While_Loop.c sampleAssembly.s
	riscv64-unknown-elf-gcc -O0 -ggdb -nostdlib -march=rv32i -mabi=ilp32 -Wl,-TsampleAssembly.ld sampleAssembly.s Do_While_Loop.c -o main.elf  
	riscv64-unknown-elf-objcopy -O binary main.elf main.bin


assemblyForLoop: For_Loop.c
# 	riscv64-unknown-elf-gcc -O0 -ggdb -nostdlib -march=rv32i -mabi=ilp32 -Wl,-TsampleAssembly.ld For_Loop.c -S  
	riscv64-unknown-elf-gcc -O0 -nostdlib -march=rv32i -mabi=ilp32 -Wl,-TsampleAssembly.ld For_Loop.c -S  

assemblyWhileLoop: While_Loop.c
# 	riscv64-unknown-elf-gcc -O0 -ggdb -nostdlib -march=rv32i -mabi=ilp32 -Wl,-TsampleAssembly.ld While_Loop.c -S  
	riscv64-unknown-elf-gcc -O0 -nostdlib -march=rv32i -mabi=ilp32 -Wl,-TsampleAssembly.ld While_Loop.c -S  

assemblyDoWhileLoop: Do_While_Loop.c
# 	riscv64-unknown-elf-gcc -O0 -ggdb -nostdlib -march=rv32i -mabi=ilp32 -Wl,-TsampleAssembly.ld Do_While_Loop.c -S  
	riscv64-unknown-elf-gcc -O0 -nostdlib -march=rv32i -mabi=ilp32 -Wl,-TsampleAssembly.ld Do_While_Loop.c -S  

machineCode: sampleAssembly.s sampleAssembly.ld
	riscv64-unknown-elf-gcc -O0 -ggdb -nostdlib -march=rv32i -mabi=ilp32 -Wl,-TsampleAssembly.ld sampleAssembly.s -o main.elf
	riscv64-unknown-elf-objcopy -O binary main.elf main.bin
	

printBinary: main.bin
	xxd -e -c 4 -g 4 main.bin

startQEMU: main.elf
	qemu-system-riscv32 -S -M virt -nographic -bios none -kernel main.elf -gdb tcp::1234

connectGDB: main.elf
	gdb-multiarch main.elf -ex "target remote localhost:1234" -ex "break _start" -ex "continue" -q

clean: 
	rm -rf *.out *.bin *.elf .gdb_history For_Loop.s While_Loop.s Do_While_Loop.s 