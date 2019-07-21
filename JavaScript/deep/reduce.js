Array.prototype._reduce = function _reduce() {
  const ary = this
  const { length } = ary
  if (arguments.length === 0) {
    throw new TypeError('undefined is not a function')
  }
  if (typeof arguments[0] !== 'function') {
    throw new TypeError(arguments[0] + 'is not a function')
  }
  if (ary.length === 0 && arguments.length === 1) {
    throw new TypeError('Reduce of empty array with no initial value')
  }
  const callback = arguments[0]
  const startIndex = arguments.length >= 2 ? 0 : 1
  let value = startIndex === 0 ? arguments[1] : ary[0]
  for (let i = startIndex; i < length; i++) {
     value = callback(value, ary[i], i, ary)
  }
  return value
}

console.log([1,3,4].reduce((a, b) => a * b, 1));
console.log([1,3,4]._reduce((a, b) => a * b, 1));
