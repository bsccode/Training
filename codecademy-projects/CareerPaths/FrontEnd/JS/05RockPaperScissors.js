/*const getUserChoice = userInput => {
  userInput = userInput.toLowerCase();
  if (userInput === 'rock' || userInput === 'paper' || userInput === 'scissors') {
    return console.log(userInput);
  } else {
    console.log('Input Error');
  };
};*/

function getuserChoice() {
    let humanNumber = Math.floor(Math.random() * 3);
  console.log(humanNumber)
  switch (humanNumber) {
    case 0:
      return 'rock';
      break;
    case 1:
      return 'paper';
      break;
    case 2:
      return 'scissors';
      break;
  };
};


function getcomputerChoice() {
  let randomNumber = Math.floor(Math.random() * 3);
  console.log(randomNumber)
  switch (randomNumber) {
    case 0:
      return 'rock';
      break;
    case 1:
      return 'paper';
      break;
    case 2:
      return 'scissors';
      break;
  };
};

function determineWinner() {
  if (userChoice === 'rock' && computerChoice === 'paper') {
  return 'You Lose'
  } else if (userChoice === 'paper' && computerChoice === 'scissors') {
  return 'You Lose'
  } else if (userChoice === 'scissors' && computerChoice === 'rock') {
  return 'You Lose'
  }else if (userChoice === 'rock' && computerChoice === 'scissors') {
  return 'You Win'
  } else if (userChoice === 'paper' && computerChoice === 'rock') {
  return 'You Win'
  } else if (userChoice === 'scissors' && computerChoice === 'paper') {
  return 'You Win'
  }else if (userChoice === computerChoice) {
  return 'You Draw'
  };
};

console.log('hi');

userChoice = getuserChoice();
computerChoice = getcomputerChoice();
result = determineWinner(userChoice,computerChoice);

console.log('The human chose ' + userChoice);
console.log('The AI chose ' + computerChoice);
console.log('So that means '+ result);


