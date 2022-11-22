void  reading(FILE *fptrRead, int numTrainingSets, int numInputs, int numOutputs, double *training_inputs, double *training_outputs){
	for (int i = 0; i < numTrainingSets ; i++) {
  		for (int j = 0; j < numInputs   ; j++) {
    		fscanf(fptrRead, "%lf, ", &training_inputs[i * numInputs + j]);
    		printf(" input: %lf\n",training_inputs[i * numInputs + j]);
  		}
  		fscanf(fptrRead, "%lf\n", &training_outputs[i * numOutputs + numOutputs - 1]);
  		printf("  output: %lf\n",training_outputs[i * numOutputs + numOutputs - 1]);
	}
} 
	
