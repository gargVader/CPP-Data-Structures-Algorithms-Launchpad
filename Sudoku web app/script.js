var arr = [[], [], [], [], [], [], [], [], []]
var temp = [[], [], [], [], [], [], [], [], []]

for (var i = 0; i < 9; i++) {
    for (var j = 0; j < 9; j++) {
        arr[i][j] = document.getElementById(i * 9 + j);

    }
}

function initializeTemp(temp) {

    for (var i = 0; i < 9; i++) {
        for (var j = 0; j < 9; j++) {
            temp[i][j] = false;

        }
    }
}


function setTemp(board, temp) {

    for (var i = 0; i < 9; i++) {
        for (var j = 0; j < 9; j++) {
            if (board[i][j] != 0) {
                temp[i][j] = true;
            }

        }
    }
}


function setColor(temp) {

    for (var i = 0; i < 9; i++) {
        for (var j = 0; j < 9; j++) {
            if (temp[i][j] == true) {
                arr[i][j].style.color = "#DC3545";
            }

        }
    }
}

function resetColor() {

    for (var i = 0; i < 9; i++) {
        for (var j = 0; j < 9; j++) {

            arr[i][j].style.color = "green";


        }
    }
}

var board = [[], [], [], [], [], [], [], [], []]


let button = document.getElementById('generate-sudoku')
let solve = document.getElementById('solve')

console.log(arr)
function changeBoard(board) {
    for (var i = 0; i < 9; i++) {
        for (var j = 0; j < 9; j++) {
            if (board[i][j] != 0) {

                arr[i][j].innerText = board[i][j]
            }

            else
                arr[i][j].innerText = ''
        }
    }
}

// Generate new board
button.onclick = function () {
    var xhrRequest = new XMLHttpRequest()
    xhrRequest.onload = function () {
        var response = JSON.parse(xhrRequest.response)
        console.log(response)
        initializeTemp(temp)
        resetColor()

        board = response.board
        setTemp(board, temp)
        setColor(temp)
        changeBoard(board)
    }
    xhrRequest.open('get', 'https://sugoku.herokuapp.com/board?difficulty=easy')
    //we can change the difficulty of the puzzle the allowed values of difficulty are easy, medium, hard and random
    xhrRequest.send()
}

//to be completed by student
function isSafe(board, r, c, num) {

    // Check in row and col
    for(var i=0; i<9; i++){
        if(board[i][c]==num){
            return false;
        }
    }
    for(var i=0; i<9; i++){
        if(board[r][i]==num){
            return false;
        }
    }


    // Check in sub-grid
    var sr = r - r%3;
    var sc = c - c%3;

    for(var i=sr;i<sr+3; i++){
        for(var j = sc;j<sc+3; j++){
            if(board[i][j]==num) return false;
        }
    }

    return true;
}

//to be completed by student
function solveSudokuHelper(board, r, c) {
    // Base Case
    if(r==9){
        changeBoard(board);
        return;
    }

    if(c==9){
        // go to next row
        solveSudokuHelper(board, r+1, 0);
        return;
    }

    // Pre-filled
    if(board[r][c]!=0){
        solveSudokuHelper(board, r, c+1);
        return;
    }

    // Empty cell to be filled
    for(var i=1; i<=9; i++){
        if(isSafe(board, r, c, i)){
            // Assume that if it is safe then it is also correct
            board[r][c] = i
            solveSudokuHelper(board, r, c+1);
            // Backtarcking
            board[r][c] = 0;

        }
        
    }

}

function solveSudoku(board) {
    solveSudokuHelper(board, 0, 0)
}

solve.onclick = function () {
    solveSudoku(board)

}