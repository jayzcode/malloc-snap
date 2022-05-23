# include <stdio.h>
# include <stdlib.h>
# include <string.h>
# include <getopt.h>
# include <unistd.h>

/* Forward declarations.  */
static void print_help (void);
static int mem_alloc (int);

static const struct option longopts[] = {
  {"greeting", required_argument, NULL, 'g'},
  {"memory", required_argument, NULL, 'm'},
  {"help", no_argument, NULL, 'h'},
  {NULL, 0, NULL, 0}
};


int 
main(int argc, char *argv[]) {
	int optc;
	while ((optc = getopt_long (argc, argv, "hg:m:", longopts, NULL)) != -1)
	switch(optc) {
		case 'h':
			print_help();
			break;
		case 'g':
			printf("Printing greetings - %s\n", optarg);
			break;
		case 'm':
			mem_alloc(atoi(optarg));
			break;
		default:
			printf("ERROR : \n");
			print_help ();
			break;
	}

	return 0;
}

static void 
print_help (void) {
	printf("Usage: myapp [OPTION]...");
	printf ("\n\
		-h, --help    	        display this help and exit\n\
		-g, --greeting=TEXT     use TEXT as the greeting message\n\
		-m, --memory=NUM        use NUM to allocate NUM MB memory\n");
	printf ("\n");
}


/* int m - memory to allocated in MB. */

static int 
mem_alloc (int m) {
    //int m = 1024; //MB of memory
    int pg;
    long sz = sysconf(_SC_PAGESIZE);
    pg = (m*1024*1024)/sz;
    printf("Allocating memory of size = %d MB (%d B)\n", m, (m * 1024 * 1024));
    printf("pagesize=%ld B\n", sz);
    printf("number of pages=%d\n", pg);

    printf("\nMemory Usage before allocation\n");
    system("free -m");

    char *ptr = (char *)malloc(pg * sz);
    if(ptr == NULL) {
       printf("FAILED : Memory allocation failed.\n");
       return -1;
    }
    for(char *p = ptr; p < ptr + (pg * sz); p=p+sz) {
            memcpy(p, "a", sizeof(char));
            //printf("Writing data: %p = %c\n", p, *(char *)p);
    }

    sleep(2);
    printf("\nMemory Usage after allocation\n");
    system("free -m");
    sleep(1);
    printf("\nPress Any Key to Continue...");
    getchar();
    return 0;
}
