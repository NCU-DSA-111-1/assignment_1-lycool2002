#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "sigmod.h" 
#include "dsigmod.h" 
#include "init_weight.h"
#include "print_weights.h"
#include "shuffle.h"
#include "set_weights.h" 
#include "training.h"
#include "reading.h"


int main(int argc, const char * argv[]) {
    
    FILE *fptr;
    
    fptr = fopen("out.csv","w");//outfile name

    static const int numInputs = 4;//////////////////////////////////////////////// change parameter here  2 or 3 or 4 or 5 or 6is avaliable
    static const int numHiddenNodes = 20;///////////////////////////////////////////change parameter here 
    
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
    fptrRead = fopen("data4.csv","r");//datafile name

	reading(fptrRead, numTrainingSets, numInputs, numOutputs,training_inputs,training_outputs);    

    set_weights(numInputs, numHiddenNodes, numOutputs, hiddenWeights, hiddenLayerBias, outputWeights, outputLayerBias);
    	
	for(int k = 0; k<numTrainingSets ; k++){
		trainingSetOrder[k] = k;	
	}
    
    for (int n=0; n < 200000; n++) { //training times
        shuffle(trainingSetOrder,numTrainingSets); 
        training(fptr, n, lr, numTrainingSets, trainingSetOrder ,numInputs, numHiddenNodes, numOutputs, hiddenWeights, hiddenLayerBias, outputWeights,  outputLayerBias, training_inputs, training_outputs, hiddenLayer, outputLayer); 	   
	}
	
    print_weights(numInputs, numHiddenNodes, numOutputs, hiddenWeights, hiddenLayerBias, outputWeights, outputLayerBias);
    
    fclose(fptr);
    fclose(fptrRead);
    free (hiddenLayer);
    free (outputLayer);  
    free (hiddenLayerBias);
    free (outputLayerBias);
    free (hiddenWeights);
    free (outputWeights);    
    free (training_inputs);
    free (training_outputs);    
    free (trainingSetOrder);
    
    return 0;
}





