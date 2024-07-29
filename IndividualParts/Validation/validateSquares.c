int validatesquares(char fromColumn, int fromLine, int toLine, char toColumn, char board[8][8])
{
    if(fromLine == toLine && fromColumn == toColumn)
    {
        return 1;
    }
    else if(board[8-fromLine][fromColumn-1] == ' ')
    {
        return 1;
    }
    else
    {
        return 0;
    }
}
