#ifndef BUFSIZE
    #define BUFSIZE 200
#endif
void uptime_format(float uptime_seconds);

void format(char *tag, char *input);

int get_cpumodel(char *output);

int get_cputype(char *output);

int get_kernelversion(char *output);

int get_filesystem_number();

void get_pcname(char *output);

int get_data(const char *path, const char *dato, char *output);

void print_uptime();


