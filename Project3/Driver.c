#include "SensorDef.h"
#include <stdio.h>

void print_sensor(struct sensor);
struct sensor initialize_sensor();

enum sensor_type get_sensor_type(char);
union readings get_sensor_readings(enum sensor_type);

void print_readings_based_on_Type(enum sensor_type , union readings);

int main(){

    struct sensor sensor_list[2] = {0};
    struct sensor temp = {0};

    unsigned short int init_sensor = 1;
    unsigned short int sensor_count = 0;

    while(1){
        
        if(sensor_count >= 2){
            printf("Maximum allowed limit reached for adding sensors\n");
            break;
        }

        printf("Want to initialise a sensor for the system?\nPress 0 to skip and exit driver code.\nPress 1 to create for reading ambient data\n");
        scanf("%hi" , &init_sensor);    
        scanf("%*c"); //flush input buffer for remaining inputs
        
        if(init_sensor == 0){
            break;
        }

        temp = initialize_sensor();
        temp.state = ACTIVE;
        
        // print_sensor(temp);

        sensor_list[sensor_count++] = temp;
    }

    printf("Info about all the sensors added\n");

    for(unsigned short count = 0 ; count < sensor_count ; count++)
    {
        print_sensor(sensor_list[count]);
    }

    return 0;
}

enum sensor_type get_sensor_type(char type){

    enum sensor_type final_type;

    switch (type)
    {
    case 't':
        final_type = TEMPERATURE;
        /* code */
        break;
    
    case 'h': 
        final_type = HUMIDITY;
        break;

    case 'p':
        final_type = PRESSURE;
        break;
    
    default:
        final_type = TEMPERATURE;
        break;
    }
    return final_type;
}

union readings get_sensor_readings(enum sensor_type type)
{
    union readings sensor_readings;
    
    switch (type)
    {
    case TEMPERATURE:
        
        printf("Here temperature\n");
        printf("Enter minimum allowed temperature\n");
        scanf("%hi" , &sensor_readings.temp.min);
        scanf("%*c");
        printf("Enter maximum allowed temperature\n");
        scanf("%hi" , &sensor_readings.temp.max);
        scanf("%*c");
        printf("Enter current reading\n");
        scanf("%f" , &sensor_readings.temp.reading);
        scanf("%*c");
        break;
    
    case HUMIDITY:
        /* code */
        printf("Here Humidity\n");
        printf("Enter calibration reading\n");
        scanf("%f" , &sensor_readings.humidity.calibration);
        scanf("%*c");
        printf("Enter current reading\n");
        scanf("%f" , &sensor_readings.humidity.reading);
        scanf("%*c");
        break;

    
    case PRESSURE:
        printf("Here pressure\n");
        printf("Enter Altitude reading\n");
        scanf("%hi" , &sensor_readings.pressure.altitude);
        scanf("%*c");
        printf("Enter current reading\n");
        scanf("%f" , &sensor_readings.pressure.reading);
        scanf("%*c");
        break;
    }
    return sensor_readings;
}


struct sensor initialize_sensor()
{
    struct sensor temp = {0};

    printf("Enter your sensor ID\n");
    scanf("%hi" , &temp.id);
    scanf("%*c");

    
    printf("Enter your sensor name\n");
    scanf("%s" , (char*)&temp.name);
    scanf("%*c");
    
    printf("Enter your sensor type press t for temperature, press h for humidity, press p for pressure\n");
    char type;
    scanf("%c" , &type);
    scanf("%*c");

    temp.type = get_sensor_type(type);
    temp.value = get_sensor_readings(temp.type);
    temp.state = INACTIVE;
    return temp;
}

void print_readings_based_on_Type(enum sensor_type type, union readings sensor_readings)
{
    switch (type)
    {
    case TEMPERATURE:
        printf("Temperature sensor below are the parameters\n");
        printf("Maximum allowed temperature : %hi\n" , sensor_readings.temp.max);
        printf("Minimum allowed temperature : %hi\n" , sensor_readings.temp.min);
        printf("Current temperature reading : %f\n" , sensor_readings.temp.reading);
        break;
    
    case HUMIDITY:
        printf("Humidity sensor below are the parameters\n");
        printf("Calibration parameter : %f\n" , sensor_readings.humidity.calibration);
        printf("Current humidity reading : %f\n" , sensor_readings.humidity.reading);
        break;
    
    case PRESSURE:
        printf("Pressure sensor below are the parameters\n");
        printf("Maximum allowed temperature : %hi\n" , sensor_readings.pressure.altitude);
        printf("Current pressure reading : %f\n" , sensor_readings.pressure.reading);
        break;
    }
}

void print_sensor(struct sensor temp)
{
    printf("\n=======Printint Sensor information============\n");
    printf("Id of the sensor : %hi\n" , temp.id);
    printf("Name of the sensor : %s\n" , temp.name);
    printf("Type of the sensor : %d\n" , temp.type);
    printf("State of the sensor : %d\n" , temp.state);
    print_readings_based_on_Type(temp.type , temp.value);
    printf("===================\n");
}