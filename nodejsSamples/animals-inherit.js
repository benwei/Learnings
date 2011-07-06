// @file animals-inherit.js
// Animals class
function Animals(name){ 
	this.name=name;
	this.babies=[];
} 

Animals.prototype.addBaby=function(newBaby){ 
	this.babies.push(newBaby);
} 

Animals.prototype.listInfo=function(){ 
	console.log("Your pet has " +  pet.babies.length + (pet.babies.length >=2 ? " baby":" babies")); 
	for (var i = 0 ; i < pet.babies.length; i++) {
		console.log("baby" + i + ": " + pet.babies[i]); 
	}
}

Animals.prototype.toString=function(){ 
	return '[Animals "'+this.name+'"]';
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

// main
var aAnimal = new Animals('Asimo');
var pet = new Dog('Popo');
console.log('Animal is '+aAnimal);
console.log('Your pet is '+pet);      
pet.addBaby(new Dog('Roro')); 
pet.addBaby(new Dog('Puka')); 
pet.listInfo();
