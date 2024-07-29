int validateRook(char fromColumn, int fromLine, int toLine, char toColumn, char board[8][8])
{
    if(toupper(board[8 - fromLine][fromColumn - 1]) == 'T')
    {
        if(fromColumn == toColumn || fromLine == toLine)
        {
            int fromLineMatriz = 8 - fromLine;
            if(fromLine == toLine)//horizontal
            {
                if(toColumn > fromColumn)//para a direita
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
                else//vai para a esquerda
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
            else//vertical
            {
                if(toLine > fromLine)//para a cima
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
                else//vai para a baiio
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
