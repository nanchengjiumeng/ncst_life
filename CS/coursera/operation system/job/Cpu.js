let CPU = function () {
    return {
        state : null,
        policy : null,
        runningJob : null,
        busyTime : null,
        freeTime : null,
        jobNumber : null,
        turnAroundTime : null,
        weightedTurnAroundTime : null,
    }
};
if(!global['cpuSign']){
    global.initCPU=function ( cpu, policy) {
        cpu.state=FREE;
        cpu.policy = policy;
        // cpu.runningJob = null;
        cpu.busyTime = cpu.freeTime = 0;
        cpu.jobNumber = 0;
        cpu.turnAroundTime = 0;
        cpu.weightedTurnAroundTime = 0.0;
    };
    global.printCPU = function (cpu) {
        switch (cpu.policy){
            case FCFS:
                console.log('FCFS');
                break;
            case SJF:
                console.log('SJF');
                break;
            case HRN:
                console.log('HRN');
                break;
            default:
                console.log('UnKnown');
        }
        console.log('busy='+ cpu.busyTime+', free='+ cpu.freeTime+', jobnumber='+cpu.jobNumber+'');
        console.log('turnaround='+cpu.turnAroundTime+', wturnaround='+cpu.weightedTurnAroundTime);
    };
}else {
    global["cpuSign"] = true;
}
module.exports ={CPU};