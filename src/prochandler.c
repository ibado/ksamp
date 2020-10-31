#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "prochandler.h"

const char* ERROR = "error reading";

static const char* CPUMODEL = "model name";
static const char* CPUTYPE = "vendor_id";
static const char* VERSION = "Linux";

static const char* CPUINFO = "/proc/cpuinfo";
static const char* KERNELVERSION = "/proc/version";
static const char* UPTIME = "/proc/uptime";
static const char* FILESYSTEM = "/proc/filesystems";

int maquina(FILE *f,const char *dato,char *output);

void format(char *tag, char *input){

    char *output = strstr(input, ":");
    printf("%s %s \n",tag,output);
}


int get_cpumodel(char *output){

    return get_data(CPUINFO,CPUMODEL,output);
}

int get_cputype(char *output){

    return get_data(CPUINFO,CPUTYPE,output);
}

int get_kernelversion(char *output){

    return get_data(KERNELVERSION,VERSION,output);
}

int get_data(const char *path, const char *dato, char *output){

    FILE *f = fopen(path,"r");
    if(maquina(f,dato,output) == 0){

        fclose(f);
        return 0;
    }
    else{
        strcpy(output,ERROR);
        return -1;
    }

}

void print_uptime(){
    char output[50];
    get_data(UPTIME,"",output);

    for(int i = 0; i < 50; i++){
        if(output[i] == (char)32){
            output[i] = '\0';
            break;
        }
    }
    float value = strtof(output,'\0');
    uptime_format(value);
}

int get_filesystem_number(){

    FILE *f = fopen(FILESYSTEM,"r");
    if(f != NULL){

        int fsnum = 0;
        while(!feof(f)){

            char linea[BUFSIZE];
            fgets(linea,BUFSIZE,f);

            char *comp = strstr(linea,"nodev");

            if(comp != NULL){

               fsnum += 1;
            }
        }
        rewind(f);
        fclose(f);
        return fsnum;
    }
    else
        return 0;
}

void get_pcname(char *output){
    FILE *f = fopen("/proc/sys/kernel/hostname","r");
    if(f != NULL){
        output = fgets(output,BUFSIZE,f);
        fclose(f);
    }
}

void uptime_format(float uptime_seconds){

    float float_days = uptime_seconds / (60*60*24);
    int days = float_days;
    float float_hours = (float_days - days) * 24;
    int hours = float_hours;
    float float_minutes = (float_hours - hours) * 60;
    int minutes = float_minutes;
    float float_seconds = (float_minutes - minutes) *60;
    int seconds = float_seconds;

    printf("uptime[dd hhmmss]: %d %d:%d:%d\n\n",days,hours,minutes,seconds);
}

int maquina(FILE *f,const char *dato,char *output){

    if(f != NULL){

        char cadena[BUFSIZE];
        while(!feof(f)){

            fgets(cadena,BUFSIZE,f);

            char *comp = strstr(cadena,dato);

            if(comp != NULL){

                //printf("cadena: %s\n",comp);
                strcpy(output,comp);
                return 0;
            }
        }
    }
    return -1;
}
