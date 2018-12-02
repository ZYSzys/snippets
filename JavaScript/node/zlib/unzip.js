const fs = require('fs')
const zlib = require('zlib')

const gunzip = zlib.createGunzip()

const inFile = fs.createReadStream('./example/example.txt.gz')
const out = fs.createWriteStream('./example/unzipexample.txt');

inFile.pipe(gunzip).pipe(out)