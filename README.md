# 利用Ｃ構建類神經網路學習xor運算
此 porject 利用類神經網路學習xor運算

---

**need to make data file, I already make 2,3,4 bit datafile**

format is 
1 input bit ..., output
2 input bit ..., output

example:2bit xor
```
0.0, 0.0, 0.0 
0.0, 1.0, 1.0 
1.0, 0.0, 1.0 
1.0, 1.0, 0.0 
```
---
you can change

**num of inputs, hidden nodes, training times, laearing rate**

in main.c file
```c
int main(int argc, const char * argv[]) {
        
    FILE *fptr;
        
    fptr = fopen("/home/lyc/Desktop/out.csv","w");//outfile name

    static const int numInputs = 6; // change parameter here  2 or 3 or 4 or 5 or 6is avaliable
    static const int numHiddenNodes = 40; //change parameter here 
        
    /*
    ......
    */
        
    int *trainingSetOrder = malloc( numTrainingSets * sizeof(int)); 
        
     const double lr = 1;//learning rate
        
     FILE * fptrRead;
     fptrRead = fopen("data6.csv","r");//datafile name

    /*
    ......
    */
    for (int n=0; n < 200000; n++) { //training times
    /*
    ......
    */  
    }   
``` 

---
更多詳細資訊請看詳細資訊請看/doc資料夾
