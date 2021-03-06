#include "stdio.h"
#include "prochandler.h"

int main(int argc, char* argv[]){


    

    printf("\n----ksamp version 1.0 BETA------------------\n\n");

    char cpumodel[BUFSIZE];
    char cputype[BUFSIZE];
    char kernelversion[BUFSIZE];
    char pcname[BUFSIZE];

    get_cpumodel(cpumodel);
    get_cputype(cputype);
    get_kernelversion(kernelversion);
    get_pcname(pcname);
   
    printf("pc name: %s\n",pcname);
    format("cpu model",cpumodel);
    format("cpu type",cputype);
    printf("kernel version: %s\n",kernelversion);
    print_uptime();
    int fsn = get_filesystem_number();
    printf("Number of support fs: %d\n",fsn);

    printf("\n---------------------------------------------\n");

    return 0;
}
