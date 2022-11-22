//print_weights after finishing training
void print_weights(int numInputs, int numHiddenNodes, int numOutputs, double *hiddenWeights, double *hiddenLayerBias, double *outputWeights, double *outputLayerBias){

    printf( "Final Hidden Weights\n[ ");
    for (int j=0; j<numHiddenNodes; j++) {
        printf("[ ");
        for(int k=0; k<numInputs; k++) {
            printf("%lf ", hiddenWeights[k * numHiddenNodes + j]);
        }
        printf("] ");
    }
    printf("] \n");

    printf( "Final Hidden Biases\n[ ");
    for (int j=0; j<numHiddenNodes; j++) {
        printf("%lf ", hiddenLayerBias[j]);
    }
    printf("] \n");
    printf( "Final Output Weights");
    for (int j=0; j<numOutputs; j++) {
        printf("[ ");
        for (int k=0; k<numHiddenNodes; k++) {
            printf("%lf ", outputWeights[k * numOutputs + j]);
        }
        printf("] \n");
    }
    printf("Final Output Biases\n[ ");
    for (int j=0; j<numOutputs; j++) {
        printf("%lf ", outputLayerBias[j]);
    
    }
    printf("] \n");
}
