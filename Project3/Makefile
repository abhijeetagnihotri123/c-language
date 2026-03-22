SensorTypesCompile : SensorTypes.h
	gcc SensorTypes.h -o SensorTypes

SensorDefCompile : SensorTypesCompile SensorDef.h
	gcc SensorDef.h -o SensorDef

CompileDriver : SensorDefCompile Driver.c
	gcc Driver.c -o Driver

clean:
	rm -rf SensorTypes SensorDef Driver