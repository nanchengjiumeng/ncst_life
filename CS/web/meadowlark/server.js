let express = require('express');
let handlebars = require('express3-handlebars').create({
   defaultLayout:'main',
});


let app = express();
app.engine('handlebars',handlebars.engine);
app.set('view engine','handlebars');
app.use(express.static(__dirname+'/public'));

app.set('port', process.env.PORT||3000);

app.get('/',function (req,res) {
    /*res.type('text/plain');
    res.send('Meadowlark Travel');*/
    res.render('home',{fortun:'666'});
});
app.get('/about', function (req,res) {
    /*res.type('text/plain');
    res.send('About Meadowlark Travel');*/
    res.render('about');
});


// set 404 page
app.use(function (req,res) {
    res.status(404);
    res.render('404');
   /*res.type('text/plain');
   res.send('404-NOT FOUND');*/
});

// set 500 page
app.use(function (err,req,res,next) {
    console.log(err.stack);
    res.status(500);
    res.render('500');
    /*res.type('text/plain');
    res.send('500 - SERVER ERROR');*/
});



app.listen(app.get('port'),function () {
    console.log('express started on port:' + app.get('port'));
});