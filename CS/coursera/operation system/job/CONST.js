if (global['CONST']) {
    console.log('CONST in prent')
} else {
    // max job create time interval( 间隔 )
    global.MAXJOBCREATETIMEINTERVAL = 50;
    // next job create time interval
    global.NEXTJOBCREATETIMEINTERVAL = (rand() % MAXJOBCREATETIMEINTERVAL + 1);
    // max job runtime
    global.MAXJOBRUNTIME = 100;
    //next job runtime
    global.NEXTJOBRUNTIME = (rand() % MAXJOBRUNTIME + 1);

    //job backup state
    global.JOBBACKUPSTATE = 1;
    // job running state
    global.JOBRUNNINGSTATE = 2;
    //job exit state
    global.JOBEXITSTATE = 3;


    global.BUSY = 1;
    global.FREE = 2;

    //First come,first served.
    global.FCFS = 1;
    //Shortest job First.
    global.SJF = 2;
    //Highest Response-ratio Next
    global.HRN = 3;

    //job create event
    global.JOBCREATEEVENT = 1;
    // job schedule event
    global.JOBSCHEDULEEVENT = 2;
    // job exit event
    global.JOBEXITEVENT = 3;


    global.FALSE = 0;
    global.TRUE = 1;
    global['CONST'] = true;

}

function rand() {
    return Math.random();
}








