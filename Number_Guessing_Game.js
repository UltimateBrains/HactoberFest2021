// AUTHOR: Gyandeep Mehra
// GITHUB: https://github.com/theGDM

//Hello everyone this is theGDM, here i am going to show you how you can make a simple number
//guessing game using Javascript, it will also tell you the no of attempts you took in making
//the correct guess, Hope you will like it.


let num = parseInt(prompt("Enter the maximum number upto which you want to generate a random number!!"));
while (!num) {
    num = parseInt(prompt("Enter the valid maximum number!!"));
}
let randomNumber = Math.floor((Math.random() * num)) + 1;
let guess = prompt(`Enter your first guess between [1-${num}]`);

let count = 1;
while (parseInt(guess) !== randomNumber) {
    count++;
    if (guess === "quit" || guess === "Quit") {
        break;
    }
    if (guess > randomNumber) {
        guess = prompt("Your guess is too HIGH!!\nEnter your guess again:");
    } else {
        guess = prompt("Your guess is too LOW!!\nEnter your guess again:");
    }
}
if (guess === "quit" || guess === "Quit") {
    console.log("Ok!!\nYou gave up!!!!");
} else {
    console.log(`Congrats!!!\nYou WONNNNNNNN!!`);
    if (count > 1) {
        console.log(`Total No.of attempts taken to match your guess with randomly generated number are ${count}`);
    } else {
        console.log(`Wow,you just took ${count} attempt to match your guess with randomly generated number`);
    }
    console.log(`randomNumber:${randomNumber}`);
    console.log(`guess:${guess}`);
}