function processData(input) {
    //Enter your code here
  var pInput = input.split('\n');
  var n = pInput[0];
  var pInput = pInput[1].split(' ');
  var oddItems = {};
  pInput.map(function (i) {
    if(oddItems[i]) {
      delete oddItems[i];
    } else {
      oddItems[i] = true;
    }
  })
  console.log((n - Object.keys(oddItems).length)/2);
}

process.stdin.resume();
process.stdin.setEncoding("ascii");
_input = "";
process.stdin.on("data", function (input) {
    _input += input;
});

process.stdin.on("end", function () {
   processData(_input);
});