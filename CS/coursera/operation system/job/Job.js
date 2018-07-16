require('./CONST');

let Job = function () {
    this.id = null;
    this.state = null;
    this.createTime = null;
    this.runTime = null;
    this.exitTime = null;
    this.turnAroundTime = 0;
    this.weightedTurnAroundTime = 0;
    this.prev = null;
    this.next = null;
};
/*Job = () => ({
    id: null,
    state: null,
    createTime: null,
    runTime: null,
    exitTime: null,
    turnAroundTime: null,
    weightedTurnAroundTime: null,
    prev: null,
    next: null,

});*/

if (!global['job_sign']) {


    global.createJob = (id, createTime, runTime) => {
        let j= new Job();
        j.id = id;
        j.createTime = createTime;
        j.runTime = runTime;
        j.state = JOBBACKUPSTATE;
        j.turnAroundTime = 0;
        j.weightedTurnAroundTime = 0.0;
        j.prev = j.next = j;
        return j;
    };
    global.destroyJob = (job) => {
        for (let key in job) {
            job[key] = null;
        }
    };
    global.initJobQueue = (queue) => {
        queue.prev = queue.next = queue;
    };

    global.isEmptyJobQueue = (queue) => {
        return queue.next === queue;
    };

    global.sizeOfJobQueue = (queue) => {
        let n = 0, job = queue.next;
        while (job !== queue) {
            ++n;
            job = job.next;
        }
        return n;
    };

    global.printJobQueue = (queue) => {
        let j = queue.next;
        while (j !== queue) {
            printJob(j);
            j = j.next;
        }
    };
    global.printJob = (job) => {
        console.log('nid' + '=' + job.id + ',',
            'createTime' + '=' + job.createTime + ',',
            'runTime' + '=' + job.runTime + ',',
            'exitTime' + '=' + job.exitTime + ',',
            'turnAroundTime' + '=' + job.turnAroundTime + ',',
            'weightedTurnAroundTime' + '=' + job.weightedTurnAroundTime + ',',
        );
    };

    global.firstJobInQueue = (queue) => {
        if (isEmptyJobQueue(queue)) {
            return null;
        } else {
            return queue.next;
        }
    };
    global.shortJobInQueue = (queue) => {
        let job = null, shortJob = null;
        if (isEmptyJobQueue(queue)) {
            return null;
        } else {
            for (shortJob = queue.next, job = shortJob.next; job !== queue; job = job.next) {
                if (job.runTime < shortJob.runTime) {
                    shortJob = job;
                }
            }
        }
        return shortJob;
    };
    //Highest Response-ratio Next
    global.hrnJobInQueue = (queue) => {
        let systemTime = global.systemTime;
        let hrnJob = null;
        let job = null;
        let hrn = null;
        let rn = null;
        if (isEmptyJobQueue(queue)) {
            return null;
        } else {
            for (hrnJob = queue.next, job = hrnJob.next; job !== queue; job = job.next) {
                hrn = (systemTime - hrnJob.createTime) / hrnJob.createTime;
                rn = (systemTime - job.createTime) / job.createTime;
                if (rn > hrn) {
                    hrnJob = job;
                }
            }
            return hrnJob;
        }
    };

    global.clearJobQueue = (queue) => {
        let job;
        while (isEmptyJobQueue(queue) === false) {
            job = firstJobInQueue(queue);

        }
    };
    global.removeJobFromQueue = (job) => {
        job.prev.next = job.next;
        job.next.prev = job.prev;
        job.prev = job.next = job;
    };
    global.addJobToQueue = (job, queue) => {
        job.prev = queue.prev;
        job.next = queue;
        queue.prev.next = job;
        queue.prev = job;
    };

} else {
    global['job_sign'] = true;
}
module.exports = {Job};


