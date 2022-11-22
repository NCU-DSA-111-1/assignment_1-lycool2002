void training(FILE *fptr, int times, double lr, int numTrainingSets, int *trainingSetOrder ,int numInputs, int numHiddenNodes, int numOutputs, double *hiddenWeights, double *hiddenLayerBias, double *outputWeights, double *outputLayerBias,double *training_inputs, double *training_outputs, double *hiddenLayer, double *outputLayer){
    fprintf(fptr, "%d, ",times);
    double avgerror = 0;
    for (int x=0; x<numTrainingSets; x++) {

        
        int i = trainingSetOrder[x];
        
        // Forward pass
        
        for (int j=0; j<numHiddenNodes; j++) {
            double activation=hiddenLayerBias[j];
             for (int k=0; k<numInputs; k++) {
                activation+=training_inputs[i * numInputs + k]*hiddenWeights[k * numHiddenNodes + j];
            }
            hiddenLayer[j] = sigmoid(activation);

        }
        
        for (int j=0; j<numOutputs; j++) {
            double activation=outputLayerBias[j];
            for (int k=0; k<numHiddenNodes; k++) {
                activation+=hiddenLayer[k]*outputWeights[k * numOutputs + j];
            }
            outputLayer[j] = sigmoid(activation);

        }
        
        avgerror = avgerror+(outputLayer[0]-training_outputs[i * numOutputs ])*(outputLayer[0]-training_outputs[i * numOutputs ]);

        // Backprop
        double * deltaOutput =  malloc( numOutputs * sizeof(double) );

        for (int j=0; j<numOutputs; j++) {
            double errorOutput = (training_outputs[i * numOutputs + j]-outputLayer[j]);
            deltaOutput[j] = errorOutput*dSigmoid(outputLayer[j]);
        }
        
        double *deltaHidden =  malloc( numHiddenNodes * sizeof(double) );

        for (int j=0; j<numHiddenNodes; j++) {
            double errorHidden = 0.0f;
            for(int k=0; k<numOutputs; k++) {
                errorHidden+=deltaOutput[k]*outputWeights[j * numOutputs + k];
            }
            deltaHidden[j] = errorHidden*dSigmoid(hiddenLayer[j]);
        }
        
        for (int j=0; j<numOutputs; j++) {
            outputLayerBias[j] += deltaOutput[j]*lr;
            for (int k=0; k<numHiddenNodes; k++) {
                outputWeights[k * numOutputs + j]+=hiddenLayer[k]*deltaOutput[j]*lr;
            }
        }
        
        for (int j=0; j<numHiddenNodes; j++) {
            hiddenLayerBias[j] += deltaHidden[j]*lr;
            for(int k=0; k<numInputs; k++) {
                hiddenWeights[k * numHiddenNodes + j]+=training_inputs[i * numInputs + k]*deltaHidden[j]*lr;
            }
        }
        free(deltaHidden);      
        free(deltaOutput);
    
    }
    fprintf(fptr,"%lf", (avgerror/numTrainingSets)); //ouput error to file
    fprintf(fptr, "\n");
   
    
}

