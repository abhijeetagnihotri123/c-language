void secondaryFunction(){

    label: //This is not allowed in C, no point in continuing to write code here as it will not compile.
        //some code here

}

void sampleFunction(){

    int i = 10;

    if(i == 10){
        goto label;
    }
    return;
}