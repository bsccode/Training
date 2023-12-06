let raceNumber = Math.floor(Math.random() * 1000);

let earlyregister = Math.floor(Math.random() * 100);
let runnerage = Math.floor(Math.random() * 100);

console.log(raceNumber);
console.log(runnerage);
console.log(earlyregister);
if (runnerage >= 18 && earlyregister < 60) {
  raceNumber += 1000; 
} else if (runnerage < 18) {
  raceNumber += 2000;
};

console.log(raceNumber);

if (runnerage >= 18 && earlyregister >= 60) {
  console.log('you will race at 0930 in race ' + raceNumber) 
} else if (runnerage >= 18 && earlyregister < 60 ) {
  console.log('you will race at 1100 in race ' + raceNumber)
} else if (runnerage < 18) {
  console.log('you will race at 1230 in race ' + raceNumber)
};

// Edited variables to make results psuedo random. and added 1000 to child value to make more sense