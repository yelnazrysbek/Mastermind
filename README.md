# my_mastermind

*Game description*

Mastermind is a game composed of 8 pieces of different colors.
A secret code is then composed of 4 distinct pieces.

The player has 10 attempts to find the secret code.
After each input, the game indicates to the player the number of well placed pieces and the number of misplaced pieces.

Pieces will be '0' '1' '2' '3' '4' '5' '6' '7'.

If the player finds the code, he wins, and the game stops.
A misplaced piece is a piece that is present in the secret code butthat is not in a good position.


*How to start the game*

1. Write "make" in terminal
2. After additional files are generated, you can write the following in the terminal to start the game with random code and 10 attempts:
>./my_mastermind
3. If you want to write your own code and number of attempts, you can write the following:
>./my_mastermind -t NoOfAttempts -c "codeinquotes"
4. If you want to have randomly generated code, but still want to determine the number of attempts, you can write the following:
./my_mastermind -t NoOfAttempts
5. If else you want to determine the code, but not the number of attempts, you can write:
>./my_mastermind -c "codeinquotes"

*Let's play!*