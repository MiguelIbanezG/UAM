#ifndef EXAMEN_H
#define EXAMEN_H



#ifndef ERR
  #define ERR -1
  #define OK (!(ERR))
#endif

int quicksort_inv(int* tabla, int ip, int iu);
int partition_inv(int* tabla, int ip, int iu,int *pos);
int median_inv(int *tabla, int ip, int iu,int *pos);




#endif
