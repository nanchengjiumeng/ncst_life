require('CONST');
let Event = function () {
    return {
        time: null,
        type: null,
        jobID: null,
        prev: null,
        next: null,
    };
};
if (!global['event_sign']) {
    global.createEvent = function (time, type) {
        let e = Event();
        e.time = time;
        e.type = type;
        e.jobID = 0;
        e.prev = e.next = e;
    };

    global.destroyEvent = function (event) {
        event = null;
    };

    global.initEventQueue = function (queue) {
        queue.prev = queue.next = queue;
    };

    global.clearEventQueue = function (queue) {
        let e = null;
        while (!isEmptyEventQueue(queue)) {
            e = firstEventInQueue(queue);
            removeEventFromQueue(e);
            destroyEvent(e);
        }
    };

    global.isEmptyEventQueue = function (queue) {
        return queue === queue.next
    };

    global.sizeOfEventQueue = function (queue) {
        let n = 0;
        let e = null;
        for (e = queue.next; e !== queue; ++n, e = e.next) {

        }
        return n;
    };

    global.printEvent = function (e) {
        console.log(e.time);
        switch (e.type) {
            case JOBCREATEEVENT:
                console.log("jobcreate   ");
                break;
            case JOBSCHEDULEEVENT:
                console.log("jobschedule ");
                break;
            case JOBEXITEVENT:
                console.log("jobexit     ");
                break;
            default:
                console.log("unknown event");
        }
        console.log(", id=", e.jobID);
    };

    global.printEventQueue = function (queue) {
        let e = null;
        e = queue.next;
        while (e !== queue) {
            printEvent(e);
            e = e.next;
        }
    };

    global.firstEventInQueue = function (queue) {
        if (isEmptyEventQueue(queue)) {
            return null;
        } else {
            return queue.next;
        }
    };

    global.removeEventFromQueue = function (event) {
        event.prev.next = event.next;
        event.next.prev = event.prev;
        event.prev = event.next = event;
    };

    global.addEventToQueue = function (event, queue) {
        let e = null;
        if(isEmptyEventQueue(queue)){
            queue.next = queue.prev = event;
            event.prev = event.next = queue;
        }
        for (e=queue.next;e!==queue && e.time<=event.time;e=e.next){

        }
        event.next = e;
        event.prev = e.prev;
        e.prev.next = event;
        e.prev = event;
    };

    global.frontAddEventToQueue = function (event, queue) {
        let e ;

        if (isEmptyEventQueue(queue)) {
            queue.next = queue.prev = event;
            event.prev = event.next = queue;
        }

        for (e = queue.next; e !== queue && e.time < event.time; e = e.next){

        }
        event.next = e;
        event.prev = e.prev;
        e.prev.next = event;
        e.prev = event;

    };

} else {
    global['event_sign'] = true;
}
module.exports ={ Event };
