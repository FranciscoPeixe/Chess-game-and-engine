int validateCannibalism(char fromColumn, int fromLine, int toLine, char toColumn, char board[8][8])
{
    if(board[8 - toLine][toColumn - 1] != ' ')
    {
        if(board[8 - fromLine][fromColumn - 1] != ' ')
        {
            if(toupper(board[8 - fromLine][fromColumn - 1]) == board[8 - fromLine][fromColumn - 1])//peca branca
            {
                if(toupper(board[8 - toLine][toColumn - 1]) == board[8 - toLine][toColumn - 1])//a board de destino tambem e uma board com peca branca
                {
                    return 1;
                }
                else
                {
                    return 0;
                }
            }
            else//peca preta
            {
                if(toupper(board[8 - toLine][toColumn - 1]) != board[8 - toLine][toColumn - 1])//a board de destino tambem e uma board com peca preta
                {
                    return 1;
                }
                else
                {
                    return 0;
                }
            }
        }
        else
        {
            return 1;
        }
    }
    else
    {
        return 0;
    }
}
