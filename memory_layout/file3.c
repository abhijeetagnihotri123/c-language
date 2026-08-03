volatile int x = 0;

void sampleFunction()
{
    while(x == 0){
        //some statement
    }
}

int main(){
    sampleFunction();
    return 0;
}