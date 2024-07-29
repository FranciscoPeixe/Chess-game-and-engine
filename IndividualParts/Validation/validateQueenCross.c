int validateQueenCross(char fromColumn, int fromLine, int toLine, char toColumn, char board[8][8])
{
    if(toupper(board[8 - fromLine][fromColumn - 1]) == 'D')
    {
        if(fromColumn == toColumn || fromLine == toLine)
        {
            int fromLineMatriz = 8 - fromLine;
            if(fromLine == toLine)
            {
                if(toColumn > fromColumn)
                {
                    for(int i = 0; i < toColumn - fromColumn - 1; i++)
                    {
                        if(board[fromLineMatriz][fromColumn + i] != ' ')
                        {
                            return 1;
                            break;
                        }
                    }
                }
                else
                {
                    for(int i = 0; i < fromColumn - toColumn - 1; i++)
                    {
                        if(board[fromLineMatriz][fromColumn - i - 2] != ' ')
                        {
                            return 1;
                            break;
                        }
                    }
                    
                }
            }
            else
            {
                if(toLine > fromLine)
                {
                    for(int i = 0; i <  toLine - fromLine - 1; i++)
                    {
                        if(board[fromLineMatriz - i - 1][fromColumn - 1] != ' ')
                        {
                            return 1;
                            break;
                        }
                    }
                }
                else
                {
                    for(int i = 0; i < fromLine - toLine - 1; i++)
                    {
                        if(board[fromLineMatriz + i + 1][fromColumn - 1] != ' ')
                        {
                            return 1;
                            break;
                        }
                    }
                    
                }
            }
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
    return 0;
}
