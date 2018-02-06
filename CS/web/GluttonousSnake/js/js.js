function a() {

    const area_division = 60;
    const area_width=600;
    const area_height=600;
    const area_id='game_area';
    let game_area=new Array(area_division);
    for(let i=0;i<area_division;i++){
        game_area[i]=new Array(area_division);
    }

    let food;
    food=generate_food_to_area(area_id);


    //向id为area_id的container中生成food
    function generate_food_to_area(area_id) {
        let game_area_dom = document.getElementById(area_id);
        let food_position=random_food_location(area_division);
        let food=generate_food(food_position,area_width,area_height,area_division);
        game_area_dom.appendChild(food);
        return {
            area:game_area_dom,
            position:food_position,
            dom:food
        };
    }
    //取消id为area中的food
    function remove_food_from_area(area,food) {
        area.removeChild(food);
    }
    //生成一个food的div,返回一个food类名的DivELement
    function generate_food(position,area_width,area_height,area_division) {
        let food = document.createElement('div');
        food.className='food';
        console.log(position );
        food.style.left=position.x*(area_width/area_division)+'px';
        food.style.top=position.y*(area_height/area_division)+'px';
        return food;
    }
    //随机生成一个事物的坐标{x,y}.
    function random_food_location(division) {
        return {
            x:random_digit(0,division-1),
            y:random_digit(0,division-1)
        }
    }

    //生成一个min-max之间（包括min和max）的随机数
    function random_digit(min,max) {
        return Math.floor(Math.random()*(max-min+1)+min)
    }

    return {
        remove_food_from_area:function () {
            remove_food_from_area(food.area,food.dom);
        },
    }
}
let abc=a();




