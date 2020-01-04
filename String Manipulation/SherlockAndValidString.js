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

// Complete the isValid function below.
function isValid(s) {

        let counter = {};
    let freq = {};

    // count of occurrences of characters
    // for example aaabbcc => {a: 3, b: 2, c: 2}
    Array.from(s).forEach(char => {
        counter[char] = counter[char] || 0;
        counter[char]++;
    })

    // count the frequency of those occurence counts,
    // for example {a: 3, b: 2, c: 2} => {3: 1, 2: 2}
    Object.keys(counter).forEach(k => {
        freq[counter[k]] = freq[counter[k]] || 0;
        freq[counter[k]]++;
    })

    // all our frequencies. e.g. [3, 2]
    let freqArr = Object.keys(freq).map(Number);

    // Simplest case: if there is only one frequency, it's valid
    if (freqArr.length === 1) {
        return 'YES'
    }

    // If not a single frequency string, check next simplest case

    // there are exactly two frequencies
    // e.g. [3, 2]
    let twoFrequencies = freqArr.length === 2;
    let [a, b] = freqArr;

    // frequency occurs only once
    let oneOccurence = freq[a] === 1 || freq[b] === 1;

    // the difference is a singleton character
    // e.g. abbcc
    let singleton = (freq[a] === 1 && a === 1) || (freq[b] === 1 && b === 1)

    // differing frequency is exactly 1 more than others
    // e.g. true if aaabbcc, false if abbcc
    let diffOfOne = (freq[a] === 1 ? a - b : b - a) === 1;

    // if single character or frequencies differ by one
    // and there are exactly two frequencies
    // and there is only one occurence of the singleton or differing frequency
    if ((singleton || diffOfOne) && twoFrequencies && oneOccurence) {
        return 'YES'
    }

    return 'NO'


}

function main() {
    const ws = fs.createWriteStream(process.env.OUTPUT_PATH);

    const s = readLine();

    let result = isValid(s);

    ws.write(result + "\n");

    ws.end();
}
