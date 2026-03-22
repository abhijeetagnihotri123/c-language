createBinary: Operators.c	
	gcc -o Operators Operators.c

createBinaryRelation: RelationalOperators.c
	gcc RelationalOperators.c -o RelationalOperators

createBitwiseShiftOperations: BitwiseShiftOperations.c
	gcc BitwiseShiftOperations.c -o BitwiseShiftOperations


convertLabelArithemetic: Operators.c sampleAssembly.s
	riscv64-unknown-elf-gcc -O0 -ggdb -nostdlib -march=rv32i -mabi=ilp32 -Wl,-TsampleAssembly.ld sampleAssembly.s Operators.c -o main.elf  
	riscv64-unknown-elf-objcopy -O binary main.elf main.bin


convertLabelRelational: RelationalOperators.c sampleAssembly.s
	riscv64-unknown-elf-gcc -O0 -ggdb -nostdlib -march=rv32i -mabi=ilp32 -Wl,-TsampleAssembly.ld sampleAssembly.s RelationalOperators.c -o main.elf  
	riscv64-unknown-elf-objcopy -O binary main.elf main.bin

convertLabelBitwise: BitwiseShiftOperations.c sampleAssembly.s
	riscv64-unknown-elf-gcc -O0 -ggdb -nostdlib -march=rv32i -mabi=ilp32 -Wl,-TsampleAssembly.ld sampleAssembly.s BitwiseShiftOperations.c -o main.elf  
	riscv64-unknown-elf-objcopy -O binary main.elf main.bin

convertLabelLogical: LogicalOperators.c sampleAssembly.s
	riscv64-unknown-elf-gcc -O0 -ggdb -nostdlib -march=rv32i -mabi=ilp32 -Wl,-TsampleAssembly.ld sampleAssembly.s LogicalOperators.c -o main.elf  
	riscv64-unknown-elf-objcopy -O binary main.elf main.bin


assemblyArithemetic: Operators.c
# 	riscv64-unknown-elf-gcc -O0 -ggdb -nostdlib -march=rv32i -mabi=ilp32 -Wl,-TsampleAssembly.ld sampleCProgram.c -S  
# 	riscv64-unknown-elf-gcc -O0 -nostdlib -march=rv32i -mabi=ilp32 -Wl,-TsampleAssembly.ld Operators.c -S  
# 	rv32im will generate multiplication instructions as well, so we need to specify that in the command line
	riscv64-unknown-elf-gcc -O0 -nostdlib -march=rv32im -mabi=ilp32 -Wl,-TsampleAssembly.ld Operators.c -S  

assembleRelationalOperators: RelationalOperators.c
	riscv64-unknown-elf-gcc -O0 -nostdlib -march=rv32i -mabi=ilp32 -Wl,-TsampleAssembly.ld RelationalOperators.c -S 

assemblyBitwiseShiftOperations: BitwiseShiftOperations.c
	riscv64-unknown-elf-gcc -O0 -nostdlib -march=rv32i -mabi=ilp32 -Wl,-TsampleAssembly.ld BitwiseShiftOperations.c -S 
	

assemblyLogicalOperators: LogicalOperators.c
	 riscv64-unknown-elf-gcc -O0 -nostdlib -march=rv32i -mabi=ilp32 -Wl,-TsampleAssembly.ld LogicalOperators.c -S

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
	rm -rf *.out *.bin *.elf *.gdb_history Operators.s RelationalOperators.s LogicalOperators.s RelationalOperators BitwiseShiftOperations.s BitwiseShiftOperations