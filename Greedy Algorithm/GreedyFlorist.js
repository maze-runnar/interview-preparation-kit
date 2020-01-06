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

// Complete the getMinimumCost function below.
function getMinimumCost(k, c) {
 // Create a 2D array holding purchase order for each friend
    let purchases = new Array(k).fill(0).map(x => [])

    // Sort flowers from most expensive to cheapest
    c.sort((a,b) => b-a)

    // Distribute purchases evenly between friends
    for (let i = 0, l = c.length; i < l; i++) purchases[i%k].push(c[i])

    // Calculate and return sum of all purchases
    return purchases.reduce( (total_cost, friend_total) => {
        return total_cost + friend_total.reduce( (total, cost, i) => {
            return total + (i + 1) * cost
        }, 0)
    }, 0)

}

function main() {
    const ws = fs.createWriteStream(process.env.OUTPUT_PATH);

    const nk = readLine().split(' ');

    const n = parseInt(nk[0], 10);

    const k = parseInt(nk[1], 10);

    const c = readLine().split(' ').map(cTemp => parseInt(cTemp, 10));

    const minimumCost = getMinimumCost(k, c);

    ws.write(minimumCost + '\n');

    ws.end();
}
