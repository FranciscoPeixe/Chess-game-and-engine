int validateKnight(char fromColumn, int fromLine, int toLine, char toColumn, char board[8][8])
{
    if(board[8 - fromLine][fromColumn - 1] == 'C' || board[8 - fromLine][fromColumn - 1] == 'c')
    {
        if(toLine == fromLine + 2 && toColumn == fromColumn + 1)//cima direita
        {
            return 0;
        }
        else if(toLine == fromLine + 2 && toColumn == fromColumn - 1)//cima esquerda
        {
            return 0;
        }
        else if(toLine == fromLine + 1 && toColumn == fromColumn + 2)//cima lado direita
        {
            return 0;
        }
        else if(toLine == fromLine + 1 && toColumn == fromColumn - 2)//cima lado esquerda
        {
            return 0;
        }
        else if(toLine == fromLine - 1 && toColumn == fromColumn + 2)//baiio lado direita
        {
            return 0;
        }
        else if(toLine == fromLine - 1 && toColumn == fromColumn - 2)//baiio lado esquerda
        {
            return 0;
        }
        else if(toLine == fromLine - 2 && toColumn == fromColumn + 1)//baiio direita
        {
            return 0;
        }
        else if(toLine == fromLine - 2 && toColumn == fromColumn - 1)
        {
            return 0;
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
