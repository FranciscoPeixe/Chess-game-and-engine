int validateQueenDiagonals(char fromColumn, int fromLine, int toLine, char toColumn, char board[8][8])
{
    if(toupper(board[8 - fromLine][fromColumn - 1]) == 'D')
    {
        if(abs(toColumn - fromColumn) == abs(toLine - fromLine))
        {
            int fromLineMatriz = 8 - fromLine;
            int toLineMatriz = 8 - toLine;
            if(toLineMatriz < fromLineMatriz)
            {
                if(toColumn > fromColumn)
                {
                    for(int i = 0; i < toLine - fromLine - 1; i++)
                    {
                        if(board[fromLineMatriz - i - 1][fromColumn + i] != ' ')
                        {
                            return 2;
                            break;
                        }
                    }
                }
                else
                {
                    for(int i = 0; i < toLine - fromLine - 1; i++)
                    {
                        if(board[fromLineMatriz - i - 1][fromColumn - i - 2] != ' ')
                        {
                            return 2;
                            break;
                        }
                    }
                    
                }
            }
            else
            {
                if(toColumn > fromColumn)
                {
                    for(int i = 0; i < fromLine - toLine - 1; i++)
                    {
                        if(board[fromLineMatriz + i + 1][fromColumn + i] != ' ')
                        {
                            return 2;
                            break;
                        }
                    }
                }
                else
                {
                    for(int i = 0; i < fromLine - toLine - 1; i++)
                    {
                        if(board[fromLineMatriz + i + 1][fromColumn - i - 2] != ' ')
                        {
                            return 2;
                            break;
                        }
                    }
                    
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
    return 0;
}
