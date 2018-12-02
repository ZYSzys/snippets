const fs = require('fs')
const zlib = require('zlib')

const gzip = zlib.createGzip()

const inFile = fs.createReadStream('./example/example.txt')
const out = fs.createWriteStream('./example/example.txt.gz');

inFile.pipe(gzip).pipe(out)