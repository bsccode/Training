// Take player input
// randomise computer input
// compare the pair
// increment winners total
// print winner and score


let player;
let computer;
let result;


function gamePlay(player, computer, result) {
    player = prompt('Rock, Paper or Scissors? ').toLowerCase();
    console.log('Rock! \n Paper! \n Scissors! \n Shoot! \n');

    if (['rock', 'paper', 'scissors'].indexOf(player) === -1) {
        return "Invalid choice!";
    }

    if (player === 'rock') {
        switch(computer) {
            case 'rock':
              result = 'DRAW!' 
              return result;
            case 'paper':
              result = 'LOSS!'
              return result;
            case 'scissors':
              result = 'WIN!'
              return result;
          };
    } else if (player === 'paper') {
        switch(computer) {
            case 'rock':
              result = 'WIN!' 
              return result;
            case 'paper':
              result = 'DRAW!'
              return result;
            case 'scissors':
              result = 'LOSS!'
              return result;
          }
    } else if (player === 'scissors') {
        switch(computer) {
            case 'rock':
              result = 'LOSS!' 
              return result;
            case 'paper':
              result = 'WIN!'
              return result;
            case 'scissors':
              result = 'DRAW!'
              return result;
        }
    }   
}


console.log(gamePlay)
