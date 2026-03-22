int sampleFunction(){

    /*
    //Demonstrating the use of const in C

    const float xyz = 5.0; // Not constant variable, but readonly
    // can be modified by pointer, but not directly

    float *ptr = &xyz;

    *ptr = 10.0;
    */

    /*
    //Demonstrating the use of volatile in C

    */

    volatile int i = 5; // do not optimize this variable, as it may change unexpectedly

    i = i + 1;
    i = i + 10;

    return i;
    
}