
//----------Hoisting in js-----------
//calling a  function and using a variable before declareing it is called hoisting
let x=7;
 
function getname(){
	console.log("namste javastript");
}
getname();
console.log(x);
console.log(getname)

var getnaam=()=>{
	console.log("ram ram sareya ne ")
}

var setname=function(){
	console.log ('another way to initialize function')
}
getnaam();
setname();
