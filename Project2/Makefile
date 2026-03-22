compilePMC : PMC.h
	gcc PMC.h -o PMC

compileDriver : compilePMC DriverCode.c
	gcc DriverCode.c -lm -o Driver

clean:
	rm -rf PMC Driver sine_wave.raw
