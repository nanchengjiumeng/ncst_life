let { main }  = require('./job/JobSch');

/*
*
* params:
*   job number,
*   cpu type ->  fcfs || sjf || hrn
*
* */
main(10,'hrn');