void set_weights(int numInputs, int numHiddenNodes, int numOutputs, double *hiddenWeights, double *hiddenLayerBias, double *outputWeights, double *outputLayerBias){
    for (int i=0; i<numInputs; i++) {
        for (int j=0; j<numHiddenNodes; j++) {
            hiddenWeights[i * numHiddenNodes + j] = init_weight();
            //printf("hiddenWeights : %lf \n",hiddenWeights[i * numHiddenNodes + j]);
        }
    }
    for (int i=0; i<numHiddenNodes; i++) {
        hiddenLayerBias[i] = init_weight();
        for (int j=0; j<numOutputs; j++) {
            outputWeights[i * numOutputs + j] = init_weight();
            //printf("outputWeights : %lf \n", outputWeights[i * numOutputs + j]);
        }
    }
    for (int i=0; i<numOutputs; i++) {
        outputLayerBias[i] = init_weight();
       // printf("outputLayerBias : %lf \n",outputLayerBias[i]);
    }
}
