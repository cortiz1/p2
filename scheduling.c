#include <stdlib.h>
#include <stdio.h>

#include "common.h"
#include "fcfs.h"
#include "sjf.h"
#include "srt.h"
#include "hpf.h"

// TODO: Answer the following:
// can we add remaining time to the process struct?
// why does arrival time need to be a float?
// why does expected run time run from 0.1 to 10
//     with possible values: [ 0.1, 1, 2, 3, 4 .. 10 ]



// Round Robin (preemptive)
int rr(process *ptr)
{
    // dont sort
    int i;
    for(i=0; i<NUMBER_OF_PROCS; i++)
    {
	printf("pid: %d\n", ptr[i].pid);
    }

    return 0;
}


int main()
{
    printf("hello main\n");
    srand(0);
    process proc_list[NUMBER_OF_PROCS];
    int i;
    process *buff = malloc(NUMBER_OF_PROCS * sizeof(process));

    printf("Running fcfs %d times\n", RUNS_PER_ALGO);
    for (i=0; i< RUNS_PER_ALGO; i++)
    {
	printf("run #%d:\n", i);
	generate_procs(buff);
	print_procs(buff);
	fcfs(buff);
    }

    printf("Running sjf %d times\n", RUNS_PER_ALGO);
    for (i=0; i< RUNS_PER_ALGO; i++)
    {
	printf("run #%d:\n", i);
	generate_procs(buff);
	print_procs(buff);
	sjf(buff);
    }


    printf("Running srt %d times\n", RUNS_PER_ALGO);
    for (i=0; i< RUNS_PER_ALGO; i++)
    {
	printf("run #%d:\n", i);
	generate_procs(buff);
	print_procs(buff);
	srt(buff);
    }

    //
    //    printf("Running rr %d times\n", RUNS_PER_ALGO);
    //    for (i=0; i< RUNS_PER_ALGO; i++)
    //    {
    //        printf("%d\n", i);
    //        generate_procs(buff);
    //        rr(buff);
    //    }
    //

    printf("Running hpf %d times\n", RUNS_PER_ALGO);
    for (i=0; i< RUNS_PER_ALGO; i++)
    {
	printf("%d\n", i);
	generate_procs(buff);
	print_procs(buff);
	process a[NUMBER_OF_PROCS], b[NUMBER_OF_PROCS];
	for(int j=0;j<NUMBER_OF_PROCS;j++) {
	    a[j] = buff[j];
	    b[j] = buff[j];
	}
	//print_procs(a); print_procs(b);
	hpf_preemptive(a);
	hpf_nonpreemptive(b);
    }

    return 0;
}
