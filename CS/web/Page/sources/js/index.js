
//let mainFrameHeight = document.body.clientHeight - document.querySelector("header").clientHeight;
//document.querySelector(".main-frame").style.height = mainFrameHeight+'px';
if(document.body.clientWidth<=960){
    document.querySelector(".side").style.display="none";
}else{
    document.querySelector(".side").style.display="flex";
}

window.onresize = function(){
    //let mainFrameHeight = document.body.clientHeight - document.querySelector("header").clientHeight;
   // document.querySelector(".main-frame").style.height = mainFrameHeight+'px';


    // side边框的是否够出现
    if(document.body.clientWidth<=960){
        document.querySelector(".side").style.display="none";
    }else{
        document.querySelector(".side").style.display="flex";
    }
    w = element.style.width.slice(0,-2);
};



let items =  document.querySelectorAll(".item");
for (let i = 0; i<items.length; ++i){
    items[i].onclick = function (e) {
        if(items[i].childNodes[3].nodeName.toUpperCase()!=="UL"){return;}
        if(items[i].childNodes[3].style.display==="block"){
            items[i].childNodes[3].style.display="none";
        }else{
            items[i].childNodes[3].style.display="block";
            for (let n = 0; n<items.length; n++){
                if(n!==i){
                    items[n].childNodes[3].style.display="none";
                }
            }
        }

    }
}



let start = null;
let element = document.querySelector('.left-frame');
element.style.flexGrow="1";
element.style.width = element.clientWidth+'px';
let w = element.style.width.slice(0,-2);
let open = document.querySelector('#open');
let close = document.querySelector('#close');

function closeStep(timestamp) {
    if (!start) start = timestamp;
    var progress = timestamp - start;
    console.log(element.style.width);
    element.style.width = w*((200-progress)/200)+'px' ;
    if (progress < 200) {
        window.requestAnimationFrame(closeStep);

    }else{
        element.style.display = "none";
        close.style.display="none";
        open.style.display="flex";
        start=null;
    }
}
function openStep(timestamp) {

    if (!start) start = timestamp;
    var progress = timestamp - start;
    console.log(element.style.width,progress);
    element.style.width = w*((progress)/200)+'px' ;
    if (progress < 200) {
        window.requestAnimationFrame(openStep);
    }else {
        close.style.display="flex";
        open.style.display="none";
        start=null;

    }
}

close.onclick=function (e) {
    window.requestAnimationFrame(closeStep);
};
open.onclick=function (e) {
    element.style.display = "flex";
    window.requestAnimationFrame(openStep);
};


