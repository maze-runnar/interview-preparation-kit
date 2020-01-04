'use strict';

const fs = require('fs');

process.stdin.resume();
process.stdin.setEncoding('utf-8');

let inputString = '';
let currentLine = 0;

process.stdin.on('data', function(inputStdin) {
    inputString += inputStdin;
});

process.stdin.on('end', function() {
    inputString = inputString.split('\n');

    main();
});

function readLine() {
    return inputString[currentLine++];
}

// Complete the freqQuery function below.
function freqQuery(queries) {
    let result = [];
let freq = [];
let map = {};

for (let i = 0; i < queries.length; i++) {
    const [op, x] = queries[i];
    const f = map[x] || 0;

    if (op === 1) {
        map[x] = f + 1;
        freq[f] = (freq[f] || 0) - 1;
        freq[f + 1] = (freq[f + 1] || 0) + 1;
    }
    if (op === 2) {
        if (map[x] > 0) {
            map[x] = f - 1;
            freq[f - 1] += 1;
            freq[f] -= 1;
        }
    }
    if (op === 3) {
        result.push(freq[x] > 0 ? 1 : 0);
    }
}
return result;


}

function main() {
    const ws = fs.createWriteStream(process.env.OUTPUT_PATH);

    const q = parseInt(readLine().trim(), 10);

    let queries = Array(q);

    for (let i = 0; i < q; i++) {
        queries[i] = readLine().replace(/\s+$/g, '').split(' ').map(queriesTemp => parseInt(queriesTemp, 10));
    }

    const ans = freqQuery(queries);

    ws.write(ans.join('\n') + '\n');

    ws.end();
}
