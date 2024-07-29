int validateEndOfGame(int toLine, int toColumn, char board[8][8])
{  
    if(toupper(board[8-toLine][toColumn-1]) == 'R')
    {
        if(moves % 2 == 1)
        {
            return 1;
        }
        else
        {
            return 2;
        }
    }
    else
    {
        return 0;
    }
}
