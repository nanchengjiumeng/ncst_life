let mysql      = require('mysql2');
let connection = mysql.createConnection({
    host     : 'localhost',
    user     : 'root',
    database : 'wxinfo',
    password:''
});

connection.connect();

/*{
    opts.command,
    opts.callback(){}
}*/
function executeSQL(opts){

    connection.execute(
        opts.command,
        ['Rick C-137', 53],
        function(err, results, fields) {
            if(opts.callback){
                opts.callback(err, results, fields);
            }

        }
    );
}

module.exports={ connection,executeSQL };