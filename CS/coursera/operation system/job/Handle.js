require('./Event');
require('./CONST');
require('./Cpu');
let {Event} = require('./Event');
let {Job} = require('./Job');
if(global['handle_sign']){

}else {

    global.jobCreateEventHandle =function (event) {
        let j = new Job();
        let e = new Event();
        if(!(j=createJob((jobId++),systemTime,NEXTJOBRUNTIME()))){
            return;
        }
        addJobToQueue(j,jobQueue);
        //addJobToQueue(job,jobQueue);
        event.jobID = j.id;
        if(cpu.state === FREE){
            e = createEvent(systemTime,JOBSCHEDULEEVENT);
            frontAddEventToQueue(e,eventQueue);


        }
    };

    global.jobScheduleEventHandle = function (event) {
        let j = new Job();
        let e = new Event();

        if(isEmptyEventQueue(jobQueue)){return false;}

        switch (cpu.policy){
            case FCFS:
                j = firstEventInQueue(jobQueue);
                break;
            case SJF:
                j = shortJobInQueue(jobQueue);
                break;
            case HRN:
                j = hrnJobInQueue(jobQueue);
                break;
            default:
                j = firstEventInQueue(jobQueue);
                break;
        }

        removeJobFromQueue(j);

        event.jobID = j.id;
        j.state  = JOBRUNNINGSTATE;
        cpu.runningJob = j;
        cpu.state = BUSY;

        e = createEvent(systemTime + j.runTime,JOBEXITEVENT);
        e.jobID = j.id;
        //

        addEventToQueue(e,eventQueue);


    };
    global.jobExitEventHandle = function () {

        let j = new Job();
         let e = new Event();
         j = cpu.runningJob;
         j.state = JOBEXITSTATE;
         j.exitTime  = systemTime;
         j.turnAroundTime = j.exitTime - j.createTime;
         j.weightedTurnAroundTime = j.turnAroundTime/j.runTime;
         cpu.state = FREE;
         cpu.busyTime +=j.runTime;
         cpu.jobNumber++;
        addJobToQueue(j,exitJobQueue);
         if(!isEmptyEventQueue(jobQueue)){
              e = createEvent(systemTime, JOBSCHEDULEEVENT);
              frontAddEventToQueue(e,eventQueue);
         }
    }
}