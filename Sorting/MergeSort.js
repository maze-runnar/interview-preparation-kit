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

// Complete the countInversions function below.
function mergeSort(arr) {

    if(arr.length == 1)
        return [arr, 0];

    let half = Math.floor(arr.length / 2);

    let [leftHalf, leftswap] = mergeSort(arr.slice(0,half));
    let [rightHalf, rightswap] = mergeSort(arr.slice(half));

    let leftPointer = 0;
    let rightPointer = 0;
    let swap = leftswap + rightswap;

    let sorted = [];

    while(leftPointer < leftHalf.length || rightPointer < rightHalf.length){
        if(leftPointer != leftHalf.length && rightPointer != rightHalf.length){
            if(leftHalf[leftPointer] <= rightHalf[rightPointer]){
                sorted.push(leftHalf[leftPointer++]);
            }else if(leftHalf[leftPointer] > rightHalf[rightPointer]){
                swap += leftHalf.length - leftPointer;
                sorted.push(rightHalf[rightPointer++]);
            }
        }else if (leftPointer == leftHalf.length){
            sorted.push(rightHalf[rightPointer++]);
        }else{
            sorted.push(leftHalf[leftPointer++]);
        }
    }

    return [sorted, swap];

}

function countInversions(arr) {

   let [_, totalInversions] = mergeSort(arr);

   return totalInversions;

}
function main() {
    const ws = fs.createWriteStream(process.env.OUTPUT_PATH);

    const t = parseInt(readLine(), 10);

    for (let tItr = 0; tItr < t; tItr++) {
        const n = parseInt(readLine(), 10);

        const arr = readLine().split(' ').map(arrTemp => parseInt(arrTemp, 10));

        const result = countInversions(arr);

        ws.write(result + '\n');
    }

    ws.end();
}
