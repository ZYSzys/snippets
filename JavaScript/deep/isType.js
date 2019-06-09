const isType = type => target => Object.prototype.toString.call(target) === `[object ${type}]`;

const isArray = isType('Array');

console.log(isArray([1]));
