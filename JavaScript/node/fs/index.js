const fs = require('fs');
const path = require('path');

const dirname = path.resolve(__dirname, '..');
console.log(dirname)

fs.readdir(dirname, (err, dir) => {
  dir.forEach(name => {
    console.log(name);
  });
});

console.log('........');
