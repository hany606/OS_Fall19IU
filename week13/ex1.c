#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

int resource_num = 3;
int process_num = 5;


int check_resources(int rqst[resource_num], int src[resource_num]) {
  for (int i = 0; i < resource_num; ++i)
    if (rqst[i] > src[i]) 
      return 0;
  return 1;
}


int main() {
  int exist[resource_num];
  int available[resource_num];
  int allocMatrix[process_num][resource_num];
  int requestMatrix[process_num][resource_num];

  FILE *input = fopen("input_ok.txt", "r");
  if (input == NULL) {
    fprintf(stderr, "No file input.txt\n");
    return 1;
  }

  for (int i = 0; i < resource_num; ++i) {
    fscanf(input, "%d", &exist[i]);
  }

  for (int i = 0; i < resource_num; ++i) {
    fscanf(input, "%d", &available[i]);
  }

  for (int i = 0; i < process_num; ++i) {
    for (int j = 0; j < resource_num; ++j) {
      fscanf(input, "%d", &allocMatrix[i][j]);
    }
  }

  for (int i = 0; i < process_num; ++i) {
    for (int j = 0; j < resource_num; ++j) {
      fscanf(input, "%d", &requestMatrix[i][j]);
    }
  }

  fclose(input);

  int proc_finished[process_num];
  int terminating = 1;
  while (terminating) {
    terminating = 0;
    for (int i = 0; i < process_num; ++i) {
      if (!proc_finished[i] && check_resources(requestMatrix[i], available)) {
        for (int j = 0; j < resource_num; ++j) {
          available[j] += allocMatrix[i][j];
        }
        proc_finished[i] = true;
        terminating = true;
      }
    }
  }

  FILE *output = fopen("output.txt", "w");
  int deadlocked = 0;
  for (int i = 0; i < process_num; ++i) {
    if (!proc_finished[i]) {
      deadlocked = 1;
      fprintf(output, "Process %d deadlocked.\n", i);
    }
  }

  if (!deadlocked) {
    fprintf(output, "No deadlock detected.\n");
  }

  fclose(output);

  return 0;
}

