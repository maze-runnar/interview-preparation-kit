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

// Complete the substrCount function below.
function substrCount(n, s) {
      let history = [];
    let historyCount = 0;


    // historyItem = [current, occurrence]
    let historyItem = [s[0], 1];

    let palindromicCount = 0;

    for(let i = 1; i < n; i++ )
        if(s[i] == historyItem[0])
            historyItem[1]++;
        else{
            // Calcuate all strings that can be formed with the same character
            // Count total substrings  -> n * (n + 1) / 2 for
            palindromicCount += historyItem[1] * (historyItem[1] + 1) / 2;


            if(historyCount == 2){
                // Calcuate all strings that can be formed with the same character except middle character
                if(history[0][0] == historyItem[0] && history[1][1] == 1 )
                    palindromicCount += Math.min(history[0][1], historyItem[1])

                history.shift();
                historyCount--;
            }

            history.push(historyItem);
            historyCount++;
            historyItem = [s[i], 1];
        }

    palindromicCount += historyItem[1] * (historyItem[1] + 1) / 2;

    if(historyCount == 2)
        if(history[0][0] == historyItem[0] && history[1][1] == 1 )
                    palindromicCount += Math.min(history[0][1], historyItem[1])


    return palindromicCount;


}

function main() {
    const ws = fs.createWriteStream(process.env.OUTPUT_PATH);

    const n = parseInt(readLine(), 10);

    const s = readLine();

    const result = substrCount(n, s);

    ws.write(result + '\n');

    ws.end();
}
