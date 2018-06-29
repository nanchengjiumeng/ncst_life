require('./CONST');
require('./Handle');
let {Job} = require('./Job');
let {Event} = require('./Event');
let {CPU} = require('./Cpu');

let event_queue = new Event();
let exit_event_queue = new Event();
let job_queue = new Job();
let exit_job_queue = new Job();


let cpu =new CPU();
let system_time = 0;


function main(jobNumber, policy) {
    global.eventQueue = event_queue;
    global.exitEventQueue = exit_event_queue;
    global.jobQueue = job_queue;
    global.exitJobQueue = exit_job_queue;
    global.cpu = cpu;
    global.systemTime = system_time;

    let createTime, turnAroundTime, weightedTurnAroundTime;
    let i;

    let e = new Event();
    let job = new  Job();

    if (!jobNumber && !policy) {
        console.log('please input job amount');
        return 1;
    }


    policy = global[policy.toUpperCase()];
    initEventQueue(eventQueue);
    initEventQueue(exitEventQueue);

    initJobQueue(jobQueue);
    initJobQueue(exitJobQueue);


    initCPU(cpu, policy);


    createTime = 0;
    for (i = 0; i < jobNumber; ++i) {

        createTime += NEXTJOBCREATETIMEINTERVAL;
        e = createEvent(createTime, JOBCREATEEVENT);
        addEventToQueue(e, eventQueue);

    }

    while (!isEmptyEventQueue(eventQueue)) {
        e = firstEventInQueue(eventQueue);
        removeEventFromQueue(e);
        global.systemTime = e.time;
        switch (e.type) {
            case JOBCREATEEVENT:
                //console.log(JOBCREATEEVENT,'jobcre');
                jobCreateEventHandle(e);
                break;
            case JOBSCHEDULEEVENT:
                //onsole.log(JOBSCHEDULEEVENT,'jobsch');
                jobScheduleEventHandle(e);
                break;
            case JOBEXITSTATE:
               // console.log(JOBEXITSTATE,'jobexit');
                jobExitEventHandle(e);
                break;
            default:
                break;
        }
        addEventToQueue(e, exitEventQueue);
    }


    console.log('EVENT QUEUE');
    printEventQueue(exitEventQueue);

    console.log('JOB QUEUE');
    printJobQueue(exitJobQueue);

    for (turnAroundTime = 0, weightedTurnAroundTime = 0.0, job = firstJobInQueue(exitJobQueue);
         job !== exitJobQueue; job = job.next) {
        turnAroundTime += job.turnAroundTime;
        weightedTurnAroundTime+=job.weightedTurnAroundTime;
    }

    cpu.turnAroundTime = turnAroundTime/cpu.jobNumber;
    cpu.weightedTurnAroundTime = weightedTurnAroundTime/cpu.jobNumber;
    cpu.freeTime = systemTime - cpu.busyTime;
    printCPU(cpu);

    clearEventQueue(eventQueue);
    clearEventQueue(exitEventQueue);
    clearJobQueue(jobQueue);
    clearJobQueue(exitJobQueue);
}



module.exports = { main };

