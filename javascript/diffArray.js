function diffArray1 (arr1, arr2) {
  var newArr = []

  function onlyInFirst (first, second) {
    for (var i = 0; i < first.length; i++) {
      if (second.indexOf(first[i]) === -1) {
        newArr.push(first[i])
      }
    }
  }

  onlyInFirst(arr1, arr2)
  onlyInFirst(arr2, arr1)

  return newArr
}

function diffArray2 (arr1, arr2) {
  return arr1
    .concat(arr2)
    .filter(item => !arr1.includes(item) || !arr2.includes(item))
}

function diffArray3 (arr1, arr2) {
  return arr1
    .filter(el => !arr2.includes(el))
    .concat(arr2.filter(el => !arr1.includes(el)))
}

let arr1 = [1, 2, 3]
let arr2 = [2, 3, 4, 5]
console.log(diffArray1(arr1, arr2))
console.log(diffArray2(arr1, arr2))
console.log(diffArray3(arr1, arr2))
