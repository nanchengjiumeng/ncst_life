require('Event');
let {CPU} = require('Cpu');
let {Event} = require('Event');
let {Job} = require('Job');
if(global['handle_sign']){

}else {

    global.jobCreateEventHandle =function (event) {



    };
    global.jobScheduleEventHandle = function (event) {
        let cpu = CPU();
        let jobQueue = Job();
        let exitJobQueue = Job();
        let systemTime = global.systemTime;
        let job = Job();
        let e = Event();

    };
    global.jobExitEventHandle = function () {
        
    }
}