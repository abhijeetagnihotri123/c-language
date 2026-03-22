convertLabel: SwitchCase.c sampleAssembly.s
	riscv64-unknown-elf-gcc -O0 -ggdb -nostdlib -march=rv32i -mabi=ilp32 -Wl,-TsampleAssembly.ld sampleAssembly.s SwitchCase.c -o main.elf  
	riscv64-unknown-elf-objcopy -O binary main.elf main.bin

assembly: SwitchCase.c
# 	riscv64-unknown-elf-gcc -O0 -ggdb -nostdlib -march=rv32i -mabi=ilp32 -Wl,-TsampleAssembly.ld SwitchCase.c -S  
	riscv64-unknown-elf-gcc -O0 -nostdlib -march=rv32i -mabi=ilp32 -Wl,-TsampleAssembly.ld SwitchCase.c -S  

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
	rm -rf *.out *.bin *.elf .gdb_history SwitchCase.s