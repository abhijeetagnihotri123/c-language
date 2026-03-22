enum sensor_type{ // forward declaration which allows for inclusion in header files

    TEMPERATURE = 0,
    HUMIDITY,
    PRESSURE
};

enum sensor_state{

    ACTIVE,
    INACTIVE,
    ERROR
} ;