void sampleFunction(){
    int i = 11;

    if(i == 10){
        goto end;
    }

    i = i + 2;

    end:
        i = i + 9;

    return;
}