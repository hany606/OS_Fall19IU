#include<stdio.h>
#include<limits.h>
#include<float.h>

int main(){
    int int_var = INT_MAX;
    float float_var = FLT_MAX;
    double double_var = DBL_MAX;
    printf("Integer variable size: %d, Max value: %d\n", sizeof(int_var), int_var);
    printf("Float variable size: %d, Max value: %f\n", sizeof(float_var), float_var);
    // printf("Float variable size: %d, values: %e\n", sizeof(float_var), float_var);
    printf("Double variable size: %d, Max value: %lf\n", sizeof(double_var), double_var);
    // printf("Double variable size: %d, values: %e\n", sizeof(double_var), double_var);
    return 0;
}
