// @file animals-inherit.js
// Javascript no protected methods
// Animals class
function Animals(name){ 
	this.name=name;
	this.babies=[];
} 

Animals.prototype.addBaby=function(newBaby){ 
	this.babies.push(newBaby);
} 

Animals.prototype.listInfo=function(){ 
	if (this.babies.length == 0) return ;
	console.log("Your pet("+this.name+") has " +  this.babies.length + (this.babies.length >=2 ? " baby":" babies")); 
	for (var i = 0 ; i < this.babies.length; i++) {
		console.log("baby" + i + ": " + this.babies[i]); 
	}
}

Animals.prototype.toString=function(){ 
	return '[Animals "'+this.name+'"]';
} 

// Rabbits
Rabbit.prototype = new Animals();
Rabbit.prototype.constructor = Rabbit;
// add parent to make simple to use super methods
Rabbit.prototype.parent = Animals.prototype;

function Rabbit(name){
	this.name = name
}

Rabbit.prototype.toString=function(){ 
	return '[Rabbit "'+this.name+'"]';
} 

Rabbit.prototype.listInfo=function() {
	console.log('--> '+this.name+' has two long ears.' );
	this.parent.listInfo.call(this);
}

// Dog class 
Dog.prototype = new Animals(); 
Dog.prototype.constructor=Dog;
function Dog(name){ 
	this.name=name;
} 

Dog.prototype.toString=function(){ 
	return '[Dog "'+this.name+'"]';
} 

Dog.prototype.listInfo=function() {
	console.log('--> '+this.name+' has four legs.' );
	// call suppr methods of Animals
	Animals.prototype.listInfo.call(this);
}

// main
var aAnimal = new Animals('Asimo');
var pet = new Dog('Popo');
var rabbit = new Rabbit('Longear');
console.log('Animal is '+aAnimal);
console.log('Your pet is '+pet);      
pet.addBaby(new Dog('Roro')); 
pet.addBaby(new Dog('Puka')); 
pet.listInfo();
rabbit.addBaby(new Rabbit('Cuta'));
rabbit.listInfo();
