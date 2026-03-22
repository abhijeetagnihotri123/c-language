#include "SensorTypes.h"

struct temperature_data {
    short int min;
    short int max;
    float reading;
} __attribute__((packed));

struct humidity_data {
    float calibration;
    float reading;
} __attribute__((packed));

struct pressure_data {

    short int altitude;
    float reading;

} __attribute__((packed));

union readings{

    struct temperature_data temp;
    struct humidity_data humidity;
    struct pressure_data pressure;

};


struct sensor {
    short int id;
    char name[20];
    enum sensor_type type;
    enum sensor_state state;
    union readings value;
} __attribute__((packed));