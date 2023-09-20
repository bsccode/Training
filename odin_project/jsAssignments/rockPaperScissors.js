// Take player input
// randomise computer input
// compare the pair
// increment winners total
// print winner and score

let welcomeChoice;
let playerChoice;
let computerChoice;
let playerScore = 0;
let computerScore = 0;
let result;
let repeat;

function welcomeScreen() {
  welcomeChoice = prompt('Welcome to the Rock, Paper, Scissors game! \n Enter 1 to begin or anything else to close the program \n')
  if (welcomeChoice === '1') {
    while (repeat != 'end') {
      console.log(gamePlay())
      console.log('The score is ' + playerScore + ' for the player and ' + computerScore + ' for the computer!')
      repeat = prompt('If you want finish the game please enter "end" in the prompt')
    }
    console.log('The final score is ' + playerScore + ' for the player and ' + computerScore + ' for the computer\n Thank you for Playing!')
  } else {
    return
  }

function getRandomChoice() {
  const choices = ['rock', 'paper', 'scissors'];
  return choices[Math.floor(Math.random() * choices.length)];
}

function gamePlay() {
    playerChoice = prompt('Rock, Paper or Scissors? ').toLowerCase();
    console.log('Rock! \n Paper! \n Scissors! \n Shoot! \n');

    computerChoice = getRandomChoice(); // Randomizing computer's choice

    console.log('Computer got ' + computerChoice + '\n')

    if (['rock', 'paper', 'scissors'].indexOf(playerChoice) === -1) {
        return "Invalid choice!";
    }

    if (playerChoice === 'rock') {
        switch(computerChoice) {
            case 'rock':
              result = 'DRAW!'; 
              return result;
            case 'paper':
              result = 'LOSS!';
              computerScore ++ ;
              return result;
            case 'scissors':
              result = 'WIN!'
              playerScore ++;
              return result;
          };
    } else if (playerChoice === 'paper') {
        switch(computerChoice) {
            case 'rock':
              result = 'WIN!'
              playerScore ++; 
              return result;
            case 'paper':
              result = 'DRAW!'
              return result;
            case 'scissors':
              result = 'LOSS!';
              computerScore ++ ;
              return result;
          }
    } else if (playerChoice === 'scissors') {
        switch(computerChoice) {
            case 'rock':
              result = 'LOSS!'; 
              computerScore ++ ;
              return result;
            case 'paper':
              result = 'WIN!'
              playerScore ++;
              return result;
            case 'scissors':
              result = 'DRAW!'
              return result;
        }
    }   
}
}

welcomeScreen()