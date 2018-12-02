'use strict';

function Parent() {
  this.name = ['ZYSzys'];
}

Parent.prototype.getName = function () {
  console.log(this.name);
}

function Child() {

}

Child.prototype = new Parent();

const child = new Child();
child.name.push('changed');
console.log(child.getName());

const ch = new Child();
console.log(ch.getName());
