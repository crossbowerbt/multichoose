#include <stdlib.h>
#include <stdio.h>


int main(int argc, char** argv){

    int *a, *b;
    char **m;
    int i,j,k,n,r;

    if (argc<3) {
        printf("usage: ./multi_erik k item_1 ... item_n\n");
        return 0;
    }
    
    n = atoi(argv[1]);
    r = argc - 2;

    m = malloc(r * sizeof(char*));
    a = malloc(n * sizeof(int));
    b = malloc(n * sizeof(int));

    for(i=0; i < r; i++)
	m[i] = argv[i+2];

    for (i=0; i < n; i++) {
        a[i] = 0;
        b[i] = r-1;
    }

    while(1){
        // emit multiset combination

	    for(i=0; i<n; i++)
            printf("%s ", m[a[i]]);
	    printf("\n");

	    j = n - 1;
        while(a[j] == b[j]) j--;

	    if (j < 0) break;

        a[j]++;
	    for(k = j+1; k < n; k++)
	        a[k] = a[j];
	
    }

    return 0;
}
