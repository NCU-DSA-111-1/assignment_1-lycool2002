# usage
need to make data file, I already make 2,3,4 bit datafile 

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
you can see the comment in DS.c file to know how to setting
```c=
int main(int argc, const char * argv[]) {
    
    FILE *fptr;
    
    fptr = fopen("/home/lyc/Desktop/out.csv","w");//outfile name

    static const int numInputs = 6;//////////////////////////////////////////////// change parameter here  2 or 3 or 4 or 5 or 6is avaliable
    static const int numHiddenNodes = 40;///////////////////////////////////////////change parameter here 
    
    double DounumTrainingSets = pow(2,numInputs);
    
    int numTrainingSets = (int)DounumTrainingSets;
    static const int numOutputs = 1;
        
	double *hiddenLayer =  malloc( numHiddenNodes * sizeof(double) );
    double *outputLayer = malloc( numOutputs * sizeof(double) );    
    double *hiddenLayerBias = malloc( numHiddenNodes * sizeof(double) );
    double *outputLayerBias = malloc( numOutputs * sizeof(double) );
    double *hiddenWeights = malloc( numInputs * numHiddenNodes * sizeof(double) );
    double *outputWeights = malloc( numHiddenNodes * numOutputs * sizeof(double) );    
    double *training_inputs = malloc( numTrainingSets * numInputs * sizeof(double) );
    double *training_outputs = malloc( numTrainingSets * numOutputs * sizeof(double) );    
    int *trainingSetOrder = malloc( numTrainingSets * sizeof(int)); 
	   
    const double lr = 1;//learning rate
    
    FILE * fptrRead;
    fptrRead = fopen("data6.csv","r");//datafile name

	reading(fptrRead, numTrainingSets, numInputs, numOutputs,training_inputs,training_outputs);    

    set_weights(numInputs, numHiddenNodes, numOutputs, hiddenWeights, hiddenLayerBias, outputWeights, outputLayerBias);
    	
	for(int k = 0; k<numTrainingSets ; k++){
		trainingSetOrder[k] = k;	
	}
    
    for (int n=0; n < 200000; n++) { //training times
        shuffle(trainingSetOrder,numTrainingSets); 
        training(fptr, n, lr, numTrainingSets, trainingSetOrder ,numInputs, numHiddenNodes, numOutputs, hiddenWeights, hiddenLayerBias, outputWeights,  outputLayerBias, training_inputs, training_outputs, hiddenLayer, outputLayer); 	   
	}
	

```
change path
``` bash
cd "file path"
```
complie
``` bash
gcc -o DS.out DS.c -lm
```
run the file
``` bash
./DS.out
```
