'use strict';

const fs = require('fs');

process.stdin.resume();
process.stdin.setEncoding('utf-8');

let inputString = '';
let currentLine = 0;

process.stdin.on('data', inputStdin => {
    inputString += inputStdin;
});

process.stdin.on('end', _ => {
    inputString = inputString.replace(/\s*$/, '')
        .split('\n')
        .map(str => str.replace(/\s*$/, ''));

    main();
});

function readLine() {
    return inputString[currentLine++];
}

// Complete the arrayManipulation function below.
function arrayManipulation(n, queries) {

let arr = [];
let max = 0;
for (let l = 0; l < n; l++) {
arr[l] = 0;
}
for (let i = 0; i < queries.length; i++) {
arr[queries[i][0]-1] += queries[i][2];
if (queries[i][1] < arr.length) {
arr[queries[i][1]] -= queries[i][2];
}
}
for (let j = 1; j < n; j++) {
arr[j] += arr[j-1];
}
for (let k = 0; k < arr.length; k++) {
max = Math.max(max, arr[k]);
}
return max;
}


function main() {
    const ws = fs.createWriteStream(process.env.OUTPUT_PATH);

    const nm = readLine().split(' ');

    const n = parseInt(nm[0], 10);

    const m = parseInt(nm[1], 10);

    let queries = Array(m);

    for (let i = 0; i < m; i++) {
        queries[i] = readLine().split(' ').map(queriesTemp => parseInt(queriesTemp, 10));
    }

    let result = arrayManipulation(n, queries);

    ws.write(result + "\n");

    ws.end();
}
