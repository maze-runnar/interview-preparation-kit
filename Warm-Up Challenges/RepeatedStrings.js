process.stdin.resume();
process.stdin.setEncoding('ascii');

var input_stdin = "";
var input_stdin_array = "";
var input_currentline = 0;

process.stdin.on('data', function (data) {
    input_stdin += data;
});

process.stdin.on('end', function () {
    input_stdin_array = input_stdin.split("\n");
    main();
});

function readLine() {
    return input_stdin_array[input_currentline++];
}

/////////////// ignore above this line ////////////////////

function main() {
    var s = readLine().split("");
    var n = parseInt(readLine());

    var stringSize = s.length;
    var a = s.filter((a) => a == 'a').length;

    var repeat = Math.floor(n/stringSize);

    var left = n-(repeat*stringSize);



    console.log((repeat*a) + s.filter((a,i) => a == 'a' && i < left).length);

}
