"use strict";

Function.prototype.simbind = function(context) {
  if (typeof this !== "function") {
    throw new Error("The caller should be a function.");
  }

  const self = this;
  const args = Array.prototype.slice.call(arguments, 1);
  const fNOP = function() {};
  const fBound = function() {
    const bindArgs = Array.prototype.slice.call(arguments);
    return self.apply(
      this instanceof fNOP ? this : context,
      args.concat(bindArgs)
    );
  };

  fNOP.prototype = this.prototype;
  fBound.prototype = new fNOP();
  return fBound;
};

function bar() {};

const bindFoo = bar.simbind(null);

bindFoo.prototype.value = 1;

console.log(bar.prototype.value) // undefined
