'use strict';

const fs = require('fs');

process.stdin.resume();
process.stdin.setEncoding('utf-8');

let inputString = '';
let currentLine = 0;

process.stdin.on('data', inputStdin => {
    inputString += inputStdin;
});

process.stdin.on('end', function() {
    inputString = inputString.replace(/\s*$/, '')
        .split('\n')
        .map(str => str.replace(/\s*$/, ''));

    main();
});

function readLine() {
    return inputString[currentLine++];
}

// Complete the makeAnagram function below.
function makeAnagram(a, b) {
      let vector = []

  for(let element of a) {
    let index = element.charCodeAt(0) - 97
    vector[index] = vector[index] || 0
    vector[index] += 1;
  }
  for(let element of b){
    let index = element.charCodeAt(0) - 97
    vector[index] = vector[index] || 0
    vector[index] -=1
  }
  return vector.reduce((a,b) =>
    Math.abs(a) + Math.abs(b))


}

function main() {
    const ws = fs.createWriteStream(process.env.OUTPUT_PATH);

    const a = readLine();

    const b = readLine();

    const res = makeAnagram(a, b);

    ws.write(res + '\n');

    ws.end();
}
