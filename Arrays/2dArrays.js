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

// Complete the hourglassSum function below.
function hourglassSum(arr) {

    let max_sum = Number.MIN_SAFE_INTEGER;
    for(let i=0;i<4;i++)
    {
        for(let j=0;j<4;j++)
        {
            let current_sum = 0;
            current_sum+=(arr[i][j]);
            current_sum+=(arr[i][j+1]);
            current_sum+=(arr[i][j+2]);
           
            current_sum+=(arr[i+1][j+1]);
            
            current_sum+=(arr[i+2][j]);
            current_sum+=(arr[i+2][j+1]);
            current_sum+=(arr[i+2][j+2]);
            if(current_sum>max_sum)max_sum = current_sum;
        }
    }

    return max_sum;
}

function main() {
    const ws = fs.createWriteStream(process.env.OUTPUT_PATH);

    let arr = Array(6);

    for (let i = 0; i < 6; i++) {
        arr[i] = readLine().split(' ').map(arrTemp => parseInt(arrTemp, 10));
    }

    let result = hourglassSum(arr);

    ws.write(result + "\n");

    ws.end();
}
