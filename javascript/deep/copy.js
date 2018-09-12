const obj = {
  name: 'ZYSzys'
}

const ref = {
  age: 100,
  sex: 'man'
}
obj.detail = ref

const shallow = Object.assign({}, obj)
console.log(shallow)

const deep = JSON.parse(JSON.stringify(obj))
console.log(deep)

ref.age = 20

console.log(`Shallow copy: `, shallow)
console.log(`Deep copy: `, deep)