int validatePlayer(char board[8][8], int fromLine, int fromColumn)
{
    if((moves % 2 == 0 && board[8-fromLine][fromColumn-1] == toupper(board[8-fromLine][fromColumn-1])) || 
    (moves % 2 == 1 && board[8-fromLine][fromColumn-1] != toupper(board[8-fromLine][fromColumn-1])))
    {
        return 0;
    }
    else
    {
        return 1;
    }
}
